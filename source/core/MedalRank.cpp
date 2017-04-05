#include "MedalRank.h"


auto MedalRank::getMedals() -> dat::Medals
{ return medals_; }


  // 
  // @function updateMedals()
  //   @param valor
  //   1 = Gold  2 = Silver 3 = Bronze
  //
  void MedalRank::giveMedal(int valor)
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

    value_ = medals_.castToInt();
  }

  // 
  // @function updateMedals()
  //   @param valor
  //   1 = Gold, 2 = silver, 3 = bronze
  //
  void MedalRank::takeMedal(int valor)
  { 
    assert(valor > 0 && valor < 4);

    switch(valor) 
    {
      case GOLD:   medals_.gold   -= 1;  break;
      case SILVER: medals_.silver -= 1;  break;
      case BRONZE: medals_.bronze -= 1;  break;
    };
  
    assert(medals_.gold   >= 0);   // If the system behaves correctl
    assert(medals_.silver >= 0);   // 
    assert(medals_.bronze >= 0);   // 

  value_ = medals_.castToInt();
  }
