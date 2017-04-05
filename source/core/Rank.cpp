#include "Rank.h"

int Rank::getValue() const
  { return value_; }

auto Rank::getNation() const -> dat::char3 
  { return dat::char3(); }


void Rank::display()
{
  printf("\n   =====   Rank   =====    "); 
    printf("\n\nRankValue:\t%d\nNation:\t%s\n", value_, (char*)nation_);
}

void Rank::givePoint(size_t point)
{ 
  assert(point > 0 && point < 8);
  value_ += point; 
}

void Rank::takePoint(size_t point)
{ 
  assert(point > 0 && point < 8);
  value_ -= point; 
}
