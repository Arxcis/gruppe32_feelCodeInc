

#include "Date.h"
using namespace dat;

Date::Date(int year_, int month_, int day_)
:Measure(),
year(year_),
month(month_),
day(day_)
{}
 
Date::~Date(){}

void Date::display(){}

//
// @function castToInt()
//  @brief Converts the date, into an integer which can be compared.
//    This integer is not meant to be an accurate representation of the date
//    which is why the conversion is simplified. It is necesarry to do 
//    and accurate conversion, as long as two equal dates gets an
//    equal integer which can be compared to 'true'
//
int  Date::castToInt()
{
  return ((year*365) + (month*30) + (day));
}