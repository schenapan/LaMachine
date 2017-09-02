#include "config_sequence.h"
#include "config_items.h"

const sItem *seq0Runes[] = { &kjoligRune, &fornuftRune };
#define SEQ_0_RUNES_SIZE (sizeof(seq0Runes)/sizeof(sItem*))
const sResult seq0Result = { END_OF_SEQUENCE_RESTART_ID, 102 /* kjofor */, true, 120 };
const sSequence seq0[] = { SEQ_0_RUNES_SIZE, &seq0Runes, &seq0Result };

const sItem *seq1Runes[] = { &kjoligRune, &ensomhetRune };
#define SEQ_1_RUNES_SIZE (sizeof(seq1Runes)/sizeof(sItem*))
const sResult seq1Result = { END_OF_SEQUENCE_RESTART_ID, 103 /* kjoens */, true, 120 };
const sSequence seq1[] = { SEQ_1_RUNES_SIZE, &seq1Runes, &seq1Result };

const sItem *seq2Runes[] = { &kjoligRune, &sterkRune };
#define SEQ_2_RUNES_SIZE (sizeof(seq2Runes)/sizeof(sItem*))
const sResult seq2Result = { END_OF_SEQUENCE_RESTART_ID, 104 /* kjoste */, true, 120 };
const sSequence seq2[] = { SEQ_2_RUNES_SIZE, &seq2Runes, &seq2Result };

const sItem *seq3Runes[] = { &kjoligRune, &stansRune };
#define SEQ_3_RUNES_SIZE (sizeof(seq3Runes)/sizeof(sItem*))
const sResult seq3Result = { END_OF_SEQUENCE_RESTART_ID, 105 /* kjosta */, true, 0 };
const sSequence seq3[] = { SEQ_3_RUNES_SIZE, &seq3Runes, &seq3Result };

const sItem *seq4Runes[] = { &kjoligRune, &storsaedRune };
#define SEQ_4_RUNES_SIZE (sizeof(seq4Runes)/sizeof(sItem*))
const sResult seq4Result = { END_OF_SEQUENCE_RESTART_ID, 206 /* kjosto */, true, 120 };
const sSequence seq4[] = { SEQ_4_RUNES_SIZE, &seq4Runes, &seq4Result };

const sItem *seq5Runes[] = { &kjoligRune, &nodRune };
#define SEQ_5_RUNES_SIZE (sizeof(seq5Runes)/sizeof(sItem*))
const sResult seq5Result = { END_OF_SEQUENCE_RESTART_ID, 107 /* kjonod */, true, 120 };
const sSequence seq5[] = { SEQ_5_RUNES_SIZE, &seq5Runes, &seq5Result };

const sItem *seq6Runes[] = { &fornuftRune, &villskapRune };
#define SEQ_6_RUNES_SIZE (sizeof(seq6Runes)/sizeof(sItem*))
const sResult seq6Result = { END_OF_SEQUENCE_RESTART_ID, 108 /* forvil */, true, 120 };
const sSequence seq6[] = { SEQ_6_RUNES_SIZE, &seq6Runes, &seq6Result };

const sItem *seq7Runes[] = { &fornuftRune, &stansRune };
#define SEQ_7_RUNES_SIZE (sizeof(seq7Runes)/sizeof(sItem*))
const sResult seq7Result = { END_OF_SEQUENCE_RESTART_ID, 109 /* forsta */, true, 120 };
const sSequence seq7[] = { SEQ_7_RUNES_SIZE, &seq7Runes, &seq7Result };

const sItem *seq8Runes[] = { &fornuftRune, &storsaedRune };
#define SEQ_8_RUNES_SIZE (sizeof(seq8Runes)/sizeof(sItem*))
const sResult seq8Result = { END_OF_SEQUENCE_RESTART_ID, 310 /* forsto */, true, 120 };
const sSequence seq8[] = { SEQ_8_RUNES_SIZE, &seq8Runes, &seq8Result };

const sItem *seq9Runes[] = { &fornuftRune, &fjellRune };
#define SEQ_9_RUNES_SIZE (sizeof(seq9Runes)/sizeof(sItem*))
const sResult seq9Result = { 1, 211 /* forfje */, true, 0 };
const sSequence seq9[] = { SEQ_9_RUNES_SIZE, &seq9Runes, &seq9Result };

const sItem *seq10Runes[] = { &villskapRune, &styrkeRune };
#define SEQ_10_RUNES_SIZE (sizeof(seq10Runes)/sizeof(sItem*))
const sResult seq10Result = { END_OF_SEQUENCE_RESTART_ID, 112 /* vilsty */, true, 120 };
const sSequence seq10[] = { SEQ_10_RUNES_SIZE, &seq10Runes, &seq10Result };

const sItem *seq11Runes[] = { &ensomhetRune, &varselRune };
#define SEQ_11_RUNES_SIZE (sizeof(seq11Runes)/sizeof(sItem*))
const sResult seq11Result = { END_OF_SEQUENCE_RESTART_ID, 313 /* ensvar */, true, 0 };
const sSequence seq11[] = { SEQ_11_RUNES_SIZE, &seq11Runes, &seq11Result };

const sItem *seq12Runes[] = { &ensomhetRune, &varselRune };
#define SEQ_12_RUNES_SIZE (sizeof(seq12Runes)/sizeof(sItem*))
const sResult seq12Result = { END_OF_SEQUENCE_RESTART_ID, 213 /* ensvar */, true, 0 };
const sSequence seq12[] = { SEQ_12_RUNES_SIZE, &seq12Runes, &seq12Result };

const sItem *seq13Runes[] = { &ensomhetRune, &varselRune };
#define SEQ_13_RUNES_SIZE (sizeof(seq13Runes)/sizeof(sItem*))
const sResult seq13Result = { END_OF_SEQUENCE_RESTART_ID, 113 /* ensvar */, true, 0 };
const sSequence seq13[] = { SEQ_13_RUNES_SIZE, &seq13Runes, &seq13Result };

const sItem *seq14Runes[] = { &sterkRune, &styrkeRune };
#define SEQ_14_RUNES_SIZE (sizeof(seq14Runes)/sizeof(sItem*))
const sResult seq14Result = { 2, 114 /* stesty */, true, 0 };
const sSequence seq14[] = { SEQ_14_RUNES_SIZE, &seq14Runes, &seq14Result };

const sItem *seq15Runes[] = { &sterkRune, &styrkeRune };
#define SEQ_15_RUNES_SIZE (sizeof(seq15Runes)/sizeof(sItem*))
const sResult seq15Result = { END_OF_SEQUENCE_RESTART_ID, 214 /* stesty */, true, 0 };
const sSequence seq15[] = { SEQ_15_RUNES_SIZE, &seq15Runes, &seq15Result };

const sItem *seq16Runes[] = { &varselRune, &stansRune };
#define SEQ_16_RUNES_SIZE (sizeof(seq16Runes)/sizeof(sItem*))
const sResult seq16Result = { END_OF_SEQUENCE_RESTART_ID, 115 /* varsta */, true, 0 };
const sSequence seq16[] = { SEQ_16_RUNES_SIZE, &seq16Runes, &seq16Result };

const sItem *seq17Runes[] = { &varselRune, &stansRune };
#define SEQ_17_RUNES_SIZE (sizeof(seq17Runes)/sizeof(sItem*))
const sResult seq17Result = { END_OF_SEQUENCE_RESTART_ID, 215 /* varsta */, true, 0 };
const sSequence seq17[] = { SEQ_17_RUNES_SIZE, &seq17Runes, &seq17Result };

const sItem *seq18Runes[] = { &varselRune, &stansRune };
#define SEQ_18_RUNES_SIZE (sizeof(seq18Runes)/sizeof(sItem*))
const sResult seq18Result = { END_OF_SEQUENCE_RESTART_ID, 315 /* varsta */, true, 0 };
const sSequence seq18[] = { SEQ_18_RUNES_SIZE, &seq18Runes, &seq18Result };

const sItem *seq19Runes[] = { &varselRune, &grenselosRune };
#define SEQ_19_RUNES_SIZE (sizeof(seq19Runes)/sizeof(sItem*))
const sResult seq19Result = { END_OF_SEQUENCE_RESTART_ID, 116 /* vargre */, true, 120 };
const sSequence seq19[] = { SEQ_19_RUNES_SIZE, &seq19Runes, &seq19Result };

const sItem *seq20Runes[] = { &varselRune, &styrkeRune };
#define SEQ_20_RUNES_SIZE (sizeof(seq20Runes)/sizeof(sItem*))
const sResult seq20Result = { END_OF_SEQUENCE_RESTART_ID, 217 /* varsty */, true, 120 };
const sSequence seq20[] = { SEQ_20_RUNES_SIZE, &seq20Runes, &seq20Result };

const sItem *seq21Runes[] = { &varselRune, &fjellRune };
#define SEQ_21_RUNES_SIZE (sizeof(seq21Runes)/sizeof(sItem*))
const sResult seq21Result = { END_OF_SEQUENCE_RESTART_ID, 218 /* varfje */, true, 0 };
const sSequence seq21[] = { SEQ_21_RUNES_SIZE, &seq21Runes, &seq21Result };

const sItem *seq22Runes[] = { &varselRune, &fjellRune };
#define SEQ_22_RUNES_SIZE (sizeof(seq22Runes)/sizeof(sItem*))
const sResult seq22Result = { END_OF_SEQUENCE_RESTART_ID, 318 /* varfje */, true, 0 };
const sSequence seq22[] = { SEQ_22_RUNES_SIZE, &seq22Runes, &seq22Result };

const sItem *seq23Runes[] = { &stansRune, &nodRune };
#define SEQ_23_RUNES_SIZE (sizeof(seq23Runes)/sizeof(sItem*))
const sResult seq23Result = { END_OF_SEQUENCE_RESTART_ID, 219 /* stanod */, true, 0 };
const sSequence seq23[] = { SEQ_23_RUNES_SIZE, &seq23Runes, &seq23Result };

const sItem *seq24Runes[] = { &stansRune, &styrkeRune };
#define SEQ_24_RUNES_SIZE (sizeof(seq24Runes)/sizeof(sItem*))
const sResult seq24Result = { END_OF_SEQUENCE_RESTART_ID, 120 /* stasty */, true, 120 };
const sSequence seq24[] = { SEQ_24_RUNES_SIZE, &seq24Runes, &seq24Result };

const sItem *seq25Runes[] = { &grenselosRune, &nodRune };
#define SEQ_25_RUNES_SIZE (sizeof(seq25Runes)/sizeof(sItem*))
const sResult seq25Result = { END_OF_SEQUENCE_RESTART_ID, 221 /* grenod */, true, 0 };
const sSequence seq25[] = { SEQ_25_RUNES_SIZE, &seq25Runes, &seq25Result };

const sItem *seq26Runes[] = { &grenselosRune, &styrkeRune };
#define SEQ_26_RUNES_SIZE (sizeof(seq26Runes)/sizeof(sItem*))
const sResult seq26Result = { END_OF_SEQUENCE_RESTART_ID, 222 /* gresty */, true, 0 };
const sSequence seq26[] = { SEQ_26_RUNES_SIZE, &seq26Runes, &seq26Result };

const sItem *seq27Runes[] = { &grenselosRune, &styrkeRune };
#define SEQ_27_RUNES_SIZE (sizeof(seq27Runes)/sizeof(sItem*))
const sResult seq27Result = { 2, 322 /* gresty */, true, 0 };
const sSequence seq27[] = { SEQ_27_RUNES_SIZE, &seq27Runes, &seq27Result };

const sItem *seq28Runes[] = { &storsaedRune, &nodRune };
#define SEQ_28_RUNES_SIZE (sizeof(seq28Runes)/sizeof(sItem*))
const sResult seq28Result = { 3, 223 /* stonod */, true, 0 };
const sSequence seq28[] = { SEQ_28_RUNES_SIZE, &seq28Runes, &seq28Result };

const sItem *seq29Runes[] = { &storsaedRune, &nodRune };
#define SEQ_29_RUNES_SIZE (sizeof(seq29Runes)/sizeof(sItem*))
const sResult seq29Result = { END_OF_SEQUENCE_RESTART_ID, 323 /* stonod */, true, 0 };
const sSequence seq29[] = { SEQ_29_RUNES_SIZE, &seq29Runes, &seq29Result };

const sItem *seq30Runes[] = { &storsaedRune, &styrkeRune };
#define SEQ_30_RUNES_SIZE (sizeof(seq30Runes)/sizeof(sItem*))
const sResult seq30Result = { END_OF_SEQUENCE_RESTART_ID, 124 /* stosty */, true, 120 };
const sSequence seq30[] = { SEQ_30_RUNES_SIZE, &seq30Runes, &seq30Result };

const sDirSequence sequencesDir1 = {
	14,
	{
		&seq0, &seq1, &seq2, &seq3, &seq5, &seq6, &seq7, &seq10, &seq13, &seq14, &seq16, &seq19, &seq24, &seq30
	}
};

const sDirSequence sequencesDir2 = {
	11,
	{
		&seq4, &seq9, &seq12, &seq15, &seq17, &seq20, &seq21, &seq23, &seq25, &seq26, &seq28
	}
};

const sDirSequence sequencesDir3 = {
	6,
	{
		&seq8, &seq11, &seq18, &seq22, &seq27, &seq29
	}
};

// Table of sequences by directory
const sDirSequence *seq_dir[NB_DIRECTORY] = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
