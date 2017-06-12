
#include "config_sequence.h"

/******************************************************
* define card uid
*/
const unsigned char uid_1_data[][UUID_TAG_SIZE] = {
  {0x0C, 0x07, 0x8D, 0xAB}
};
const sItem item_1 = {1,uid_1_data};

const unsigned char uid_2_data[][UUID_TAG_SIZE] = {
  {0x60, 0xE8, 0x21, 0x83}
};
const sItem item_2 = {1,uid_2_data};

/**
 * export table of items, simplify other process
 */
const sItemTbl items_table = {
  2,
  { &item_1, &item_2 }
};


/**
 * Directory 0
 */

/**
 * Sequence A
 */

const sItem *items_seq_A[] = {
  &item_1,
  &item_2
};
#define ITEM_SEQ_A_SIZE (sizeof(items_seq_A)/sizeof(sItem*))

const sResult result_seq_A = {
  END_OF_SEQUENCE_DISABLE_DIR_ID,
  0
};
 
const sSequence seq_A[] = {
   ITEM_SEQ_A_SIZE,
  &items_seq_A,
  &result_seq_A,
};
 
/**
 * Full set of directory 0
 */
 
const sDirSequence seq_dir_0 = {
  1,
  {&seq_A}
};

/**
 * Table of sequences by directory
 */
const sDirSequence *seq_dir[NB_DIRECTORY] = {
  &seq_dir_0
};








