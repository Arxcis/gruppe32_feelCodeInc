#include "valid.h"

bool valid::isEnum(const std::string& value, const std::vector<std::string>& validStrings)
{

  for(const auto& str: validStrings)
  { 
    if (value == str) 
       { return true; } 
  }
  return false;
}

//
// @funciton isChar3
//  @robustness We should also check that all letters are indeed letters and nothing else

bool valid::isChar3(const std::string& value)
{
  return (value.size() == 3);
}

//
// @funciton isInt
//
bool valid::isInt(const std::string& value)
{
  try
  {
    int test = stoi(value); // @warning, unused var. Used to provoke exception if the convert to int fails.
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
  return std::regex_match(value, regDouble);
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
  return std::regex_match(value, regPhone);
  //return (value.find("+") != std::string::npos);
}

//
// @funciton isTime @robustness
//
bool valid::isTime(const std::string& value)
{
  return (value.find(":",2) != std::string::npos);
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
