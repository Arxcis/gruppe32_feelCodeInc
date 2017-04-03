#include "Rank.h"

int Rank::getValue()
  { return value_; }

auto Rank::getNation() -> dat::char3
  { return dat::char3(); }


void Rank::display()
{
    printf("RankValue:\t%d\nNation:%s\n", value_, (char*)nation_);
}
