#include "stream.h"


bool stream::readString(std::string& value)
{ 
  getline(std::cin, value, ',');
  return 1;
}

bool stream::readPhone(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isPhone(value);
}

bool stream::readEmail(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isEmail(value);
}

bool stream::readInt(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isInt(value);
}

bool stream::readDouble(std::string&value)
{
  getline(std::cin, value, ',');
  return valid::isDouble(value);
}

bool stream::readTime(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isTime(value);
}

bool stream::readDate(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isDate(value);
}

bool stream::readMedals(std::string& value)
{
  getline(std::cin, value, ',');
  return valid::isMedals(value);
}
