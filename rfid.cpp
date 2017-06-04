#include "rfid.hpp"


CRfid::CRfid( byte chipSelectPin, byte resetPowerDownPin )
{
  p_mfrc522 = new MFRC522(chipSelectPin, resetPowerDownPin);

  // init
  p_mfrc522->PCD_Init();   
  p_mfrc522->PCD_DumpVersionToSerial(); // debug  // init led IO

  //
  memset(previous_uid,0,UUID_TAG_SIZE);

}


byte *CRfid::GetNewCardId( void )
{
  byte *lo_new_card = NULL;

  if ( p_mfrc522->PICC_IsNewCardPresent()) 
  {     
    // Récupération des informations de la carte RFID   
    if ( p_mfrc522->PICC_ReadCardSerial()) 
    {    
      // Test la taille de l'uid, seul ceux de 4 octets sont accepter
      if( UUID_TAG_SIZE == p_mfrc522->uid.size ) 
      {
        // vérifie que ce ne soit pas la carte courante
        if( 0 != memcmp(previous_uid, p_mfrc522->uid.uidByte, UUID_TAG_SIZE) )
        {
          memcpy(previous_uid,p_mfrc522->uid.uidByte,UUID_TAG_SIZE);
          lo_new_card = previous_uid;
        }
      }
    }
  }

  return lo_new_card;
}

