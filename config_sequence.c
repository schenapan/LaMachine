#include "config_sequence.h"

const sSequence seq0 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 1 /* KjoligFornuft */, false, 0 }, 
                                   2, 
                                   { &kjoligRune, &fornuftRune } };

const sSequence seq1 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID/*LEVEL_2*/, /* Kronien */ 1 /* KjoligFornuft */, false, 120 }, 
                                   2, 
                                   { &kjoligRune, &fornuftRune } };

const sSequence seq11 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 4 /* KjoligEnsomhet */, false, 120 }, 
                                   2, 
                                   { &kjoligRune, &ensomhetRune } };

const sSequence seq14 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 5 /* KjoligSterk */, false, 120 }, 
                                   2, 
                                   { &kjoligRune, &sterkRune } };

const sSequence seq20 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 7 /* KjoligStans */, false, 0 }, 
                                   2, 
                                   { &kjoligRune, &stansRune } };

const sSequence seq24 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 9 /* KjoligStorsaed */, false, 120 }, 
                                   2, 
                                   { &kjoligRune, &storsaedRune } };

const sSequence seq29 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 10 /* KjoligNod */, false, 120 }, 
                                   2, 
                                   { &kjoligRune, &nodRune } };

const sSequence seq38 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 13 /* FornuftVillskap */, false, 120 }, 
                                   2, 
                                   { &fornuftRune, &villskapRune } };

const sSequence seq53 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 18 /* FornuftStans */, false, 120 }, 
                                   2, 
                                   { &fornuftRune, &stansRune } };

const sSequence seq58 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 20 /* FornuftStorsaed */, false, 120 }, 
                                   2, 
                                   { &fornuftRune, &storsaedRune } };

const sSequence seq66 PROGMEM = { { LEVEL_3, /* Æthérique */ 23 /* FornuftFjell */, true, 0 }, 
                                   2, 
                                   { &fornuftRune, &fjellRune } };

const sSequence seq95 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 32 /* VillskapStyrke */, false, 120 }, 
                                   2, 
                                   { &villskapRune, &styrkeRune } };

const sSequence seq126 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 43 /* EnsomhetVarsel */, false, 0 }, 
                                   2, 
                                   { &ensomhetRune, &varselRune } };

const sSequence seq127 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 43 /* EnsomhetVarsel */, false, 0 }, 
                                   2, 
                                   { &ensomhetRune, &varselRune } };

const sSequence seq128 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 43 /* EnsomhetVarsel */, false, 0 }, 
                                   2, 
                                   { &ensomhetRune, &varselRune } };

const sSequence seq163 PROGMEM = { { 2, /* Kronien */ 55 /* SterkStyrke */, false, 0 }, 
                                   2, 
                                   { &sterkRune, &styrkeRune } };

const sSequence seq164 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 55 /* SterkStyrke */, false, 0 }, 
                                   2, 
                                   { &sterkRune, &styrkeRune } };

const sSequence seq168 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 57 /* VarselStans */, false, 0 }, 
                                   2, 
                                   { &varselRune, &stansRune } };

const sSequence seq169 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 57 /* VarselStans */, false, 0 }, 
                                   2, 
                                   { &varselRune, &stansRune } };

const sSequence seq170 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 57 /* VarselStans */, false, 0 }, 
                                   2, 
                                   { &varselRune, &stansRune } };

const sSequence seq173 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 58 /* VarselGrenselos */, false, 120 }, 
                                   2, 
                                   { &varselRune, &grenselosRune } };

const sSequence seq180 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 61 /* VarselStyrke */, false, 120 }, 
                                   2, 
                                   { &varselRune, &styrkeRune } };

const sSequence seq184 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 62 /* VarselFjell */, false, 0 }, 
                                   2, 
                                   { &varselRune, &fjellRune } };

const sSequence seq185 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 62 /* VarselFjell */, false, 0 }, 
                                   2, 
                                   { &varselRune, &fjellRune } };

const sSequence seq192 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 65 /* StansNod */, false, 0 }, 
                                   2, 
                                   { &stansRune, &nodRune } };

const sSequence seq197 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 66 /* StansStyrke */, false, 120 }, 
                                   2, 
                                   { &stansRune, &styrkeRune } };

const sSequence seq204 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 69 /* GrenselosNod */, false, 0 }, 
                                   2, 
                                   { &grenselosRune, &nodRune } };

const sSequence seq208 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Æthérique */ 70 /* GrenselosStyrke */, false, 0 }, 
                                   2, 
                                   { &grenselosRune, &styrkeRune } };

const sSequence seq209 PROGMEM = { { LEVEL_1, /* Divin */ 70 /* GrenselosStyrke */, false, 0 }, 
                                   2, 
                                   { &grenselosRune, &styrkeRune } };

const sSequence seq213 PROGMEM = { { 3, /* Æthérique */ 72 /* StorsaedNod */, false, 0 }, 
                                   2, 
                                   { &storsaedRune, &nodRune } };

const sSequence seq214 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Divin */ 72 /* StorsaedNod */, false, 0 }, 
                                   2, 
                                   { &storsaedRune, &nodRune } };

const sSequence seq218 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 73 /* StorsaedStyrke */, false, 120 }, 
                                   2, 
                                   { &storsaedRune, &styrkeRune } };

const sDirSequence sequencesDir1 PROGMEM = {
	14,
	{
		&seq1, &seq11, &seq14, &seq20, &seq29, &seq38, &seq53, &seq95, &seq128, &seq163, &seq168, &seq173, &seq197, &seq218
	}
};

const sDirSequence sequencesDir2 PROGMEM = {
	11,
	{
		&seq24, &seq66, &seq127, &seq164, &seq169, &seq180, &seq184, &seq192, &seq204, &seq208, &seq213
	}
};

const sDirSequence sequencesDir3 PROGMEM = {
	6,
	{
		&seq58, &seq126, &seq170, &seq185, &seq209, &seq214
	}
};

// Table of sequences by directory
const sDirSequence * const seq_dir[NB_DIRECTORY] PROGMEM = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
