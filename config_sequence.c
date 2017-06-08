
#include "config_sequence.h"

/******************************************************
* define card uid
*/
const unsigned char uid_1_data[][UUID_TAG_SIZE] = {
  {0x0C, 0x07, 0x8D, 0xAB}
};
#define UID_1_SIZE (sizeof(uid_1_data)/sizeof(unsigned char[UUID_TAG_SIZE]))
const sItem item_1 = {UID_1_SIZE,uid_1_data};

const unsigned char uid_2_data[][UUID_TAG_SIZE] = {
  {0x60, 0xE8, 0x21, 0x83}
};
#define UID_2_SIZE (sizeof(uid_1_data)/sizeof(unsigned char[UUID_TAG_SIZE]))
const sItem item_2 = {UID_2_SIZE,uid_1_data};


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
  &result_seq_A
};
#define SEQ_A_SIZE (sizeof(seq_A)/sizeof(sSequence))
 
/**
 * Full set of directory 0
 */
 
const sDirSequence seq_dir_0 = {
  SEQ_A_SIZE,
  &seq_A
};

/**
 * Table of sequences by directory
 */
const sDirSequence *seq_dir[NB_DIRECTORY] = {
  &seq_dir_0
};








