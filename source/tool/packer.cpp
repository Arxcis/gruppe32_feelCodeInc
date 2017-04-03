#include "packer.h"

dat::Object* dat::packing::packContact( const std::string & name_, 
                                          const std::string & phone_, 
                                          const std::string & mailAddress_)
{
  return new dat::Object
  { 
    { "Name", name_},
    { "Phone", phone_ }, 
    { "EMail", mailAddress_ }
  };
}

auto dat::packing::packInt(const int myint) -> const std::string 
{
  return (myint < 10) ? "0" + std::to_string(myint) : std::to_string(myint);
}

auto dat::packing::packTime(const dat::Time& time) -> std::string
{   
  return  packInt(time.hour) + ":" + packInt(time.minute) + ":" + packInt(time.second);
}

auto dat::packing::packDate(const dat::Date& date) -> std::string
{ 
  return packInt(date.year) + "." + packInt(date.month) + "." + packInt(date.day);
}

auto dat::packing::packMedals(const dat::Medals& medals) -> std::string
{ 
  return  packInt(medals.gold) + "-" + packInt(medals.silver) + "-" + packInt(medals.bronze);
}
