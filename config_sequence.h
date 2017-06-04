#ifndef CONFIG_SEQUENCE_H
#define CONFIG_SEQUENCE_H

// son par defaut jouer lorsque aucune sequence ne correspond
#define DEFAULT_SOUND_ID 0x00000000


// define some structure
typedef struct {
  const unsigned char nb;
  const unsigned char *data[4];
}sUid;

typedef struct {
  const unsigned char nb;
  const sUid *data;
}sUidSeq;

// nombre d'octet d'un tag rfid
#define UUID_TAG_SIZE 4

// sequence table
#define SEQUENCE_SIZE 1
extern const sUidSeq sequence[SEQUENCE_SIZE];



#endif // CONFIG_SEQUENCE_H
