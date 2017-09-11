#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "engine.hpp"

CEngine::CEngine(unsigned short i_flash_ptr_seq, const sItemTbl *ip_items_table) {
	flash_ptr_seq = i_flash_ptr_seq;
	p_items_tbl = ip_items_table;
}

void CEngine::SetDirectorySequence(unsigned short i_flash_ptr_seq) {
	flash_ptr_seq = i_flash_ptr_seq;
}

sItem *CEngine::GetItem(unsigned char i_uid[UUID_TAG_SIZE]) {
	sItem *op_item = NULL;

	// parcours par item
	unsigned char nb_items = pgm_read_byte(p_items_tbl + offsetof(sItemTbl, nb_items));
	for (unsigned char item_loop = 0; item_loop < nb_items; item_loop++) {
		unsigned short p_item = pgm_read_ptr(&p_items_tbl->p_items[item_loop]);
		unsigned char nb_uid = pgm_read_byte(p_item + offsetof(sItem, nb_uid));
		for (unsigned char uuid_loop = 0; uuid_loop < nb_uid; uuid_loop++) {
			unsigned short p_tag = pgm_read_ptr( p_item + offsetof(sItem, p_uid));
			if (0 == memcmp_PF(i_uid, p_tag + (UUID_TAG_SIZE * uuid_loop), UUID_TAG_SIZE)) {
				op_item = (sItem *) p_item;
				uuid_loop = nb_uid;
				item_loop = nb_items;
			}
		}
	}

	return op_item;
}

bool CEngine::IsSequenceValid(sSeq *p_in_seq, sSequence **op_seq_result) {
	bool o_valid = false;
	*op_seq_result = NULL;

	// parcours par séquence
  unsigned char l_nb_sequence = pgm_read_byte(flash_ptr_seq + offsetof(sDirSequence, nb_seq));
	for (unsigned char seq_loop = 0; seq_loop < l_nb_sequence; seq_loop++) 
	{
		// regarde pour chaque item de la séquence entrante si elle correspond
		for (unsigned char item_loop = 0; item_loop < p_in_seq->nb; item_loop++) 
		{
			// si l'item ne correspond pas, on sort de cette séquence
      unsigned short lp_seq = pgm_read_ptr(&(((sDirSequence*)flash_ptr_seq)->p_seq[seq_loop]));
			unsigned short p_item = pgm_read_ptr(&((sSequence*)lp_seq)->p_items[item_loop]);
			if (p_item == p_in_seq->p_item[item_loop]) 
			{
				// si il s'agit du dernier item de la séquence, on a trouver un résultat
				if (item_loop == p_in_seq->nb - 1) 
				{
          unsigned char l_nb_item = pgm_read_byte(&(((sSequence*)lp_seq)->nb_item));
          
					// valide la séquence
					o_valid = true;

					if (item_loop == l_nb_item - 1) {
						*op_seq_result = (sSequence*)lp_seq;
						seq_loop = l_nb_sequence;
						item_loop = p_in_seq->nb;
					}
				}
			} 
			else 
			{
				// pas de coresspondance, on doit passer a la séquence suivante
				item_loop = p_in_seq->nb;
			}
		}
	}
	return o_valid;
}

