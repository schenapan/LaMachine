#ifndef CONFIG_SEQUENCE_H
#define CONFIG_SEQUENCE_H

#include "custom_typedef.h"
#include "config_items.h"

/**
 * export table of sequence, indice of table is same as directory
 */
extern const sDirSequence * const seq_dir[NB_DIRECTORY] PROGMEM;

/**
 * export table of items, simplify other process
 */
extern const sItemTbl items_table PROGMEM;

#endif // CONFIG_SEQUENCE_H
