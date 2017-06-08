#ifndef CONFIG_SEQUENCE_H
#define CONFIG_SEQUENCE_H

#include "custom_typedef.h"

// son par defaut jouer lorsque aucune sequence ne correspond
#define DEFAULT_SOUND_ID 0x00000000

/**
 * export table of sequence, indice of table is same as directory
 */
#define NB_DIRECTORY  1
extern const sDirSequence *seq_dir[NB_DIRECTORY];


#endif // CONFIG_SEQUENCE_H
