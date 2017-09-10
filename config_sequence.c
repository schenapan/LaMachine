#include "config_sequence.h"

//const sItem * const seq237Runes[] PROGMEM = { &nodRune, &fjellRune };
//#define SEQ_237_RUNES_SIZE (sizeof(seq237Runes)/sizeof(sItem*))
//const sResult seq237Result PROGMEM = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 76 /* NodFjell */, false, 0 };
//const sSequence seq237 PROGMEM = { &seq237Result, SEQ_237_RUNES_SIZE, seq237Runes };
const sSequence seq237 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 76 /* NodFjell */, false, 0 }, 
                                   2, 
                                   { &nodRune, &fjellRune } };

//const sItem * const seq238Runes[] PROGMEM = { &nodRune, &varselRune, &styrkeRune };
//#define SEQ_238_RUNES_SIZE (sizeof(seq238Runes)/sizeof(sItem*))
//const sResult seq238Result PROGMEM = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 75 /* NodStyrke */, false, 0 };
//const sSequence seq238 PROGMEM = { &seq238Result, SEQ_238_RUNES_SIZE, seq238Runes };
const sSequence seq238 PROGMEM = { { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 75 /* NodStyrke */, false, 0 }, 
                                   3, 
                                   { &nodRune, &varselRune, &styrkeRune } };

const sDirSequence sequencesDir1 PROGMEM = {
	2,
	{
		&seq237, &seq238
	}
};

const sDirSequence sequencesDir2 PROGMEM = {
	0,
	{

	}
};

const sDirSequence sequencesDir3 PROGMEM = {
	0,
	{

	}
};

// Table of sequences by directory
const sDirSequence * const seq_dir[NB_DIRECTORY] PROGMEM = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
