#pragma once

// POTENTIALLY DELETEABLE AND VERY REDUNDANT

#include "Rank.h"
#include "../tool/Medals.h"

class MedalRank : public Rank
{
private:
  dat::Medals medals;
public:
  MedalRank(int value);
  auto GetMedals() -> dat::Medals;
};

