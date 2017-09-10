#include "rfid.hpp"

#include "config_hardware.h"

CRfid::CRfid(byte chipSelectPin, byte resetPowerDownPin) {
#ifndef NO_RFID_HARDWARE
    p_mfrc522 = new MFRC522(chipSelectPin, resetPowerDownPin);

    // init
    p_mfrc522->PCD_Init();
    p_mfrc522->PCD_DumpVersionToSerial(); // debug  // init led IO
#endif
    //
    ClearPrevious();
}

byte *CRfid::GetNewCardId(void) {
    byte *lo_new_card = NULL;
#ifndef NO_RFID_HARDWARE
    if (p_mfrc522->PICC_IsNewCardPresent()) {
        // Récupération des informations de la carte RFID
        if (p_mfrc522->PICC_ReadCardSerial()) {
            // Test la taille de l'uid, seul ceux de 4 octets sont accepter
            if (UUID_TAG_SIZE == p_mfrc522->uid.size) {
                // vérifie que ce ne soit pas la carte courante
                if (0 != memcmp(previous_uid, p_mfrc522->uid.uidByte, UUID_TAG_SIZE)) {
                    memcpy(previous_uid, p_mfrc522->uid.uidByte, UUID_TAG_SIZE);
                    lo_new_card = previous_uid;
                }
            }
        }
    }
#else
  // debug
  static unsigned long dbg_time = millis();
  static unsigned char count = 3;

  if( ((unsigned long)(millis() - dbg_time)) > 5000 )
  {
    dbg_time += 5000; 
  
    if( 0 == count )
    {
  		// Nod - TAG_17 {0x85, 0x6D, 0xB6, 0x3B}
  		previous_uid[0] = 0x85;
  		previous_uid[1] = 0x6D;
  		previous_uid[2] = 0xB6;
  		previous_uid[3] = 0x3B;
  		lo_new_card = previous_uid;
      count += 1;
      count = 0xFE;
    }
    else if( 1 == count )
    {
      // Varsel - TAG_1 {0x41, 0x6C, 0x04, 0x6B}
      previous_uid[0] = 0x41;
      previous_uid[1] = 0x6C;
      previous_uid[2] = 0x04;
      previous_uid[3] = 0x6B;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if( 2 == count )
    {
      // Styrke - TAG_5 {0x36, 0x61, 0x8D, 0xBB}
      previous_uid[0] = 0x36;
      previous_uid[1] = 0x61;
      previous_uid[2] = 0x8D;
      previous_uid[3] = 0xBB;
      lo_new_card = previous_uid;
      count += 1;
    }
    else
    {
      count += 1;
    }
    
  }
#endif
    return lo_new_card;
}

void CRfid::ClearPrevious(void) {
    memset(previous_uid, 0, UUID_TAG_SIZE);
}
