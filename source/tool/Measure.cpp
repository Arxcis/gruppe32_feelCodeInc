//
// @file    tool/Measure.cpp
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Contact data to Participants
//

#include "Measure.h"
using namespace dat;

Measure::Measure(){}
Measure::~Measure(){}

bool Measure::operator <  (Measure* other)
{
  return (this->castToInt() < other->castToInt());
}

bool Measure::operator >  (Measure* other)
{
  return (this->castToInt() > other->castToInt());
}

bool Measure::operator <= (Measure* other)
{
  return (this->castToInt() <= other->castToInt());
}

bool Measure::operator >= (Measure* other)
{
  return (this->castToInt() >= other->castToInt());
}

bool Measure::operator == (Measure* other)
{
  return (this->castToInt() == other->castToInt());
}
