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
// @function isString
//
bool valid::isName(const std::string& value)
{ 
  return std::regex_match(value, regName);
}
//
// @funciton isChar3
//  @robustness We should also check that all letters are indeed letters and nothing else

bool valid::isChar3(const std::string& value)
{
  return std::regex_match(value, regChar3);
}

//
// @funciton isInt
//
bool valid::isInt(const std::string& value)
{
  return std::regex_match(value, regInt);
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
  return std::regex_match(value, regEmail);
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
  return std::regex_match(value, regTime);
}

//
// @funciton isDate @robustness
//
bool valid::isDate(const std::string& value)
{
  return std::regex_match(value, regDate);
}

//
// @funciton isMedals @robustness
//
bool valid::isMedals(const std::string& value)
{
  return std::regex_match(value, regMedals);
}
