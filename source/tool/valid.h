#pragma once
//
// @file    tool/valid.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Validates if a string is one of the basic data types
//


#include <string>

namespace valid
{
  bool isChar3(const std::string& value);
  bool isInt(const std::string& value);
  bool isDouble(const std::string& value);
  bool isPhone(const std::string& value);
  bool isEmail(const std::string& value);
  bool isPhone(const std::string& value);
  bool isTime(const std::string& value);
  bool isDate(const std::string& value);
  bool isMedals(const std::string& value);
}