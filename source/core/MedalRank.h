#pragma once

// POTENTIALLY DELETEABLE AND VERY REDUNDANT

#include "Rank.h"
#include "../tool/Medals.h"

class MedalRank : public Rank
{
private:
  dat::Medals medals_;

public:
  MedalRank(dat::Medals medals, dat::char3 nation);
  auto getMedals() -> dat::Medals;
};

