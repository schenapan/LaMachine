

#include <SPI.h> 


#include "config_hardware.h"
#include "config_sequence.h"
#include "rfid.hpp"


/*************************************
 * Variables
 */
unsigned long old_time; // hold previous time
byte nuidPICC[UUID_TAG_SIZE];       // save previous rfid uid
byte seq_number; // numero de sequence qui match
byte seq_index; // progression dans la séquence

CRfid *p_rfid;

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

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  // clear leds
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);


  // init variables
  old_time = millis();
  for( byte loop=0; loop<UUID_TAG_SIZE; loop++ ) {
    nuidPICC[loop]=0;
  }
  seq_number = 0xFF;
  seq_index = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long comp_time; 
  byte *read_nuidPICC;

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
    printHex(read_nuidPICC,4);
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

/**
 * Helper to find a match inside a list of uid
 */
bool isEqual(sUid *ip_const_uid, byte i_read_uid[4])
{
  bool lo_result = false;

  for( int loop=0; loop<ip_const_uid->nb; loop++ )
  {
    if( 0 == memcmp(ip_const_uid->data, i_read_uid, 4) )
    {
      lo_result = true;
    }
  }

  return lo_result;
}



