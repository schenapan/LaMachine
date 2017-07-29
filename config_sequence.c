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

// Varsel  
const t_tag varsel_data[] = {TAG_1, TAG_2};
const sItem item_varsel = {2, varsel_data};

// Ensomhet 
const t_tag ensomhet_data[] = {TAG_3, TAG_4};
const sItem item_ensomhet = {2, ensomhet_data};

// Styrke   
const t_tag styrke_data[] = {TAG_5, TAG_6};
const sItem item_styrke = {2, styrke_data};

// Stans   
const t_tag stans_data[] = {TAG_7, TAG_8};
const sItem item_stans = {2, stans_data};

// Storsaed
const t_tag storsaed_data[] = {TAG_9, TAG_10};
const sItem item_storsaed = {2, storsaed_data};

// Sterk 
const t_tag sterk_data[] = {TAG_11, TAG_12};
const sItem item_sterk = {2, sterk_data};

// Fjell
const t_tag fjell_data[] = {TAG_13, TAG_14};
const sItem item_fjell = {2, fjell_data};

// Grenselos
const t_tag grenselos_data[] = {TAG_15, TAG_16};
const sItem item_grenselos = {2, grenselos_data};

// Nod
const t_tag nod_data[] = {TAG_17, TAG_18};
const sItem item_nod = {2, nod_data};

// Herje
const t_tag herje_data[] = {TAG_19, TAG_20};
const sItem item_herje = {2, herje_data};

// Fornuft 
const t_tag fornuft_data[] = {TAG_21, TAG_22};
const sItem item_fornuft = {2, fornuft_data};

// Kjolig 
const t_tag kjolig_data[] = {TAG_23, TAG_24};
const sItem item_kjolig = {2, kjolig_data};

// Villskap 
const t_tag villskap_data[] = {TAG_23, TAG_24};
const sItem item_villskap = {2, villskap_data};

// Orga  
const t_tag orga_data[] = {TAG_CARTE};
const sItem item_orga = {2, orga_data};

/*
const t_tag uid_x_data[] = {
  TAG_1,  TAG_2,  TAG_3,  TAG_4,  TAG_5,  TAG_6,  TAG_7,  TAG_8,  TAG_9,  TAG_10,  TAG_11,  TAG_12,  TAG_13,
  TAG_14,  TAG_15,  TAG_16,  TAG_17,  TAG_18,  TAG_19,  TAG_20,  TAG_21,  TAG_22,  TAG_23,  TAG_24,  TAG_25,
  TAG_26,  TAG_CARTE
};
const sItem item_x = {27,uid_x_data};
*/

/**
 * export table of items, simplify other process
 */
const sItemTbl items_table = {
        14,
        {
                &item_varsel,
                &item_ensomhet,
                &item_styrke,
                &item_stans,
                &item_storsaed,
                &item_sterk,
                &item_fjell,
                &item_grenselos,
                &item_nod,
                &item_herje,
                &item_fornuft,
                &item_kjolig,
                &item_villskap,
                &item_orga
        }
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

// Séquence Initiation
const sItem *items_seq_initiation[] = {
        &item_varsel,
        &item_ensomhet
};
#define ITEM_SEQ_INITIATION_SIZE (sizeof(items_seq_initiation)/sizeof(sItem*))

const sResult result_seq_initiation = {
        END_OF_SEQUENCE_CONTINUE_DIR_ID, // Directory destination APRES avoir joué le son
        1  // Son à jouer
};

const sSequence seq_initiation[] = {
        ITEM_SEQ_INITIATION_SIZE,
        &items_seq_initiation,
        &result_seq_initiation,
};

// Séquence Renforcement
const sItem *items_seq_renforcement[] = {
        &item_styrke,
        &item_nod
};
#define ITEM_SEQ_RENFORCEMENT_SIZE (sizeof(items_seq_renforcement)/sizeof(sItem*))

/**
 * Directory 1 : Niveau d'énargie faible
 */

// Directory 1 => Séquence Renforcement
const sResult result_seq_renforcement_1 = {
        2, // Directory destination APRES avoir joué le son
        2  // Son à jouer
};

const sSequence seq_renforcement_1[] = {
        ITEM_SEQ_RENFORCEMENT_SIZE,
        &items_seq_renforcement,
        &result_seq_renforcement_1,
};

//Liste des séquences du directory 1
const sDirSequence seq_dir_1 = {
        3,
        {
                &seq_initiation,
                &seq_renforcement_1,
                &seq_orga
        }
};

/**
 * Directory 2 : Niveau d'énargie moyen
 */

// Directory 2 => Séquence Renforcement
const sResult result_seq_renforcement_2 = {
        3, // Directory destination APRES avoir joué le son
        2  // Son à jouer
};

const sSequence seq_renforcement_2[] = {
        ITEM_SEQ_RENFORCEMENT_SIZE,
        &items_seq_renforcement,
        &result_seq_renforcement_2,
};

//Liste des séquences du directory 2
const sDirSequence seq_dir_2 = {
        3,
        {
                &seq_initiation,
                &seq_renforcement_2,
                &seq_orga
        }
};

/**
 * Directory 3 : Niveau d'énargie moyen
 */

// Directory 3 => Séquence Renforcement
const sResult result_seq_renforcement_2 = {
        END_OF_SEQUENCE_CONTINUE_DIR_ID, // Directory destination APRES avoir joué le son
        2  // Son à jouer
};

const sSequence seq_renforcement_3[] = {
        ITEM_SEQ_RENFORCEMENT_SIZE,
        &items_seq_renforcement,
        &result_seq_renforcement_3,
};

//Liste des séquences du directory 2
const sDirSequence seq_dir_3 = {
        3,
        {
                &seq_initiation,
                &seq_renforcement_3,
                &seq_orga
        }
};

/**
 * Table of sequences by directory
 */
const sDirSequence *seq_dir[NB_DIRECTORY] = {
        &seq_dir_1,
        &seq_dir_2,
};








