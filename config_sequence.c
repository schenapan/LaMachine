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
const t_tag varselTags[] = {TAG_1, TAG_2};
const sItem varselRune = {2, varselTags};

// Ensomhet
const t_tag ensomhetTags[] = {TAG_3, TAG_4};
const sItem ensomhetRune = {2, ensomhetTags};

// Styrke
const t_tag styrkeTags[] = {TAG_5, TAG_6};
const sItem styrkeRune = {2, styrkeTags};

// Stans
const t_tag stansTags[] = {TAG_7, TAG_8};
const sItem stansRune = {2, stansTags};

// Storsaed
const t_tag storsaedTags[] = {TAG_9, TAG_10};
const sItem storsaedRune = {2, storsaedTags};

// Sterk
const t_tag sterkTags[] = {TAG_11, TAG_12};
const sItem sterkRune = {2, sterkTags};

// Fjell
const t_tag fjellTags[] = {TAG_13, TAG_14};
const sItem fjellRune = {2, fjellTags};

// Grenselos
const t_tag grenselosTags[] = {TAG_15, TAG_16};
const sItem grenselosRune = {2, grenselosTags};

// Nod
const t_tag nodTags[] = {TAG_17, TAG_18};
const sItem nodRune = {2, nodTags};

// Herje
const t_tag herjeTags[] = {TAG_19, TAG_20};
const sItem herjeRune = {2, herjeTags};

// Fornuft
const t_tag fornuftTags[] = {TAG_21, TAG_22};
const sItem fornuftRune = {2, fornuftTags};

// Kjolig
const t_tag kjoligTags[] = {TAG_23, TAG_24};
const sItem kjoligRune = {2, kjoligTags};

// Villskap
const t_tag villskapTags[] = {TAG_23, TAG_24};
const sItem villskapRune = {2, villskapTags};

// Orga
const t_tag orgaTags[] = {TAG_CARTE};
const sItem orgaRune = {1, orgaTags};

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
                &varselRune,
                &ensomhetRune,
                &styrkeRune,
                &stansRune,
                &storsaedRune,
                &sterkRune,
                &fjellRune,
                &grenselosRune,
                &nodRune,
                &herjeRune,
                &fornuftRune,
                &kjoligRune,
                &villskapRune,
                &orgaRune
        }
};

// Séquence Orga
const sItem *seqOrgaRunes[] = { &orgaRune };
#define SEQ_ORGA_RUNES_SIZE (sizeof(seqOrgaRunes)/sizeof(sItem*))
// Séquence Orga => All Dir
const sResult seqOrgaResult = { END_OF_SEQUENCE_RESTART_ID /* Dir sortie */, 100  /* Son */ };
const sSequence seqOrga[] = { SEQ_ORGA_RUNES_SIZE, &seqOrgaRunes, &seqOrgaResult };

// Séquence Initiation
const sItem *seqInitiationRunes[] = { &varselRune, &ensomhetRune};
#define SEQ_INITIATION_RUNES_SIZE (sizeof(seqInitiationRunes)/sizeof(sItem*))
// Séquence Initiation => All Dir
const sResult seqInitiationResult = { END_OF_SEQUENCE_CONTINUE_DIR_ID /* Dir sortie */, 1  /* Son */ };
const sSequence seqInitiation[] = { SEQ_INITIATION_RUNES_SIZE, &seqInitiationRunes, &seqInitiationResult };

// Séquence Renforcement
const sItem *seqRenforcementRunes[] = { &styrkeRune, &nodRune };
#define SEQ_RENFORCEMENT_RUNES_SIZE (sizeof(seqRenforcementRunes)/sizeof(sItem*))
// Séquence Renforcement => Directory 1
const sResult seqRenforcementResultDir1 = { 2 /* Dir sortie */, 2  /* Son */ };
const sSequence seqRenforcementDir1[] = { SEQ_RENFORCEMENT_RUNES_SIZE, &seqRenforcementRunes, &seqRenforcementResultDir1 };
// Séquence Renforcement => Directory 2
const sResult seqRenforcementResultDir2 = { 3 /* Dir sortie */, 2  /* Son */ };
const sSequence seqRenforcementDir2[] = { SEQ_RENFORCEMENT_RUNES_SIZE, &seqRenforcementRunes, &seqRenforcementResultDir2 };
// Séquence Renforcement => Directory 3
const sResult seqRenforcementResultDir2 = { END_OF_SEQUENCE_CONTINUE_DIR_ID, /* Dir sortie */, 2  /* Son */ };
const sSequence seqRenforcementDir3[] = { SEQ_RENFORCEMENT_RUNES_SIZE, &seqRenforcementRunes, &seqRenforcementResultDir3 };

// Directory 1 : Niveau d'énargie faible
const sDirSequence sequencesDir1 = {
        3,
        {
                &seqInitiation,
                &seqRenforcementDir1,
                &seqOrga
        }
};

// Directory 2 : Niveau d'énargie moyen
const sDirSequence sequencesDir2 = {
        3,
        {
                &seqInitiation,
                &seqRenforcementDir2,
                &seqOrga
        }
};

// Directory 3 : Niveau d'énargie élevé
const sDirSequence sequencesDir3 = {
        3,
        {
                &seqInitiation,
                &seqRenforcementDir3,
                &seqOrga
        }
};

// Table of sequences by directory
const sDirSequence *seq_dir[NB_DIRECTORY] = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
