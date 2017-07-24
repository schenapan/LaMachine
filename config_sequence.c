
#include "config_sequence.h"


#define TAG_1 {0x41, 0x6C, 0x04, 0x6B}
#define TAG_2 {0x06, 0x7F, 0x9E, 0xBB}
#define TAG_3 {0x16, 0xC8, 0x05, 0x6B}
#define TAG_4 {0x53, 0xC7, 0x5F, 0x7B}
#define TAG_5 {0x36, 0x61, 0x8D, 0xBB}
#define TAG_6 {0x35, 0xA3, 0xDB, 0x0D}
#define TAG_7 {0x56, 0xCB, 0x94, 0xBB}
#define TAG_8 {0x36, 0x65, 0x98, 0xBB}
#define TAG_9 {0x46, 0xCF, 0xA1, 0xBB}
#define TAG_10 {0xC4, 0xDC, 0x04, 0x6B}
#define TAG_11 {0x5B, 0x96, 0xDB, 0xAB}
#define TAG_12 {0xAD, 0x7C, 0x05, 0x6B}
#define TAG_13 {0x56, 0x5C, 0x9A, 0xBB}
#define TAG_14 {0x8D, 0x66, 0x60, 0x7B}
#define TAG_15 {0x96, 0x44, 0x97, 0xBB}
#define TAG_16 {0xE6, 0xC5, 0x9E, 0xBB}
#define TAG_17 {0x85, 0x6D, 0xB6, 0x3B}
#define TAG_18 {0x26, 0xCC, 0xA9, 0xBB}
#define TAG_19 {0x61, 0xD8, 0x04, 0x6B}
#define TAG_20 {0x83, 0x56, 0xE6, 0xAB}
#define TAG_21 {0x9A, 0x0D, 0xDB, 0xAB}
#define TAG_22 {0x22, 0x25, 0x4F, 0x39}
#define TAG_23 {0xBF, 0x5A, 0x45, 0x39}
#define TAG_24 {0x7C, 0x8A, 0xEE, 0x2B}
#define TAG_25 {0x36, 0x33, 0x98, 0xBB}
#define TAG_26 {0x60, 0xE8, 0x21, 0x83}
#define TAG_CARTE {0x0C, 0x07, 0x8D, 0xAB}


/******************************************************
* define card uid
*/

// Kjot
const t_tag kjot_data[] = {
  TAG_1,
  TAG_2
};
const sItem item_kjot = { 2, kjot_data };

// Bevegelse 
const t_tag bevegelse_data[] = {
  TAG_3,
  TAG_4
};
const sItem item_bevegelse = { 2, bevegelse_data };

// Varsel  
const t_tag varsel_data[] = {
  TAG_5,
  TAG_6
};
const sItem item_varsel = { 2, varsel_data };

// Orga  
const t_tag orga_data[] = {
  TAG_CARTE
};
const sItem item_orga = { 2, orga_data };

/*
const t_tag uid_x_data[] = {
  TAG_1,
  TAG_2,
  TAG_3,
  TAG_4,
  TAG_5,
  TAG_6,
  TAG_7,
  TAG_8,
  TAG_9,
  TAG_10,
  TAG_11,
  TAG_12,
  TAG_13,
  TAG_14,
  TAG_15,
  TAG_16,
  TAG_17,
  TAG_18,
  TAG_19,
  TAG_20,
  TAG_21,
  TAG_22,
  TAG_23,
  TAG_24,
  TAG_25,
  TAG_26,
  TAG_CARTE
};
const sItem item_x = {27,uid_x_data};
*/

/**
 * export table of items, simplify other process
 */
const sItemTbl items_table = {
  4,
  { &item_kjot, &item_bevegelse, &item_varsel, &item_orga }
};


/**
 * Sequence Orga
 */

const sItem *items_seq_orga[] = {
  &item_orga
};
#define ITEM_SEQ_ORGA_SIZE (sizeof(items_seq_orga)/sizeof(sItem*))

const sResult result_seq_orga = {
  END_OF_SEQUENCE_RESTART_ID, // Directory destination APRES avoir joué le son
  100  // Son à jouer
};

const sSequence seq_orga[] = {
   ITEM_SEQ_ORGA_SIZE,
  &items_seq_orga,
  &result_seq_orga,
};

/**
 * Directory 1
 */

/**
 * Sequence A
 */

const sItem *items_seq_A[] = {
  &item_kjot,
  &item_bevegelse,
  &item_varsel
};
#define ITEM_SEQ_A_SIZE (sizeof(items_seq_A)/sizeof(sItem*))

const sResult result_seq_A = {
  1, // Directory destination APRES avoir joué le son
  1  // Son à jouer
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
  &item_bevegelse,
  &item_varsel,
  &item_kjot
};
#define ITEM_SEQ_B_SIZE (sizeof(items_seq_B)/sizeof(sItem*))

const sResult result_seq_B = {
  2, // Directory destination APRES avoir joué le son
  2  //Son à jouer
};

const sSequence seq_B[] = {
   ITEM_SEQ_B_SIZE,
  &items_seq_B,
  &result_seq_B,
};
 
/**
 * Full set of directory 1
 */
 
const sDirSequence seq_dir_0 = {
  3,
  { &seq_A, &seq_B, &seq_orga }
};

/**
 * Directory 2
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
  3,
  {&seq_1_A,&seq_1_B, &seq_orga}
};

/**
 * Table of sequences by directory
 */
const sDirSequence *seq_dir[NB_DIRECTORY] = {
  &seq_dir_0,
  &seq_dir_1,
};








