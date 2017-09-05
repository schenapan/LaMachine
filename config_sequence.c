#include "config_sequence.h"

const sItem * const seq0Runes[] PROGMEM = { &kjoligRune, &fornuftRune };
#define SEQ_0_RUNES_SIZE (sizeof(seq0Runes)/sizeof(sItem*))
const sResult seq0Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 1 /* kjofor */, true, 120 };
const sSequence seq0[] = { SEQ_0_RUNES_SIZE, &seq0Runes, &seq0Result };

const sItem * const seq1Runes[] PROGMEM = { &kjoligRune, &ensomhetRune };
#define SEQ_1_RUNES_SIZE (sizeof(seq1Runes)/sizeof(sItem*))
const sResult seq1Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 2 /* kjoens */, true, 120 };
const sSequence seq1[] = { SEQ_1_RUNES_SIZE, &seq1Runes, &seq1Result };

const sItem * const seq2Runes[] PROGMEM = { &kjoligRune, &sterkRune };
#define SEQ_2_RUNES_SIZE (sizeof(seq2Runes)/sizeof(sItem*))
const sResult seq2Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 3 /* kjoste */, true, 120 };
const sSequence seq2[] = { SEQ_2_RUNES_SIZE, &seq2Runes, &seq2Result };

const sItem * const seq3Runes[] PROGMEM = { &kjoligRune, &stansRune };
#define SEQ_3_RUNES_SIZE (sizeof(seq3Runes)/sizeof(sItem*))
const sResult seq3Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 4 /* kjosta */, true, 0 };
const sSequence seq3[] = { SEQ_3_RUNES_SIZE, &seq3Runes, &seq3Result };

const sItem * const seq4Runes[] PROGMEM = { &kjoligRune, &storsaedRune };
#define SEQ_4_RUNES_SIZE (sizeof(seq4Runes)/sizeof(sItem*))
const sResult seq4Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 5 /* kjosto */, true, 120 };
const sSequence seq4[] = { SEQ_4_RUNES_SIZE, &seq4Runes, &seq4Result };

const sItem * const seq5Runes[] PROGMEM = { &kjoligRune, &nodRune };
#define SEQ_5_RUNES_SIZE (sizeof(seq5Runes)/sizeof(sItem*))
const sResult seq5Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 6 /* kjonod */, true, 120 };
const sSequence seq5[] = { SEQ_5_RUNES_SIZE, &seq5Runes, &seq5Result };

const sItem * const seq6Runes[] PROGMEM = { &fornuftRune, &villskapRune };
#define SEQ_6_RUNES_SIZE (sizeof(seq6Runes)/sizeof(sItem*))
const sResult seq6Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 7 /* forvil */, true, 120 };
const sSequence seq6[] = { SEQ_6_RUNES_SIZE, &seq6Runes, &seq6Result };

const sItem * const seq7Runes[] PROGMEM = { &fornuftRune, &stansRune };
#define SEQ_7_RUNES_SIZE (sizeof(seq7Runes)/sizeof(sItem*))
const sResult seq7Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 8 /* forsta */, true, 120 };
const sSequence seq7[] = { SEQ_7_RUNES_SIZE, &seq7Runes, &seq7Result };

const sItem * const seq8Runes[] PROGMEM = { &fornuftRune, &storsaedRune };
#define SEQ_8_RUNES_SIZE (sizeof(seq8Runes)/sizeof(sItem*))
const sResult seq8Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 9 /* forsto */, true, 120 };
const sSequence seq8[] = { SEQ_8_RUNES_SIZE, &seq8Runes, &seq8Result };

const sItem * const seq9Runes[] PROGMEM = { &fornuftRune, &fjellRune };
#define SEQ_9_RUNES_SIZE (sizeof(seq9Runes)/sizeof(sItem*))
const sResult seq9Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 10 /* forfje */, true, 0 };
const sSequence seq9[] = { SEQ_9_RUNES_SIZE, &seq9Runes, &seq9Result };

const sItem * const seq10Runes[] PROGMEM = { &villskapRune, &styrkeRune };
#define SEQ_10_RUNES_SIZE (sizeof(seq10Runes)/sizeof(sItem*))
const sResult seq10Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 11 /* vilsty */, true, 120 };
const sSequence seq10[] = { SEQ_10_RUNES_SIZE, &seq10Runes, &seq10Result };

const sItem * const seq11Runes[] PROGMEM = { &ensomhetRune, &varselRune };
#define SEQ_11_RUNES_SIZE (sizeof(seq11Runes)/sizeof(sItem*))
const sResult seq11Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 12 /* ensvar */, true, 0 };
const sSequence seq11[] = { SEQ_11_RUNES_SIZE, &seq11Runes, &seq11Result };

const sItem * const seq12Runes[] PROGMEM = { &ensomhetRune, &varselRune };
#define SEQ_12_RUNES_SIZE (sizeof(seq12Runes)/sizeof(sItem*))
const sResult seq12Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 12 /* ensvar */, true, 0 };
const sSequence seq12[] = { SEQ_12_RUNES_SIZE, &seq12Runes, &seq12Result };

const sItem * const seq13Runes[] PROGMEM = { &ensomhetRune, &varselRune };
#define SEQ_13_RUNES_SIZE (sizeof(seq13Runes)/sizeof(sItem*))
const sResult seq13Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 12 /* ensvar */, true, 0 };
const sSequence seq13[] = { SEQ_13_RUNES_SIZE, &seq13Runes, &seq13Result };

const sItem * const seq14Runes[] PROGMEM = { &sterkRune, &styrkeRune };
#define SEQ_14_RUNES_SIZE (sizeof(seq14Runes)/sizeof(sItem*))
const sResult seq14Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 13 /* stesty */, true, 0 };
const sSequence seq14[] = { SEQ_14_RUNES_SIZE, &seq14Runes, &seq14Result };

const sItem * const seq15Runes[] PROGMEM = { &sterkRune, &styrkeRune };
#define SEQ_15_RUNES_SIZE (sizeof(seq15Runes)/sizeof(sItem*))
const sResult seq15Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 13 /* stesty */, true, 0 };
const sSequence seq15[] = { SEQ_15_RUNES_SIZE, &seq15Runes, &seq15Result };

const sItem * const seq16Runes[] PROGMEM = { &varselRune, &stansRune };
#define SEQ_16_RUNES_SIZE (sizeof(seq16Runes)/sizeof(sItem*))
const sResult seq16Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 14 /* varsta */, true, 0 };
const sSequence seq16[] = { SEQ_16_RUNES_SIZE, &seq16Runes, &seq16Result };

const sItem * const seq17Runes[] PROGMEM = { &varselRune, &stansRune };
#define SEQ_17_RUNES_SIZE (sizeof(seq17Runes)/sizeof(sItem*))
const sResult seq17Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 14 /* varsta */, true, 0 };
const sSequence seq17[] = { SEQ_17_RUNES_SIZE, &seq17Runes, &seq17Result };

const sItem * const seq18Runes[] PROGMEM = { &varselRune, &stansRune };
#define SEQ_18_RUNES_SIZE (sizeof(seq18Runes)/sizeof(sItem*))
const sResult seq18Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 14 /* varsta */, true, 0 };
const sSequence seq18[] = { SEQ_18_RUNES_SIZE, &seq18Runes, &seq18Result };

const sItem * const seq19Runes[] PROGMEM = { &varselRune, &grenselosRune };
#define SEQ_19_RUNES_SIZE (sizeof(seq19Runes)/sizeof(sItem*))
const sResult seq19Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 15 /* vargre */, true, 120 };
const sSequence seq19[] = { SEQ_19_RUNES_SIZE, &seq19Runes, &seq19Result };

const sItem * const seq20Runes[] PROGMEM = { &varselRune, &styrkeRune };
#define SEQ_20_RUNES_SIZE (sizeof(seq20Runes)/sizeof(sItem*))
const sResult seq20Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 16 /* varsty */, true, 120 };
const sSequence seq20[] = { SEQ_20_RUNES_SIZE, &seq20Runes, &seq20Result };

const sItem * const seq21Runes[] PROGMEM = { &varselRune, &fjellRune };
#define SEQ_21_RUNES_SIZE (sizeof(seq21Runes)/sizeof(sItem*))
const sResult seq21Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 17 /* varfje */, true, 0 };
const sSequence seq21[] = { SEQ_21_RUNES_SIZE, &seq21Runes, &seq21Result };

const sItem * const seq22Runes[] PROGMEM = { &varselRune, &fjellRune };
#define SEQ_22_RUNES_SIZE (sizeof(seq22Runes)/sizeof(sItem*))
const sResult seq22Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 17 /* varfje */, true, 0 };
const sSequence seq22[] = { SEQ_22_RUNES_SIZE, &seq22Runes, &seq22Result };

const sItem * const seq23Runes[] PROGMEM = { &stansRune, &nodRune };
#define SEQ_23_RUNES_SIZE (sizeof(seq23Runes)/sizeof(sItem*))
const sResult seq23Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 18 /* stanod */, true, 0 };
const sSequence seq23[] = { SEQ_23_RUNES_SIZE, &seq23Runes, &seq23Result };

const sItem * const seq24Runes[] PROGMEM = { &stansRune, &styrkeRune };
#define SEQ_24_RUNES_SIZE (sizeof(seq24Runes)/sizeof(sItem*))
const sResult seq24Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 19 /* stasty */, true, 120 };
const sSequence seq24[] = { SEQ_24_RUNES_SIZE, &seq24Runes, &seq24Result };

const sItem * const seq25Runes[] PROGMEM = { &grenselosRune, &nodRune };
#define SEQ_25_RUNES_SIZE (sizeof(seq25Runes)/sizeof(sItem*))
const sResult seq25Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 20 /* grenod */, true, 0 };
const sSequence seq25[] = { SEQ_25_RUNES_SIZE, &seq25Runes, &seq25Result };

const sItem * const seq26Runes[] PROGMEM = { &grenselosRune, &styrkeRune };
#define SEQ_26_RUNES_SIZE (sizeof(seq26Runes)/sizeof(sItem*))
const sResult seq26Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 21 /* gresty */, true, 0 };
const sSequence seq26[] = { SEQ_26_RUNES_SIZE, &seq26Runes, &seq26Result };

const sItem * const seq27Runes[] PROGMEM = { &grenselosRune, &styrkeRune };
#define SEQ_27_RUNES_SIZE (sizeof(seq27Runes)/sizeof(sItem*))
const sResult seq27Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 21 /* gresty */, true, 0 };
const sSequence seq27[] = { SEQ_27_RUNES_SIZE, &seq27Runes, &seq27Result };

const sItem * const seq28Runes[] PROGMEM = { &storsaedRune, &nodRune };
#define SEQ_28_RUNES_SIZE (sizeof(seq28Runes)/sizeof(sItem*))
const sResult seq28Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 22 /* stonod */, true, 0 };
const sSequence seq28[] = { SEQ_28_RUNES_SIZE, &seq28Runes, &seq28Result };

const sItem * const seq29Runes[] PROGMEM = { &storsaedRune, &nodRune };
#define SEQ_29_RUNES_SIZE (sizeof(seq29Runes)/sizeof(sItem*))
const sResult seq29Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 22 /* stonod */, true, 0 };
const sSequence seq29[] = { SEQ_29_RUNES_SIZE, &seq29Runes, &seq29Result };

const sItem * const seq30Runes[] PROGMEM = { &storsaedRune, &styrkeRune };
#define SEQ_30_RUNES_SIZE (sizeof(seq30Runes)/sizeof(sItem*))
const sResult seq30Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 23 /* stosty */, true, 120 };
const sSequence seq30[] = { SEQ_30_RUNES_SIZE, &seq30Runes, &seq30Result };

const sItem * const seq31Runes[] PROGMEM = { &orgaRune };
#define SEQ_31_RUNES_SIZE (sizeof(seq31Runes)/sizeof(sItem*))
const sResult seq31Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 24 /* org */, true, 0 };
const sSequence seq31[] = { SEQ_31_RUNES_SIZE, &seq31Runes, &seq31Result };

const sItem * const seq32Runes[] PROGMEM = { &orgaRune };
#define SEQ_32_RUNES_SIZE (sizeof(seq32Runes)/sizeof(sItem*))
const sResult seq32Result = { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 24 /* org */, true, 0 };
const sSequence seq32[] = { SEQ_32_RUNES_SIZE, &seq32Runes, &seq32Result };

const sItem * const seq33Runes[] PROGMEM = { &orgaRune };
#define SEQ_33_RUNES_SIZE (sizeof(seq33Runes)/sizeof(sItem*))
const sResult seq33Result = { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 24 /* org */, true, 0 };
const sSequence seq33[] = { SEQ_33_RUNES_SIZE, &seq33Runes, &seq33Result };

const sDirSequence sequencesDir1 = {
	15,
	{
		&seq0, &seq1, &seq2, &seq3, &seq5, &seq6, &seq7, &seq10, &seq13, &seq14, &seq16, &seq19, &seq24, &seq30, &seq31
	}
};

const sDirSequence sequencesDir2 = {
	12,
	{
		&seq4, &seq9, &seq12, &seq15, &seq17, &seq20, &seq21, &seq23, &seq25, &seq26, &seq28, &seq32
	}
};

const sDirSequence sequencesDir3 = {
	7,
	{
		&seq8, &seq11, &seq18, &seq22, &seq27, &seq29, &seq33
	}
};

// Table of sequences by directory
const sDirSequence *seq_dir[NB_DIRECTORY] = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
