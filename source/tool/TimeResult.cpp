#include "TimeResult.h"

auto TimeResult::getTimeStamp() -> dat::Time
{ return timeStamp_; }


void TimeResult::display()
  { printf("ID: %d    Time: %ds\n",ID_, timeStamp_.castToInt()); }