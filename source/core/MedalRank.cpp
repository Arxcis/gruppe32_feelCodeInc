#include "MedalRank.h"


auto MedalRank::getMedals() -> dat::Medals
{ return medals_; }


  // 
  // @function updateMedals()
  //   @param valor
  //   1 = Gold
  //   2 = Silver
  //   3 = Bronze
  //
  void MedalRank::addMedal(int valor)
  { 
    assert(valor > 0 && valor < 4);

    switch(valor) 
    {
      case GOLD:   medals_.gold   += 1;  break;
      case SILVER: medals_.silver += 1;  break;
      case BRONZE: medals_.bronze += 1;  break;
    };
  
    assert(medals_.gold   >= 0);
    assert(medals_.silver >= 0);
    assert(medals_.bronze >= 0);
  }