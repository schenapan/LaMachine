#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "custom_typedef.h"


class CEngine {
  public:
    CEngine( const sSequence *ip_seq );

  private:
    sSequence *p_seq;
};

#endif // ENGINE_HPP
