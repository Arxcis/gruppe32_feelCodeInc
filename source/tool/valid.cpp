#include "valid.h"

//
// @funciton isInt
//
bool valid::isInt(const std::string& value)
{
  try
  {
    int test = stoi(value);
    return true;
  }
  catch (const std::invalid_argument& e)
  {
    return false;
  }
  catch (const std::out_of_range& e)
  {
    return false;
  }
}

//
// @funciton isDouble
//
bool valid::isDouble(const std::string& value)
{
  try
  {
    float test = stof(value);
    return true;
  }
  catch (const std::invalid_argument& e)
  {
    return false;
  }
  catch (const std::out_of_range& e)
  {
    return false;
  }
}

//
// @funciton isEmail @robustness
//
bool valid::isEmail(const std::string& value)
{
  return (value.find("@") != std::string::npos);
}

//
// @funciton isPhone @robustness
//
bool valid::isPhone(const std::string& value)
{
  return (value.find("+") != std::string::npos);
}

//
// @funciton isTime @robustness
//
bool valid::isTime(const std::string& value)
{
  return (value.find(":",2) != std::string::npos) && 
         (value.find(":",4) != std::string::npos);
}

//
// @funciton isDate @robustness
//
bool valid::isDate(const std::string& value)
{
  return (value.find(".",2) != std::string::npos) &&
         (value.find(".",4) != std::string::npos);
}

//
// @funciton isMedals @robustness
//
bool valid::isMedals(const std::string& value)
{
  return (value.find("-") != std::string::npos);
}
