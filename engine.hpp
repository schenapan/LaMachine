#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "custom_typedef.h"


class CEngine {
  public:
    CEngine( const sDirSequence *ip_seq, const sItemTbl *ip_items_table );
    void SetDirectorySequence( const sDirSequence *ip_seq );
    sItem *GetItem( unsigned char i_uid[UUID_TAG_SIZE] );
    bool IsSequenceValid( sSeq *p_in_seq, sResult **op_seq_result );

  private:
    sDirSequence *p_seq;
    sItemTbl *p_items_tbl;
};

#endif // ENGINE_HPP
