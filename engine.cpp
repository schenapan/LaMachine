
#include <stdlib.h>


#include "engine.hpp"


CEngine::CEngine( const sDirSequence *ip_seq )
{
  p_seq = ip_seq;
}

void CEngine::SetDirectorySequence( const sDirSequence *ip_seq )
{
  p_seq = ip_seq;
}

bool CEngine::IsSequenceValid( sSeq *p_in_seq, sResult *op_seq_result )
{
  bool o_valid = false;
  op_seq_result = NULL;

  


  return o_valid;
}

