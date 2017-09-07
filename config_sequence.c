#include "config_sequence.h"

const sItem * const seq237Runes[] PROGMEM = { &nodRune, &fjellRune };
#define SEQ_237_RUNES_SIZE (sizeof(seq237Runes)/sizeof(sItem*))
const sResult seq237Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 76 /* NodFjell */, false, 0 };
const sSequence seq237 = { SEQ_237_RUNES_SIZE, &seq237Runes, &seq237Result };

const sItem * const seq238Runes[] PROGMEM = { &nodRune, &styrkeRune };
#define SEQ_238_RUNES_SIZE (sizeof(seq238Runes)/sizeof(sItem*))
const sResult seq238Result = { END_OF_SEQUENCE_RESTART_ID, /* Kronien */ 75 /* NodStyrke */, false, 0 };
const sSequence seq238 = { SEQ_238_RUNES_SIZE, &seq238Runes, &seq238Result };

const sDirSequence sequencesDir1 = {
	2,
	{
		&seq237, &seq238
	}
};

const sDirSequence sequencesDir2 = {
	0,
	{

	}
};

const sDirSequence sequencesDir3 = {
	0,
	{

	}
};

// Table of sequences by directory
const sDirSequence *seq_dir[NB_DIRECTORY] = { &sequencesDir1, &sequencesDir2, &sequencesDir3 };
