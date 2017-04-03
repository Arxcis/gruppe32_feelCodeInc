#pragma once

// POTENTIALLY DELETEABLE AND VERY REDUNDANT

#include "Rank.h"
#include "../tool/Medals.h"

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
};

