#include <SPI.h>
#include <SoftwareSerial.h>
#include <MP3Player_KT403A.h>


#include "config_hardware.h"
#include "config_sequence.h"
#include "rfid.hpp"
#include "engine.hpp"


/*************************************
 * Variables
 */
unsigned long old_time; // hold previous time
unsigned long old_tick; // hold previous time for 1s tick

bool wait_timeout_flag;
bool disable_machine;
bool disable_timer;


sSeq in_seq;
unsigned char current_directory;


CRfid *p_rfid;
CEngine seq_engine(seq_dir[0], &items_table);

// Note: You must define a SoftwareSerial class object that the name must be mp3, 
//       but you can change the pin number according to the actual situation.$
#ifndef NO_MP3_HARDWARE    
  SoftwareSerial mp3(MP3_SOFT_TX_PIN, MP3_SOFT_RX_PIN);
#endif


/************************************
 * fonctions
 */

void setup() {
    // put your setup code here, to run once:

    // Init MP3
#ifndef NO_MP3_HARDWARE    
    mp3.begin(MP3_UART_SPEED);
    delay(100);
#endif

    // Init serial line for debug and needed by RFID library
    Serial.begin(9600);
    while (!Serial);

    // Init SPI for RFID library
    SPI.begin();

    // Init RFID module
    p_rfid = new CRfid(SS_PIN, RST_PIN);

    // Led
    initLeds();

    // init variables
    old_time = millis();
    old_tick = millis();
    in_seq.nb = 0;

    wait_timeout_flag = false;
    disable_machine = false;
    disable_timer = false;
    current_directory = 1;

    // configure MP3
#ifndef NO_MP3_HARDWARE    
    delay(100);
    SelectPlayerDevice(MP3_DEFAULT_DEVICE);       // Select SD card as the player device.
    delay(100);
    SetVolume(MP3_DEFAULT_SOUND_LEVEL);                // Set the volume, the range is 0x00 to 0x1E.
#endif

    // init config counter to 0
    for( unsigned char seq_dir_loop =0; seq_dir_loop<NB_DIRECTORY; seq_dir_loop++ )
    {
      for( unsigned char seq_item_loop=0; seq_item_loop<seq_dir[seq_dir_loop]->nb_seq; seq_item_loop++ )
      {
        seq_dir[seq_dir_loop]->p_seq[seq_item_loop]->p_result->lock_timer_counter = 0;
      }
    }


    //debug display items table
#ifdef DEBUG_PRINT
    sItemTbl *p_items_tbl = &items_table;
    Serial.print(F("Nb Item : "));
    unsigned char nb_items = pgm_read_byte(p_items_tbl + offsetof(sItemTbl, nb_items));
    printHex(&nb_items,1);
    for( unsigned char loop=0; loop<nb_items; loop++)
    {
      Serial.print(F("Item : "));
      printHex(&loop,1);

      Serial.print(F("Nb UID : "));
      unsigned char nb_uuid;
      unsigned short p_item = pgm_read_ptr(p_items_tbl + offsetof(sItemTbl, p_items) + (sizeof(sItem*)*loop));
      nb_uuid = pgm_read_byte(p_item + offsetof(sItem, nb_uid));      
      printHex(&nb_uuid,1);
      for( unsigned char uid_loop=0; uid_loop<nb_uuid; uid_loop++ )
      {        
        t_tag l_tag;
        unsigned short p_tag = pgm_read_ptr(p_item + offsetof(sItem, p_uid));
        memcpy_P(l_tag, p_tag + (UUID_TAG_SIZE*uid_loop), UUID_TAG_SIZE);
        printHex(l_tag,UUID_TAG_SIZE);
        
      }
    }

    //while(1);
     
#endif    
}

void loop() {
    // put your main code here, to run repeatedly:
    unsigned long comp_time;
    byte *read_nuidPICC;
    sResult *seq_result;

    // Attente d'une carte RFID
    read_nuidPICC = NULL;
    if (!disable_machine) {
        if (!wait_timeout_flag) {
            read_nuidPICC = p_rfid->GetNewCardId();
      }
    }
    if (NULL != read_nuidPICC) {
        sItem *lp_item;

        Serial.print(F("TAG : "));
        printHex(read_nuidPICC, UUID_TAG_SIZE);

        // convertit en item
        lp_item = seq_engine.GetItem(read_nuidPICC);
        if (NULL == lp_item) {
            // Wrong TAG
            // que doit on faire ?

            Serial.println(F("Wrong TAG"));

#ifndef NO_MP3_HARDWARE    
            SpecifyfolderPlay(99, 002);

            // wait end of read
            while (QueryPlayStatus() != 0);
#endif

            clearSeqAndLeds();
        } else {
            bool is_item_added = false;

            // repousse le temps
            old_time = millis();

            // ajoute le nouvel item
            if (in_seq.nb < MAX_SEQ_ITEM) {
                if (in_seq.p_item[in_seq.nb - 1] != lp_item) {
                    in_seq.p_item[in_seq.nb] = lp_item;
                    in_seq.nb += 1;
                    is_item_added = true;
                    Serial.print(F("Add in seq : "));
                    printHex(&(in_seq.nb), 1);
                }
            }

            if (true == is_item_added) {
                // test si la nouvelle sequence est valide et retourne un résultat si il existe

                /***/
                // DEBUG
#ifdef DEBUG_PRINT                
                Serial.println(F("in_seq[0], OrgaRune : "));
                unsigned short l_tmp_ptr;
                l_tmp_ptr = (unsigned short)in_seq.p_item[0];
                printHex((byte*)&l_tmp_ptr, 2);
                l_tmp_ptr = (unsigned short)&varselRune;
                printHex((byte*)&l_tmp_ptr, 2);
                l_tmp_ptr = (unsigned short)&ensomhetRune;
                printHex((byte*)&l_tmp_ptr, 2);
                l_tmp_ptr = (unsigned short)&styrkeRune;
                printHex((byte*)&l_tmp_ptr, 2);
                l_tmp_ptr = (unsigned short)&stansRune;
                printHex((byte*)&l_tmp_ptr, 2);
                l_tmp_ptr = (unsigned short)&orgaRune;
                printHex((byte*)&l_tmp_ptr, 2);
#endif
                /***/
                
                if (true == seq_engine.IsSequenceValid(&in_seq, &seq_result)) {
                    // a valid sequence is found
                    // update LED
                    if (in_seq.nb <= NB_LED) {
                        digitalWrite(led_tbl[in_seq.nb - 1], LED_LEVEL_ON);
                    }

                    // check if a result exist
                    if ((NULL != seq_result) && (0 == seq_result->lock_timer_counter)) {
                        // play sound

                        Serial.println(F("Sequence Valide"));

                        seq_result->lock_timer_counter = seq_result->lock_timer_reload_value;

                        if (0xFF != current_directory) {

                            // enable relay if needed
                            if( true == seq_result->enable_relay )
                            {
                              Serial.println(F("Enable Relay"));
                              digitalWrite(EXT_RELAY_PIN, HIGH);
                              delay(EXT_RELAY_DELAY_MS);
                              digitalWrite(EXT_RELAY_PIN, LOW);
                            }

                          
                            Serial.println(F("Play : "));
                            Serial.print(F("directory : "));
                            printHex(&current_directory, 1);
                            Serial.print(F("sound : "));
                            printHex(&(seq_result->sound_id), 1);

#ifndef NO_MP3_HARDWARE    
                            SpecifyfolderPlay(current_directory, seq_result->sound_id);

                            // wait end of read
                            while (QueryPlayStatus() != 0);
#endif
                        }

                        // switch to next directory
                        switch (seq_result->next_sound_directory_id) {
                            case END_OF_SEQUENCE_RESTART_ID: {
                                // end of current sequence with success
                                Serial.println(F("Finie et re-initialise la machine"));

                                seq_engine.SetDirectorySequence(seq_dir[0]);
                                current_directory = 1;

                                wait_timeout_flag = true;
                            }
                                break;

                            case END_OF_SEQUENCE_CONTINUE_DIR_ID: {
                                // end of current sequence with success
                                Serial.println(F("Finie et continue dans le même repertoire"));

                                current_directory = 0xFF;

                                wait_timeout_flag = true;
                            }
                                break;

                            case END_OF_SEQUENCE_DISABLE_DIR_ID: {
                                // disable machine final ending
                                Serial.println(F("Finie et désactive la machine"));

                                current_directory = 0xFF;

                                disable_machine = true;
                                wait_timeout_flag = true;
                            }
                                break;

                            default: {
                                // switch to new directory
                                Serial.println(F("Finie et continue dans un nouveau répertoire"));

                                if (seq_result->next_sound_directory_id <= NB_DIRECTORY) {
                                    seq_engine.SetDirectorySequence(seq_dir[seq_result->next_sound_directory_id - 1]);
                                    current_directory = seq_result->next_sound_directory_id;
                                }

                                wait_timeout_flag = true;
                            }
                                break;
                        }
                    }
                    else
                    {
                      // cooldown : UNIQUEMENT SI LA SEQUENCE EST VALIDE ET SOUS LOCK !!!
                      if ((NULL != seq_result) && (0 != seq_result->lock_timer_counter)) 
                      {
                      
                        Serial.println(F("Cooldown"));

#ifndef NO_MP3_HARDWARE    
                        switch( random(3) ) // argument is max exclusive value of random ie: if 3, return number 0,1,2
                        {
                          case 0:
                          case 1:
                          case 2:
                          default:
                            SpecifyfolderPlay(99, 001);
                          break;
                        }
  
                        // wait end of read
                        while (QueryPlayStatus() != 0);
#endif
                        wait_timeout_flag = true;
                      }
                    }
                } 
                else 
                {
                    // invlid sequence

                    Serial.println(F("Mauvaise séquence"));

#ifndef NO_MP3_HARDWARE    
                    switch( random(3) ) // argument is max exclusive value of random ie: if 3, return number 0,1,2
                    {
                      case 0:
                      case 1:
                      case 2:
                      default:
                        SpecifyfolderPlay(99, 001);
                      break;
                    }

                    // wait end of read
                    while (QueryPlayStatus() != 0);
#endif

                    wait_timeout_flag = true;
                }
            }
        }
    }

    // manage timeout
    if (!disable_timer) {
        comp_time = (unsigned long) (millis() - old_time);
        if (comp_time > 5000) 
        {
            // desactive la machine
            clearSeqAndLeds();
            wait_timeout_flag = false;
            if (disable_machine) 
            {
                disable_timer = true;
            }

            // sequence incomplète

        }
    }

    // 1s tick
    if (((unsigned long) (millis() - old_tick)) > 1000) 
    {
      old_tick += 1000;
      
      for( unsigned char seq_dir_loop =0; seq_dir_loop<NB_DIRECTORY; seq_dir_loop++ )
      {
        for( unsigned char seq_item_loop=0; seq_item_loop<seq_dir[seq_dir_loop]->nb_seq; seq_item_loop++ )
        {
          if( 0 != seq_dir[seq_dir_loop]->p_seq[seq_item_loop]->p_result->lock_timer_counter )
          {
            seq_dir[seq_dir_loop]->p_seq[seq_item_loop]->p_result->lock_timer_counter -= 1;
          }
        }
      }     
    }
}

/**
* Helper routine to dump a byte array as hex values to Serial.
*/
void printHex(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
    Serial.println("");
}

void initLeds(void) {
    for (int loop = 0; loop < NB_LED; loop++) {
        pinMode(led_tbl[loop], OUTPUT);
        digitalWrite(led_tbl[loop], LED_LEVEL_OFF);
    }
}

void clearSeqAndLeds(void) {
    for (int loop = 0; loop < NB_LED; loop++) {
        digitalWrite(led_tbl[loop], LED_LEVEL_OFF);
    }

    in_seq.nb = 0;

    p_rfid->ClearPrevious();
}


