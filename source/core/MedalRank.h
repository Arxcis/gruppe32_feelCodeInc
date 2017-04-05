#pragma once

// POTENTIALLY DELETEABLE AND VERY REDUNDANT

#include "Rank.h"
#include "../tool/Medals.h"
#include <cassert>
#include "../enum.h"

class MedalRank : public Rank
{
private:
  dat::Medals medals_;

public:
  MedalRank(dat::Medals medals, dat::char3 nation)
  :Rank(medals.castToInt(), nation)
  ,medals_(medals)
  {}
  
  auto getMedals() -> dat::Medals;

  // 
  // @function updateMedals()
  //   @param valor
  //   1 = Gold
  //   2 = Silver
  //   3 = Bronze
  //
    void addMedal(int valor);
};

