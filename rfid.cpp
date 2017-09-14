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
  static unsigned char count = 0;

  if( ((unsigned long)(millis() - dbg_time)) > 5000 )
  {
    dbg_time += 5000; 
  
    if( 0 == count )
    {
      // Kjolig - TAG_23 {0xBF, 0x5A, 0x45, 0x39}
      previous_uid[0] = 0xBF;
      previous_uid[1] = 0x5A;
      previous_uid[2] = 0x45;
      previous_uid[3] = 0x39;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if( 1 == count )
    {
      // Fornuft - TAG_21 {0x9A, 0x0D, 0xDB, 0xAB}
      previous_uid[0] = 0x9A;
      previous_uid[1] = 0x0D;
      previous_uid[2] = 0xDB;
      previous_uid[3] = 0xAB;
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
    else if(3 == count )
    {
      // Kjolig - TAG_23 {0xBF, 0x5A, 0x45, 0x39}
      previous_uid[0] = 0xBF;
      previous_uid[1] = 0x5A;
      previous_uid[2] = 0x45;
      previous_uid[3] = 0x39;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if(4 == count )
    {
      // Fornuft - TAG_21 {0x9A, 0x0D, 0xDB, 0xAB}
      previous_uid[0] = 0x9A;
      previous_uid[1] = 0x0D;
      previous_uid[2] = 0xDB;
      previous_uid[3] = 0xAB;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if(10 == count )
    {
      // Fornuft - TAG_21 {0x9A, 0x0D, 0xDB, 0xAB}
      previous_uid[0] = 0x9A;
      previous_uid[1] = 0x0D;
      previous_uid[2] = 0xDB;
      previous_uid[3] = 0xAB;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if(11 == count )
    {
      // Fjell - TAG_13 {0x56, 0x5C, 0x9A, 0xBB}
      previous_uid[0] = 0x56;
      previous_uid[1] = 0x5C;
      previous_uid[2] = 0x9A;
      previous_uid[3] = 0xBB;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if(20 == count )
    {
      // Grenselos - TAG_16 {0xE6, 0xC5, 0x9E, 0xBB}
      previous_uid[0] = 0xE6;
      previous_uid[1] = 0xC5;
      previous_uid[2] = 0x9E;
      previous_uid[3] = 0xBB;
      lo_new_card = previous_uid;
      count += 1;
    }
    else if(21 == count )
    {
      // Styrke - TAG_5 {0x36, 0x61, 0x8D, 0xBB}
      previous_uid[0] = 0x36;
      previous_uid[1] = 0x61;
      previous_uid[2] = 0x8D;
      previous_uid[3] = 0xBB;
      lo_new_card = previous_uid;
      count += 1;

      count = 0xFE;
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
