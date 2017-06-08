#ifndef CUSTOM_TYPEDEF_H
#define CUSTOM_TYPEDEF_H

// nombre d'octet d'un tag rfid
#define UUID_TAG_SIZE 4

// nombre maximum d'item dans une sequence
#define MAX_SEQ_ITEM  3

// definit la fin de toute sequence a placer comme directory
#define END_OF_SEQUENCE_CONTINUE_DIR_ID  0xFE
#define END_OF_SEQUENCE_DISABLE_DIR_ID  0xFF


// define an item
typedef struct {
  const unsigned char nb_uid;
  const unsigned char *p_uid[UUID_TAG_SIZE];
}sItem;

// define a sequence result
typedef struct {
  const unsigned char sound_directory_id;
  const unsigned char sound_id;
}sResult;

// define a config sequence
typedef struct {
  const unsigned char nb_item;
  const sItem **p_items;
  const sResult *p_result;
}sSequence;

// define a config directory sequence
typedef struct {
  const unsigned char nb_seq;
  const sSequence *p_seq;
}sDirSequence;

// define a type for storing sequence in progress
typedef struct {
  unsigned char nb;
  unsigned char data[MAX_SEQ_ITEM][UUID_TAG_SIZE];
}sSeq;



#endif // CUSTOM_TYPEDEF_H
