#include "Rank.h"

Rank::Rank(int value, dat::char3 nation)
:value_(value)
,nation_(nation)
{}

int Rank::getValue()
  { return value_; }

auto Rank::getNation() -> dat::char3
  { return dat::char3(); }
