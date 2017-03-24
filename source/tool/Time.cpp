

#include "Time.h"
using namespace dat;

Time::Time(int hour_, int minute_, int second_)
:Measure(),
hour(hour_),
minute(minute_),
second(second_)
{} 

Time::~Time(){}

void Time::display(){}
int  Time::castToInt()
{
  return ((hour*60*60) + (minute*60) + (second));
}