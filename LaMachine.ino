

#include <SPI.h> 


#include "config_hardware.h"
#include "config_sequence.h"
#include "rfid.hpp"
#include "engine.hpp"


/*************************************
 * Variables
 */
unsigned long old_time; // hold previous time

bool wait_timeout_flag;
bool disable_machine;
bool disable_timer;


sSeq in_seq;


CRfid *p_rfid;
CEngine seq_engine(seq_dir[0],&items_table);


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
  initLeds();

  // init variables
  old_time = millis();
  in_seq.nb = 0;

  wait_timeout_flag = false;
  disable_machine = false;
  disable_timer = false;

  


  //debug display items table
/*  
  Serial.print("Nb Item : ");
  printHex(&(items_table.nb_items),1);
  for( unsigned char loop=0; loop<items_table.nb_items; loop++)
  {
    Serial.print("Item : ");
    printHex(&loop,1);

    Serial.print("Nb UID : ");
    printHex(&(items_table.p_items[loop]->nb_uid),1);
    for( unsigned char uid_loop=0; uid_loop<items_table.p_items[loop]->nb_uid; uid_loop++ )
    {
      printHex(items_table.p_items[loop]->p_uid[uid_loop],UUID_TAG_SIZE);
    }
  }
*/  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long comp_time; 
  byte *read_nuidPICC;
  sResult *seq_result;

  // Attente d'une carte RFID 
  read_nuidPICC = NULL;
  if( !disable_machine )
  {
    if( !wait_timeout_flag )
    {
      read_nuidPICC = p_rfid->GetNewCardId();
    }
  }
  if( NULL != read_nuidPICC )
  {
    sItem *lp_item;
    
    printHex(read_nuidPICC,UUID_TAG_SIZE);

    // convertit en item
    lp_item = seq_engine.GetItem( read_nuidPICC );
    if( NULL == lp_item )
    {
      // Wrong TAG
      // que doit on faire ?

      Serial.print("Wrong TAG");

      clearSeqAndLeds();
    }
    else
    {
      // repousse le temps
      old_time = millis();
     
      // ajoute le nouvel item
      if( in_seq.nb < MAX_SEQ_ITEM )
      {
        in_seq.p_item[in_seq.nb] = lp_item;
        in_seq.nb += 1;
        Serial.print("Add in seq : ");
        printHex(&(in_seq.nb),1);
      }


      // test si la nouvelle sequence est valide et retourne un résultat si il existe
      if( true == seq_engine.IsSequenceValid( &in_seq, &seq_result ) )
      {
        // a valid sequence is found 
        // update LED
        if( in_seq.nb <= NB_LED )
        {
          digitalWrite(led_tbl[in_seq.nb-1], LOW); 
        }
  
        // check if a result exist
        if( NULL != seq_result )
        {
          // play sound

          Serial.println("Sequence Valide");
  
          // switch to next directory
          switch( seq_result->sound_directory_id )
          {
            case END_OF_SEQUENCE_CONTINUE_DIR_ID:
            {
              // end of current sequence with success
              Serial.println("Finie et continue dans le même repertoire");

              wait_timeout_flag = true;
            }
            break;
  
            case END_OF_SEQUENCE_DISABLE_DIR_ID:
            {
              // disable machine final ending
              Serial.println("Finie et désactive la machine");
              
              disable_machine = true;
              wait_timeout_flag = true;
            }
            break;
  
            default:
            {
              // switch to new directory
              Serial.println("Finie et continue dans un nouveau répertoire");
              
              if( seq_result->sound_directory_id < NB_DIRECTORY )
              {
                seq_engine.SetDirectorySequence(seq_dir[seq_result->sound_directory_id]);
              }

              wait_timeout_flag = true;
            }
            break;
          }
        }
      }
      else
      {
        // invlid sequence

        Serial.println("Mauvaise séquence");

        wait_timeout_flag = true;
      }
    }
  }

  // manage timeout
  if( !disable_timer )
  {
    comp_time = (unsigned long)( millis() - old_time );
    if( comp_time > 3000 )
    {
      // desactive la machine
      clearSeqAndLeds();
      wait_timeout_flag = false;
      if( disable_machine )
      {
        disable_timer = true;
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

void initLeds( void )
{
  for( int loop=0; loop<NB_LED; loop++ )
  {
    pinMode(led_tbl[loop], OUTPUT); 
    digitalWrite(led_tbl[loop], HIGH); 
  }
}

void clearSeqAndLeds( void )
{
  for( int loop=0; loop<NB_LED; loop++ )
  {
    digitalWrite(led_tbl[loop], HIGH); 
  }
  
  in_seq.nb = 0;

  p_rfid->ClearPrevious();
}


