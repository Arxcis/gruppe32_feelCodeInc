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

auto dat::packing::packTime(const dat::Time& time) -> std::string
{ 
    return std::to_string(time.hour) + ":" + std::to_string(time.minute) + ":" + std::to_string(time.second);
}

auto dat::packing::packDate(const dat::Date& date) -> std::string
{ 
  return std::to_string(date.year) + "." + std::to_string(date.month) + "." + std::to_string(date.day);
}

auto dat::packing::packMedals(const dat::Medals& medals) -> std::string
{ 
  return  std::to_string(medals.gold) + "-" + std::to_string(medals.silver) + "-" + std::to_string(medals.bronze);
}
