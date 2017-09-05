#include "config_sequence.h"

const sItem * const seq0Runes[] PROGMEM = { &orgaRune };
#define SEQ_0_RUNES_SIZE (sizeof(seq0Runes)/sizeof(sItem*))
const sResult seq0Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 1 /* org */, true, 0 };
const sSequence seq0[] = { SEQ_0_RUNES_SIZE, &seq0Runes, &seq0Result };

const sItem * const seq1Runes[] PROGMEM = { &orgaRune };
#define SEQ_1_RUNES_SIZE (sizeof(seq1Runes)/sizeof(sItem*))
const sResult seq1Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 1 /* org */, true, 0 };
const sSequence seq1[] = { SEQ_1_RUNES_SIZE, &seq1Runes, &seq1Result };

const sItem * const seq2Runes[] PROGMEM = { &orgaRune };
#define SEQ_2_RUNES_SIZE (sizeof(seq2Runes)/sizeof(sItem*))
const sResult seq2Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 1 /* org */, true, 0 };
const sSequence seq2[] = { SEQ_2_RUNES_SIZE, &seq2Runes, &seq2Result };

const sItem * const seq3Runes[] PROGMEM = { &varselRune, &stansRune };
#define SEQ_3_RUNES_SIZE (sizeof(seq3Runes)/sizeof(sItem*))
const sResult seq3Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 2 /* varsta */, true, 0 };
const sSequence seq3[] = { SEQ_3_RUNES_SIZE, &seq3Runes, &seq3Result };

const sItem * const seq4Runes[] PROGMEM = { &varselRune, &fjellRune };
#define SEQ_4_RUNES_SIZE (sizeof(seq4Runes)/sizeof(sItem*))
const sResult seq4Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 3 /* varfje */, true, 0 };
const sSequence seq4[] = { SEQ_4_RUNES_SIZE, &seq4Runes, &seq4Result };

const sItem * const seq5Runes[] PROGMEM = { &varselRune, &storsaedRune };
#define SEQ_5_RUNES_SIZE (sizeof(seq5Runes)/sizeof(sItem*))
const sResult seq5Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 4 /* varsto */, true, 0 };
const sSequence seq5[] = { SEQ_5_RUNES_SIZE, &seq5Runes, &seq5Result };

const sItem * const seq6Runes[] PROGMEM = { &varselRune, &grenselosRune };
#define SEQ_6_RUNES_SIZE (sizeof(seq6Runes)/sizeof(sItem*))
const sResult seq6Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 5 /* vargre */, true, 0 };
const sSequence seq6[] = { SEQ_6_RUNES_SIZE, &seq6Runes, &seq6Result };

const sDirSequence sequencesDir1 = {
	5,
	{
		&seq0, &seq3, &seq4, &seq5, &seq6
	}
};

const sDirSequence sequencesDir2 = {
	1,
	{
		&seq1
	}
};

const sDirSequence sequencesDir3 = {
	1,
	{
		&seq2
	}
};

// Table of sequences by directory
const sDirSequence *seq_dir[NB_DIRECTORY] = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
