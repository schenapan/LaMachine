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
  delay(500);
  if (millis() < first + 2500) {
		//TAG_17 {0x85, 0x6D, 0xB6, 0x3B}
		previous_uid[0] = 0x85;
		previous_uid[1] = 0x6D;
		previous_uid[2] = 0xB6;
		previous_uid[3] = 0x3B;
		lo_new_card = previous_uid;
  } else {
  	// Fjell TAG_13 {0x56, 0x5C, 0x9A, 0xBB}
//  	  	previous_uid[0] = 0x56;
//  			previous_uid[1] = 0x5C;
//  			previous_uid[2] = 0x9A;
//  			previous_uid[3] = 0xBB;

//  Styrke	TAG_5 {0x36, 0x61, 0x8D, 0xBB}
  	previous_uid[0] = 0x36;
		previous_uid[1] = 0x61;
		previous_uid[2] = 0x8D;
		previous_uid[3] = 0xBB;

		lo_new_card = previous_uid;
  }
#endif
    return lo_new_card;
}

void CRfid::ClearPrevious(void) {
    memset(previous_uid, 0, UUID_TAG_SIZE);
}
