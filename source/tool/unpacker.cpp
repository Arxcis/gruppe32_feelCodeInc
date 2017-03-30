#include "Unpacker.h"

namespace dat { namespace unpacking
{
  Contact* contact(const Field & name_, const Field & phone_, const Field & address_)
  { return new Contact(name_.second, phone_.second, address_.second); }

  Time * time(const Field & time_)
  {
    const std::string* time = &time_.second;
    return new Time(
      std::stoi(time->substr(0, 2)), 
      std::stoi(time->substr(3, 2)), 
      std::stoi(time->substr(6, 2)));
  }

  Date * date(const Field & date_)
  {
    const std::string* time = &date_.second;
    return new Date(
      std::stoi(time->substr(0, 2)),
      std::stoi(time->substr(3, 2)),
      std::stoi(time->substr(6, 2)));
  }
}}