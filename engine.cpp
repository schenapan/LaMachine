#include <stdlib.h>
#include <string.h>

#include "engine.hpp"


CEngine::CEngine(const sDirSequence *ip_seq, const sItemTbl *ip_items_table) {
    p_seq = ip_seq;
    p_items_tbl = ip_items_table;
}

void CEngine::SetDirectorySequence(const sDirSequence *ip_seq) {
    p_seq = ip_seq;
}

sItem *CEngine::GetItem(unsigned char i_uid[UUID_TAG_SIZE]) {
    sItem *op_item = NULL;

    // parcours par item
    for (unsigned char item_loop = 0; item_loop < p_items_tbl->nb_items; item_loop++) {
        // pour chaque item regarde les uid associé
        for (unsigned char uuid_loop = 0; uuid_loop < p_items_tbl->p_items[item_loop]->nb_uid; uuid_loop++) {
            if (0 == memcmp(p_items_tbl->p_items[item_loop]->p_uid[uuid_loop], i_uid, UUID_TAG_SIZE)) {
                op_item = p_items_tbl->p_items[item_loop];
                uuid_loop = p_items_tbl->p_items[item_loop]->nb_uid;
                item_loop = p_items_tbl->nb_items;
            }
        }
    }

    return op_item;
}

bool CEngine::IsSequenceValid(sSeq *p_in_seq, sResult **op_seq_result) {
    bool o_valid = false;
    *op_seq_result = NULL;

    // parcours par séquence
    for (unsigned char seq_loop = 0; seq_loop < p_seq->nb_seq; seq_loop++) {
        // regarde pour chaque item de la séquence entrante si elle correspond
        for (unsigned char item_loop = 0; item_loop < p_in_seq->nb; item_loop++) {
            // si l'item ne correspond pas, on sort de cette séquence
            if (p_seq->p_seq[seq_loop]->p_items[item_loop] == p_in_seq->p_item[item_loop]) {
                // si il s'agit du dernier item de la séquence, on a trouver un résultat
                if ((item_loop == (p_seq->p_seq[seq_loop]->nb_item - 1)) &&
                    (item_loop == (p_in_seq->nb - 1))
                        ) {
                    // si la sequence est en lock on ne renvoi pas de résultat
                    if( 0 != p_seq->p_seq[seq_loop]->p_result->lock_timer_counter )
                    {
                      *op_seq_result = p_seq->p_seq[seq_loop]->p_result;
                      // on positionne le nouveau temps de lock
                      p_seq->p_seq[seq_loop]->p_result->lock_timer_counter = p_seq->p_seq[seq_loop]->p_result->lock_timer_reload_value;
                    }
                    seq_loop = p_seq->nb_seq;
                }

                // valide la séquence
                o_valid = true;
            } else {
                // pas de coresspondance, on doit passer a la séquence suivante
                item_loop = p_in_seq->nb;
            }
        }
    }


    return o_valid;
}

