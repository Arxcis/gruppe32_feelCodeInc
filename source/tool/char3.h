#pragma once
#include <cstring>
namespace dat {
  struct char3
  {
  private:
    char str[4];
  public:
    char3();
    char3(const char* s);
    inline char & operator[](int i);
    operator char*() const;
  };
}