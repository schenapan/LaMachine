#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "custom_typedef.h"


class CEngine {
  public:
    CEngine( const sDirSequence *ip_seq );
    void SetDirectorySequence( const sDirSequence *ip_seq );
    bool IsSequenceValid( sSeq *p_in_seq, sResult *op_seq_result );

  private:
    sDirSequence *p_seq;
};

#endif // ENGINE_HPP
