#ifndef CONFIG_SEQUENCE_H
#define CONFIG_SEQUENCE_H

#include "custom_typedef.h"
#include "config_items.h"

/**
 * export table of sequence, indice of table is same as directory
 */
#define NB_DIRECTORY  3
extern const sDirSequence *seq_dir[NB_DIRECTORY];

/**
 * export table of items, simplify other process
 */
extern const sItemTbl items_table PROGMEM;

#endif // CONFIG_SEQUENCE_H
