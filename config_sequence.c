
#include "config_sequence.h"

/******************************************************
* define card uid
*/
const unsigned char uid_1_data[][UUID_TAG_SIZE] = {
  {0x0C, 0x07, 0x8D, 0xAB}
};
#define UID_1_SIZE (sizeof(uid_1_data)/sizeof(unsigned char[UUID_TAG_SIZE]))
const sUid uid_1 = {UID_1_SIZE,uid_1_data};

const unsigned char uid_2_data[][UUID_TAG_SIZE] = {
  {0x60, 0xE8, 0x21, 0x83}
};
#define UID_2_SIZE (sizeof(uid_1_data)/sizeof(unsigned char[UUID_TAG_SIZE]))
const sUid uid_2 = {UID_2_SIZE,uid_1_data};


/******************************************************
* define sequence
*/
const sUid *seq_1_data[] = {
  &uid_1,
  &uid_2
};
#define SEQ_1_SIZE (sizeof(seq_1_data)/sizeof(sUid))

const sUid *seq_2_data[] = {
  &uid_2,
  &uid_1
};
#define SEQ_2_SIZE (sizeof(seq_2_data)/sizeof(sUid))

/******************************************************
* final table
*/

const sUidSeq sequence[SEQUENCE_SIZE] = {
  {SEQ_1_SIZE, seq_1_data},
  {SEQ_2_SIZE, seq_2_data}
};







