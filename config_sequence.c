#include "config_sequence.h"
#include "config_items.h"

// Séquence Orga
const sItem *seqOrgaRunes[] = { &orgaRune };
#define SEQ_ORGA_RUNES_SIZE (sizeof(seqOrgaRunes)/sizeof(sItem*))
// Séquence Orga => All Dir
const sResult seqOrgaResult = { END_OF_SEQUENCE_RESTART_ID /* Dir sortie */, 100  /* Son */, false, 0, 0 };
const sSequence seqOrga[] = { SEQ_ORGA_RUNES_SIZE, &seqOrgaRunes, &seqOrgaResult };

// Séquence Initiation
const sItem *seqInitiationRunes[] = { &varselRune, &ensomhetRune};
#define SEQ_INITIATION_RUNES_SIZE (sizeof(seqInitiationRunes)/sizeof(sItem*))
// Séquence Initiation => All Dir
const sResult seqInitiationResult = { END_OF_SEQUENCE_CONTINUE_DIR_ID /* Dir sortie */, 1  /* Son */, false, 3, 0  };
const sSequence seqInitiation[] = { SEQ_INITIATION_RUNES_SIZE, &seqInitiationRunes, &seqInitiationResult };

// Séquence Renforcement
const sItem *seqRenforcementRunes[] = { &styrkeRune, &nodRune };
#define SEQ_RENFORCEMENT_RUNES_SIZE (sizeof(seqRenforcementRunes)/sizeof(sItem*))
// Séquence Renforcement => Directory 1
const sResult seqRenforcementResultDir1 = { 2 /* Dir sortie */, 2  /* Son */, false, 60, 0 };
const sSequence seqRenforcementDir1[] = { SEQ_RENFORCEMENT_RUNES_SIZE, &seqRenforcementRunes, &seqRenforcementResultDir1 };
// Séquence Renforcement => Directory 2
const sResult seqRenforcementResultDir2 = { 3 /* Dir sortie */, 2  /* Son */, false, 60, 0 };
const sSequence seqRenforcementDir2[] = { SEQ_RENFORCEMENT_RUNES_SIZE, &seqRenforcementRunes, &seqRenforcementResultDir2 };
// Séquence Renforcement => Directory 3
const sResult seqRenforcementResultDir3 = { END_OF_SEQUENCE_CONTINUE_DIR_ID /* Dir sortie */, 2  /* Son */, false, 60, 0 };
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
