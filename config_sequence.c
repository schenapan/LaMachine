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

const sItem * const seq3Runes[] PROGMEM = { &varselRune };
#define SEQ_3_RUNES_SIZE (sizeof(seq3Runes)/sizeof(sItem*))
const sResult seq3Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 2 /* var */, true, 0 };
const sSequence seq3[] = { SEQ_3_RUNES_SIZE, &seq3Runes, &seq3Result };

const sItem * const seq4Runes[] PROGMEM = { &stansRune };
#define SEQ_4_RUNES_SIZE (sizeof(seq4Runes)/sizeof(sItem*))
const sResult seq4Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 3 /* sta */, true, 0 };
const sSequence seq4[] = { SEQ_4_RUNES_SIZE, &seq4Runes, &seq4Result };

const sItem * const seq5Runes[] PROGMEM = { &fjellRune };
#define SEQ_5_RUNES_SIZE (sizeof(seq5Runes)/sizeof(sItem*))
const sResult seq5Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 4 /* fje */, true, 0 };
const sSequence seq5[] = { SEQ_5_RUNES_SIZE, &seq5Runes, &seq5Result };

const sItem * const seq6Runes[] PROGMEM = { &herjeRune };
#define SEQ_6_RUNES_SIZE (sizeof(seq6Runes)/sizeof(sItem*))
const sResult seq6Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 5 /* her */, true, 0 };
const sSequence seq6[] = { SEQ_6_RUNES_SIZE, &seq6Runes, &seq6Result };

const sItem * const seq7Runes[] PROGMEM = { &villskapRune };
#define SEQ_7_RUNES_SIZE (sizeof(seq7Runes)/sizeof(sItem*))
const sResult seq7Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 6 /* vil */, true, 0 };
const sSequence seq7[] = { SEQ_7_RUNES_SIZE, &seq7Runes, &seq7Result };

const sItem * const seq8Runes[] PROGMEM = { &ensomhetRune };
#define SEQ_8_RUNES_SIZE (sizeof(seq8Runes)/sizeof(sItem*))
const sResult seq8Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 7 /* ens */, true, 0 };
const sSequence seq8[] = { SEQ_8_RUNES_SIZE, &seq8Runes, &seq8Result };

const sItem * const seq9Runes[] PROGMEM = { &storsaedRune };
#define SEQ_9_RUNES_SIZE (sizeof(seq9Runes)/sizeof(sItem*))
const sResult seq9Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 8 /* sto */, true, 0 };
const sSequence seq9[] = { SEQ_9_RUNES_SIZE, &seq9Runes, &seq9Result };

const sItem * const seq10Runes[] PROGMEM = { &grenselosRune };
#define SEQ_10_RUNES_SIZE (sizeof(seq10Runes)/sizeof(sItem*))
const sResult seq10Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 9 /* gre */, true, 0 };
const sSequence seq10[] = { SEQ_10_RUNES_SIZE, &seq10Runes, &seq10Result };

const sItem * const seq11Runes[] PROGMEM = { &fornuftRune };
#define SEQ_11_RUNES_SIZE (sizeof(seq11Runes)/sizeof(sItem*))
const sResult seq11Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 10 /* for */, true, 0 };
const sSequence seq11[] = { SEQ_11_RUNES_SIZE, &seq11Runes, &seq11Result };

const sItem * const seq12Runes[] PROGMEM = { &styrkeRune };
#define SEQ_12_RUNES_SIZE (sizeof(seq12Runes)/sizeof(sItem*))
const sResult seq12Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 11 /* sty */, true, 0 };
const sSequence seq12[] = { SEQ_12_RUNES_SIZE, &seq12Runes, &seq12Result };

const sItem * const seq13Runes[] PROGMEM = { &sterkRune };
#define SEQ_13_RUNES_SIZE (sizeof(seq13Runes)/sizeof(sItem*))
const sResult seq13Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 12 /* ste */, true, 0 };
const sSequence seq13[] = { SEQ_13_RUNES_SIZE, &seq13Runes, &seq13Result };

const sItem * const seq14Runes[] PROGMEM = { &nodRune };
#define SEQ_14_RUNES_SIZE (sizeof(seq14Runes)/sizeof(sItem*))
const sResult seq14Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 13 /* nod */, true, 0 };
const sSequence seq14[] = { SEQ_14_RUNES_SIZE, &seq14Runes, &seq14Result };

const sItem * const seq15Runes[] PROGMEM = { &kjoligRune };
#define SEQ_15_RUNES_SIZE (sizeof(seq15Runes)/sizeof(sItem*))
const sResult seq15Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 14 /* kjo */, true, 0 };
const sSequence seq15[] = { SEQ_15_RUNES_SIZE, &seq15Runes, &seq15Result };

const sDirSequence sequencesDir1 = {
	14,
	{
		&seq0, &seq3, &seq4, &seq5, &seq6, &seq7, &seq8, &seq9, &seq10, &seq11, &seq12, &seq13, &seq14, &seq15
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
