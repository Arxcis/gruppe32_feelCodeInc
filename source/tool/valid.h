#pragma once
//
// @file    tool/valid.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Validates if a string is one of the basic data types
//


#include <string>
#include <vector>
#include <regex>

namespace valid
{
  
  // @regex
  //   All these regular expressions har hand-made using the
  //    really helpfull tool rubuluar.com
  //
  static std::regex regChar3  ("[A-Z]{3}");
  static std::regex regInt    ("[0-9]+");
  static std::regex regDouble ("[+-]?[0-9]{0,15}[\\.]?[0-9]{1,15}"); // @robustness - could overflow floating point
  static std::regex regPhone  ("[+][0-9]{1,3}[ ](([0-9]{8})|(([0-9]{2}[ ]){3}[0-9]{2})|([0-9]{3}[ ][0-9]{2}[ ][0-9]{3}))");
  static std::regex regTime   ("[0-9]{2}[:][0-9]{2}([:][0-9]{2}([:][0-9]{3})?)?"); // @friendlyness, demands 00:00:00:999 for milliseconds
  static std::regex regDate   ("(([0][1-9])|([1-2][0-9])|([3][0-1]))[\\.](([0][1-9])|([1][0-2]))[\\.](([0-9]{2})|(([1][9][0-9]{2})|([2][0]([0-9]{2}))))"); //  @robustness - Does not account for varying month-length and year-length
  static std::regex regMedals ("(([0][1-9]?)|[1-9]{1,2})([-](([0][1-9]?)|[1-9]{1,2})){2}");


  bool isChar3(const std::string& value);
  bool isInt(const std::string& value);
  bool isDouble(const std::string& value);
  bool isPhone(const std::string& value);
  bool isEmail(const std::string& value);
  bool isPhone(const std::string& value);
  bool isTime(const std::string& value);
  bool isDate(const std::string& value);
  bool isMedals(const std::string& value);
  bool isEnum(const std::string& value, const std::vector<std::string>& validStrings);
}
