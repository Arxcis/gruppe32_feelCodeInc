#include "Unpacker.h"

namespace dat { namespace packing
{
  Contact unpackContact(const Field & name_, const Field & phone_, const Field & mailAddress_)
  { 
    return Contact(
              name_.second, 
              phone_.second, 
              mailAddress_.second); 
}

  Time unpackTime(const Field& time_)
  {
    const std::string time = time_.second;
    return Time(
      std::stoi(time.substr(0, 2)), 
      std::stoi(time.substr(3, 2)), 
      std::stoi(time.substr(6, 2)));
  }

  Date unpackDate(const Field& date_)
  {
    const std::string date = date_.second;
    return Date(
      std::stoi(date.substr(0, 2)),
      std::stoi(date.substr(3, 2)),
      std::stoi(date.substr(6)));
  }
  Medals unpackMedals(const Field& medals_)
  { 
    const std::string medals = medals_.second;
    return Medals(
      std::stoi(medals.substr(0, 2)),
      std::stoi(medals.substr(3, 2)),
      std::stoi(medals.substr(6, 2)));
  }
}}
