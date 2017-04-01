#pragma once

// POTENTIALLY DELETEABLE AND VERY REDUNDANT

#include "Rank.h"
#include "../tool/Medals.h"

class MedalRank : public Rank
{
private:
  dat::Medals medals_;
public:
  auto GetMedals() -> dat::Medals;
};