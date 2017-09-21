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

sCoolDownElmt cooldown_tbl[MAX_COOLDOWN_TBL_SIZE];

sSeq in_seq;
unsigned char current_directory;

CRfid *p_rfid;
CEngine seq_engine(0, &items_table);

// Note: You must define a SoftwareSerial class object that the name must be mp3, 
//       but you can change the pin number according to the actual situation.$
#ifndef NO_MP3_HARDWARE    
SoftwareSerial mp3(MP3_SOFT_TX_PIN, MP3_SOFT_RX_PIN);
#endif

/************************************
 * fonctions
 */

void setup()
{
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

  // init engine
  seq_engine.SetDirectorySequence(pgm_read_ptr(&seq_dir[0]));

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
  for (unsigned short loop = 0; loop < MAX_COOLDOWN_TBL_SIZE; loop++)
  {
    cooldown_tbl[loop].p_seq = NULL;
    cooldown_tbl[loop].minute_counter = 0;
  }

  //debug display items table
#ifdef DEBUG_PRINT_CONFIG_ITEMS
  sItemTbl *p_items_tbl = &items_table;
  Serial.print(F("Nb Item : "));
  unsigned char nb_items = pgm_read_byte(p_items_tbl + offsetof(sItemTbl, nb_items));
  printHex(&nb_items,1);
  for( unsigned char loop=0; loop<nb_items; loop++)
  {
    Serial.print(F("Item : "));
    printHex(&loop,1);

    unsigned char nb_uuid;
    unsigned short p_item = pgm_read_ptr(p_items_tbl + offsetof(sItemTbl, p_items) + (sizeof(sItem*)*loop));
    printHex((unsigned char*)&p_item,2);
    nb_uuid = pgm_read_byte(p_item + offsetof(sItem, nb_uid));
    Serial.print(F("Nb UID : "));
    printHex(&nb_uuid,1);
    for( unsigned char uid_loop=0; uid_loop<nb_uuid; uid_loop++ )
    {
      t_tag l_tag;
      unsigned short p_tag = pgm_read_ptr(p_item + offsetof(sItem, p_uid));
      memcpy_P(l_tag, p_tag + (UUID_TAG_SIZE*uid_loop), UUID_TAG_SIZE);
      printHex(l_tag,UUID_TAG_SIZE);

    }
  }
#endif    

#ifdef DEBUG_PRINT_CONFIG_SEQ

  for(unsigned char seq_dir_loop=0; seq_dir_loop<NB_DIRECTORY; seq_dir_loop++ )
  {
    Serial.print(F("Seq dir : "));
    printHex(&seq_dir_loop,1);

    unsigned short lp_seq_dir = pgm_read_ptr(&seq_dir[seq_dir_loop]);
    unsigned char l_nb_sequence = pgm_read_byte(lp_seq_dir + offsetof(sDirSequence, nb_seq));
    Serial.print(F("nb sequence : "));
    printHex(&l_nb_sequence,1);

    for( unsigned char seq_loop=0; seq_loop<l_nb_sequence; seq_loop++ )
    {
      Serial.print(F("Seq : "));
      printHex(&seq_loop,1);

      unsigned short lp_seq = pgm_read_ptr(&(((sDirSequence*)lp_seq_dir)->p_seq[seq_loop]));
      unsigned char l_nb_item = pgm_read_byte(&(((sSequence*)lp_seq)->nb_item));
      Serial.print(F("nb items : "));
      printHex(&l_nb_item,1);

      for( unsigned char item_loop=0; item_loop<l_nb_item; item_loop++ )
      {
        Serial.print(F("Item : "));
        printHex(&item_loop,1);

        unsigned short lp_item = pgm_read_ptr(&((sSequence*)lp_seq)->p_items[item_loop]);
        printHex((unsigned char *)&lp_item,2);
      }
    }
  }

#endif

}

void loop()
{
  // put your main code here, to run repeatedly:
  unsigned long comp_time;
  byte *read_nuidPICC;
  sSequence *seq_result;

  // Attente d'une carte RFID
  read_nuidPICC = NULL;
  if (!disable_machine && !wait_timeout_flag)
  {
    read_nuidPICC = p_rfid->GetNewCardId();
  }

  if (NULL != read_nuidPICC)
  {
    sItem *lp_item;

    Serial.print(F("TAG : "));
    printHex(read_nuidPICC, UUID_TAG_SIZE);

    // convertit en item
    lp_item = seq_engine.GetItem(read_nuidPICC);
    if (NULL == lp_item)
    {
      // Wrong TAG
      // que doit on faire ?

      Serial.println(F("Wrong TAG"));

#ifndef NO_MP3_HARDWARE    
      SpecifyfolderPlay(99, 002);

      // wait end of read
      while (QueryPlayStatus() != 0);
#endif

      clearSeqAndLeds();
    }
    else
    {
      bool is_item_added = false;

      // ajoute le nouvel item
      if (in_seq.nb < MAX_SEQ_ITEM)
      {
        if (in_seq.nb == 0 || (in_seq.p_item[in_seq.nb - 1] != lp_item))
        {
          in_seq.p_item[in_seq.nb] = lp_item;
          in_seq.nb += 1;
          is_item_added = true;
          Serial.print(F("Add in seq : "));
          printHex(&(in_seq.nb), 1);
        }
      }

      if (true == is_item_added)
      {
        // test si la nouvelle sequence est valide et retourne un résultat si il existe
        if (true == seq_engine.IsSequenceValid(&in_seq, &seq_result))
        {
          // a valid sequence is found
          // update LED
          if (in_seq.nb <= NB_LED)
          {
            digitalWrite(led_tbl[in_seq.nb - 1], LED_LEVEL_ON);
          }

          // check if a result exist
          if (NULL != seq_result)
          {
            if (0 == getCooldownCounter(seq_result))
            {
              // play sound

              Serial.println(F("Sequence Valide"));

              setCooldownCounter(seq_result, pgm_read_byte(&seq_result->result.lock_timer_reload_value));

              if (0xFF != current_directory)
              {

                // enable relay if needed
                if (true == pgm_read_byte(&seq_result->result.enable_relay))
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
                unsigned char l_sound_id = pgm_read_byte(&seq_result->result.sound_id);
                printHex(&l_sound_id, 1);

#ifndef NO_MP3_HARDWARE    
                SpecifyfolderPlay(current_directory, l_sound_id);

                // wait end of read
                while (QueryPlayStatus() != 0);
#endif
              }

              // switch to next directory
              unsigned char l_next_sound_dir = pgm_read_byte(&seq_result->result.next_sound_directory_id);
              switch (l_next_sound_dir)
              {
              case END_OF_SEQUENCE_RESTART_ID:
                // end of current sequence with success
                Serial.println(F("Finie et re-initialise la machine"));

                seq_engine.SetDirectorySequence(pgm_read_ptr(&seq_dir[0]));
                current_directory = 1;
                break;

              case END_OF_SEQUENCE_CONTINUE_DIR_ID:
                // end of current sequence with success
                Serial.println(F("Finie et continue dans le même repertoire"));

                current_directory = 0xFF;
                break;

              case END_OF_SEQUENCE_DISABLE_DIR_ID:
                // disable machine final ending
                Serial.println(F("Finie et désactive la machine"));

                current_directory = 0xFF;

                disable_machine = true;
                break;

              default:
                // switch to new directory
                Serial.print(F("Finie et continue dans un nouveau répertoire"));
                printHex(&l_next_sound_dir, 1);

                if (l_next_sound_dir <= NB_DIRECTORY)
                {
                  current_directory = l_next_sound_dir;
                  seq_engine.SetDirectorySequence(pgm_read_ptr(&seq_dir[l_next_sound_dir - 1]));
                }
              }
            }
            else
            {
              // cooldown : UNIQUEMENT SI LA SEQUENCE EST VALIDE ET SOUS LOCK !!!
              Serial.println(F("Cooldown"));

#ifndef NO_MP3_HARDWARE    
              switch (random(3))
              // argument is max exclusive value of random ie: if 3, return number 0,1,2
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
            }
            wait_timeout_flag = true;
          }
        }
        else
        {
          // invlid sequence

          Serial.println(F("Mauvaise séquence"));

#ifndef NO_MP3_HARDWARE    
          switch (random(3))
          // argument is max exclusive value of random ie: if 3, return number 0,1,2
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
      // repousse le temps
      old_time = millis();
    }
  }

  // manage timeout
  if (!disable_timer)
  {
    comp_time = (unsigned long) (millis() - old_time);
    if (comp_time > 5000)
    {
      // sequence incomplète
      clearSeqAndLeds();
      wait_timeout_flag = false;
      if (disable_machine)
      {
      // desactive la machine
        disable_timer = true;
      }
    }
  }

  // 1s tick
  if (((unsigned long) (millis() - old_tick)) > 60000UL)
  {
    old_tick += 60000UL;

    for (unsigned short loop = 0; loop < MAX_COOLDOWN_TBL_SIZE; loop++)
    {
      if (0 != cooldown_tbl[loop].minute_counter)
      {
        cooldown_tbl[loop].minute_counter -= 1;
      }
    }
  }
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void printHex(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
  Serial.println("");
}

void initLeds(void)
{
  for (int loop = 0; loop < NB_LED; loop++)
  {
    pinMode(led_tbl[loop], OUTPUT);
    digitalWrite(led_tbl[loop], LED_LEVEL_OFF);
  }
}

void clearSeqAndLeds(void)
{
  for (int loop = 0; loop < NB_LED; loop++)
  {
    digitalWrite(led_tbl[loop], LED_LEVEL_OFF);
  }

  in_seq.nb = 0;

  p_rfid->ClearPrevious();
}

unsigned char getCooldownCounter(unsigned short i_seq_ptr)
{
  unsigned char r_value = 0;

  for (unsigned short loop = 0; loop < MAX_COOLDOWN_TBL_SIZE; loop++)
  {
    if (cooldown_tbl[loop].p_seq == i_seq_ptr)
    {
      r_value = cooldown_tbl[loop].minute_counter;
      loop = MAX_COOLDOWN_TBL_SIZE;
    }
  }

  return r_value;
}

void setCooldownCounter(unsigned short i_seq_ptr, unsigned char i_value)
{
  unsigned char l_low_value = 0xFF;
  unsigned short l_low_idx = 0;

  for (unsigned short loop = 0; loop < MAX_COOLDOWN_TBL_SIZE; loop++)
  {
    // update low value
    if (cooldown_tbl[loop].minute_counter < l_low_value)
    {
      l_low_value = cooldown_tbl[loop].minute_counter;
      l_low_idx = loop;
    }

    if (0 == cooldown_tbl[loop].minute_counter)
    {
      cooldown_tbl[loop].p_seq = i_seq_ptr;
      cooldown_tbl[loop].minute_counter = i_value;
      loop = MAX_COOLDOWN_TBL_SIZE;
    }
  }

  if (0 != l_low_value)
  {
    // il n'y a plus de place dans le tableau on ecrase la plus petite valeur
    cooldown_tbl[l_low_idx].p_seq = i_seq_ptr;
    cooldown_tbl[l_low_idx].minute_counter = i_value;
  }

}

