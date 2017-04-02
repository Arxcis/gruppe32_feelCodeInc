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
    int value = dat::packing::unpackMedals(obj[2])->castToInt();
    return new Rank(value,nationCode);
  }

  dat::Object * MedalBase::pack(Rank * rank)
  {
    auto rankObj = dat::Object
    {
      { "Type",        "Medal" },  // Medal/Point
      { "Rank",        "NULL" },  // Position - not assigned by database
      { "Code",        rank->getNation() },  // NationCode        
      { "Value",       dat::packing::unpackMedals( rank->getValue() ) }  // Medal values [GOLD-SILVER-BRONZE]
    };
  }
  /*
  FORMAT: (POSITION/RANK is given by the list sorting)
      Medal;  TYPE
      NOR;    NATIONCODE
      1-2-3;  MEDALS [GOLD-SILVER-BRONZE]
  */
}