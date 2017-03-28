#include "char3.h"

namespace dat {
  char3::char3()
  {}
  char3::char3(const char* s)
  {
    strcpy_s(str, s);
  }
  inline char & char3::operator[](int i)
  {
    return str[i];
  }
}