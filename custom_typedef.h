#ifndef CUSTOM_TYPEDEF_H
#define CUSTOM_TYPEDEF_H

#include <stdbool.h>
#include <avr/pgmspace.h>

// nombre d'octet d'un tag rfid
#define UUID_TAG_SIZE 4

// nombre maximum d'item dans une sequence
#define MAX_SEQ_ITEM  3

// definit la fin de toute sequence a placer comme directory
#define END_OF_SEQUENCE_RESTART_ID        0xFD
#define END_OF_SEQUENCE_CONTINUE_DIR_ID   0xFE
#define END_OF_SEQUENCE_DISABLE_DIR_ID    0xFF

// define a tag
typedef unsigned char t_tag[UUID_TAG_SIZE];

// define an item
typedef struct {
    const unsigned char nb_uid;
    const t_tag *p_uid;
} sItem;

// define an items table
typedef struct {
    const unsigned char nb_items;
    const sItem * const p_items[];
} sItemTbl;

// define a sequence result
typedef struct {
    const unsigned char next_sound_directory_id; // special define to stop machine
    const unsigned char sound_id;
    const bool enable_relay; // true for enable relay
    const unsigned short lock_timer_reload_value; // default time to wait before apply again this result
//    unsigned short lock_timer_counter; 
} sResult;

// define a config sequence
typedef struct {
    sResult result;
    const unsigned char nb_item;
    const sItem * const p_items[];
} sSequence;

// define a config directory sequence
typedef struct {
    const unsigned char nb_seq;
    const sSequence * const p_seq[];
} sDirSequence;

// define a type for storing sequence in progress
typedef struct {
    unsigned char nb;
    sItem *p_item[MAX_SEQ_ITEM];
} sSeq;


#endif // CUSTOM_TYPEDEF_H
