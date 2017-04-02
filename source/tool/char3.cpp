#include "char3.h"

namespace dat {
  char3::char3()
  {}
  char3::char3(const char* s)
  {

#ifdef WIN32
      strcpy_s(str, s);
#else
      strcpy(str, s);
#endif
      
  }
  inline char & char3::operator[](int i)
    { return str[i]; }
  char3::operator char*() const
    { return (char*)str; }
}