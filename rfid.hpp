#ifndef RFID_HPP
#define RFID_HPP

#include <MFRC522.h> 
#include "config_sequence.h"


class CRfid {

  public:
  CRfid( byte chipSelectPin, byte resetPowerDownPin );

  
  byte *GetNewCardId( void );

  private :
    MFRC522 *p_mfrc522;
    byte previous_uid[UUID_TAG_SIZE];
};


#endif // RFI_HPP
