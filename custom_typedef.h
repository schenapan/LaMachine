#ifndef CUSTOM_TYPEDEF_H
#define CUSTOM_TYPEDEF_H

// nombre d'octet d'un tag rfid
#define UUID_TAG_SIZE 4


// define an item
typedef struct {
  const unsigned char nb_uid;
  const unsigned char *p_uid[UUID_TAG_SIZE];
}sItem;


// define a config sequence
typedef struct {
  const unsigned char nb_item;
  const sItem *p_items;
}sItemSequence;


// define a config result of sequence
typedef struct {
  const unsigned char sound_directory_number;
  const unsigned char sound_number;
}sResult;

// define a config sequence
typedef struct {
  const sUidSequence *p_item_seq;
  const sResult *p_result;
}sSequence;

// define a config directory sequence
typedef struct {
  const unsigned char nb_seq;
  const sSequence *p_seq;
}sDirSequence;

#endif // CUSTOM_TYPEDEF_H
