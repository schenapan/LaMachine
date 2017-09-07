#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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
	unsigned char nb_items = pgm_read_byte(p_items_tbl + offsetof(sItemTbl, nb_items));
	for (unsigned char item_loop = 0; item_loop < nb_items; item_loop++) {
		// pour chaque item regarde les uid associé
		//unsigned short p_item = pgm_read_ptr(p_items_tbl + offsetof(sItemTbl, p_items) + (sizeof(sItem*)*item_loop));
		unsigned short p_item = pgm_read_ptr(&p_items_tbl->p_items[item_loop]);
		unsigned char nb_uid = pgm_read_byte(p_item + offsetof(sItem, nb_uid));
		for (unsigned char uuid_loop = 0; uuid_loop < nb_uid; uuid_loop++) {
			unsigned short p_tag = pgm_read_ptr( p_item + offsetof(sItem, p_uid));
			//if (0 == memcmp(p_items_tbl->p_items[item_loop]->p_uid[uuid_loop], i_uid, UUID_TAG_SIZE))
			if (0 == memcmp_PF(i_uid, p_tag + (UUID_TAG_SIZE * uuid_loop), UUID_TAG_SIZE)) {
				op_item = (sItem *) p_item; //p_items_tbl->p_items[item_loop];
				uuid_loop = nb_uid; //p_items_tbl->p_items[item_loop]->nb_uid;
				item_loop = nb_items; //p_items_tbl->nb_items;
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
		for (unsigned char item_loop = 0; item_loop < p_in_seq->nb;
				item_loop++) {
			// si l'item ne correspond pas, on sort de cette séquence
			unsigned short p_item = pgm_read_ptr(&p_seq->p_seq[seq_loop]->p_items[item_loop]);
			if (p_item == p_in_seq->p_item[item_loop]) {
				// si il s'agit du dernier item de la séquence, on a trouver un résultat
				if (item_loop == p_in_seq->nb - 1) {
					// valide la séquence
					o_valid = true;

					if (item_loop == p_seq->p_seq[seq_loop]->nb_item - 1) {
						// si la sequence est en lock on ne renvoi pas de résultat -en fait si, le test sera fait plus loin
						// if( 0 == p_seq->p_seq[seq_loop]->p_result->lock_timer_counter )
						*op_seq_result = p_seq->p_seq[seq_loop]->p_result;
						seq_loop = p_seq->nb_seq;
						item_loop = p_in_seq->nb;
						// on positionne le nouveau temps de lock
						// p_seq->p_seq[seq_loop]->p_result->lock_timer_counter = p_seq->p_seq[seq_loop]->p_result->lock_timer_reload_value;
					}
				}
			} else {
				// pas de coresspondance, on doit passer a la séquence suivante
				item_loop = p_in_seq->nb;
			}
		}
	}
	return o_valid;
}

