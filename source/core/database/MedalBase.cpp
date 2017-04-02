#include "MedalBase.h"

namespace db
{
  //
  // @class function MedalBase::unpack
  //
  Rank * MedalBase::unpack(dat::Object * object)
  { 
    dat::Object obj = *object;
    dat::char3 nationCode = obj[1].second.c_str();
    int value = std::stoi(obj[2].second);
    return new Rank(value,nationCode);
  }
  /*
  FORMAT: (POSITION/RANK is given by the list sorting)
      Medal;  TYPE
      NOR;    NATIONCODE
      1-2-3;  MEDALS [GOLD-SILVER-BRONZE]
  */
}