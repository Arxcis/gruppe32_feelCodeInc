#include "Rank.h"

int Rank::getValue() const
  { return value_; }

auto Rank::getNation() const -> dat::char3 
  { return nation_; }


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

void Rank::givePointByPosition(size_t position)
{ 
  assert(position > 0 && position < 8);
  value_ += ((position > 1) ? 7 - position : 7); //7 if pos is 1, 5-1 otherwise
}

void Rank::takePoint(size_t point)
{ 
  assert(point > 0 && point < 8);
  value_ -= point; 
}
