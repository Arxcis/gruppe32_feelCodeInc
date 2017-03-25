#include "valid.h"

bool valid::isInt(const std::string& value)
{
  try
  {
    int test = stoi(value);
    return true;
  }
  catch (int e)
  {
    return false;
  }
}

bool valid::isDouble(const std::string& value)
{
  try
  {
    float test = stof(value);
    return true;
  }
  catch (int e)
  {
    return false;
  }
}

bool valid::isEmail(const std::string& value)
{
  return (value.find("@") != std::string::npos);
}

bool valid::isPhone(const std::string& value)
{
  return (value.find("+") != std::string::npos);
}

bool valid::isTime(const std::string& value)
{
  return (value.find(":",2) != std::string::npos) && 
         (value.find(":",4) != std::string::npos);
}

bool valid::isDate(const std::string& value)
{
  return (value.find(".",2) != std::string::npos) &&
         (value.find(".",4) != std::string::npos);
}

bool valid::isMedals(const std::string& value)
{
  return (value.find("-") != std::string::npos);
}
