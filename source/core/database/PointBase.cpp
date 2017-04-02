#include "PointBase.h"

namespace db
{
  //
  // @class function MedalBase::unpack
  //
  Rank * PointBase::unpack(dat::Object * object)
  {
    dat::Object obj = *object;
    dat::char3 nationCode = obj[1].second.c_str();
    if(obj[0].secont.compare)
    int value = std::stoi(obj[2].second);
    return new Rank(value, );
  }
  /*
  FORMAT: (POSITION/RANK is given by the list sorting)
  Medal;  TYPE
  NOR;    NATIONCODE
  1-2-3;  MEDALS [GOLD-SILVER-BRONZE]
  */
}