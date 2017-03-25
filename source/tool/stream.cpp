#include "stream.h"


bool stream::readString(const std::string& message, std::string& value)
{
  std::cout << message << " :  "; 
  getline(std::cin, value, ',');
  return 1;
}

bool stream::readPhone(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isPhone(value);
}

bool stream::readEmail(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isEmail(value);
}

bool stream::readInt(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isInt(value);
}

bool stream::readDouble(const std::string& message, std::string&value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isDouble(value);
}

bool stream::readTime(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isTime(value);
}

bool stream::readDate(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isDate(value);
}

bool stream::readMedals(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";
  getline(std::cin, value, ',');
  return valid::isMedals(value);
}
