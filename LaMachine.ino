

#include <SPI.h> 


#include "config_hardware.h"
#include "config_sequence.h"
#include "rfid.hpp"
#include "engine.hpp"


/*************************************
 * Variables
 */
unsigned long old_time; // hold previous time

sSeq in_seq;


CRfid *p_rfid;
CEngine seq_engine(seq_dir[0]);


/************************************
 * fonctions
 */

void setup() {
  // put your setup code here, to run once:

  // Init serial line for debug and needed by RFID library
  Serial.begin(9600);
  while (!Serial); 

  // Init SPI for RFID library
  SPI.begin(); 

  // Init RFID module
  p_rfid = new CRfid(SS_PIN, RST_PIN);

  // Led
  for( int loop=0; loop<NB_LED; loop++ )
  {
    pinMode(led_tbl[loop], OUTPUT); 
    digitalWrite(led_tbl[loop], HIGH); 
  }

  // init variables
  old_time = millis();
  in_seq.nb = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long comp_time; 
  byte *read_nuidPICC;
  sResult *seq_result;

  // 1second ticks
  comp_time = (unsigned long)( millis() - old_time );
  if( comp_time > 1000 )
  {
    old_time += 1000;
    
//    digitalWrite(GREEN_LED, green_led_state);
//    if( HIGH == green_led_state ){ green_led_state = LOW; }
//    else{ green_led_state = HIGH; }

    
    //Serial.print("Time: ");
    //prints time since program started
    //Serial.println(old_time);    
  }
  
  // Attente d'une carte RFID 
  read_nuidPICC = p_rfid->GetNewCardId();
  if( NULL != read_nuidPICC )
  {
    printHex(read_nuidPICC,UUID_TAG_SIZE);

    // ajoute le nouvel id
    if( in_seq.nb < MAX_SEQ_ITEM )
    {
      memcpy(in_seq.data[in_seq.nb], read_nuidPICC, UUID_TAG_SIZE);
      in_seq.nb += 1;
    }

    // test si la nouvelle sequence est valide et retourne un résultat si il existe
    if( true == seq_engine.IsSequenceValid( &in_seq, seq_result ) )
    {
      // a valid sequence is found 
      // update LED
      if( in_seq.nb <= NB_LED )
      {
        digitalWrite(led_tbl[in_seq.nb-1], LOW); 
      }

      //debug 
      Serial.print("sequence nb : ");
      printHex(&(in_seq.nb),1);
      
      // check if a result exist
      if( NULL != seq_result )
      {
        // play sound

        // switch to next directory
        switch( seq_result->sound_directory_id )
        {
          case END_OF_SEQUENCE_CONTINUE_DIR_ID:
          {
            // end of current sequence with success
            
          }
          break;

          case END_OF_SEQUENCE_DISABLE_DIR_ID:
          {
            // disable machine final ending

          }
          break;

          default:
          {
            // switch to new directory
            if( seq_result->sound_directory_id < NB_DIRECTORY )
            {
              seq_engine.SetDirectorySequence(seq_dir[seq_result->sound_directory_id]);
            }
          }
          break;
        }
      }
    }
    else
    {
      // invlid sequence
    }
  }
  else
  {
    // manage timeout
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



