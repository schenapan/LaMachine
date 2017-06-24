
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
  &item_2,
  &item_1
};
#define ITEM_SEQ_A_SIZE (sizeof(items_seq_A)/sizeof(sItem*))

const sResult result_seq_A = {
  1,
  1
};
 
const sSequence seq_A[] = {
   ITEM_SEQ_A_SIZE,
  &items_seq_A,
  &result_seq_A,
};

/**
 * Sequence B
 */

const sItem *items_seq_B[] = {
  &item_2,
  &item_1,
  &item_2
};
#define ITEM_SEQ_B_SIZE (sizeof(items_seq_B)/sizeof(sItem*))

const sResult result_seq_B = {
  2,
  2
};

const sSequence seq_B[] = {
   ITEM_SEQ_B_SIZE,
  &items_seq_B,
  &result_seq_B,
};
 
/**
 * Full set of directory 0
 */
 
const sDirSequence seq_dir_0 = {
  2,
  {&seq_A,&seq_B}
};


/**
 * Directory 1
 */

/**
 * Sequence 1_A
 */

const sResult result_seq_1_A = {
  END_OF_SEQUENCE_RESTART_ID,
  1
};
 
const sSequence seq_1_A[] = {
   ITEM_SEQ_A_SIZE,
  &items_seq_A,
  &result_seq_1_A,
};

/**
 * Sequence 1_B
 */

const sResult result_seq_1_B = {
  END_OF_SEQUENCE_RESTART_ID,
  2
};

const sSequence seq_1_B[] = {
   ITEM_SEQ_B_SIZE,
  &items_seq_B,
  &result_seq_1_B,
};
 
/**
 * Full set of directory 1
 */
 
const sDirSequence seq_dir_1 = {
  2,
  {&seq_1_A,&seq_1_B}
};

/**
 * Table of sequences by directory
 */
const sDirSequence *seq_dir[NB_DIRECTORY] = {
  &seq_dir_0,
  &seq_dir_1,
};








