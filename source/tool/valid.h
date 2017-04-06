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
       // Special case to this system
  static std::regex regDiciplineID(R"([\s]*[[:alpha:]0-9_-]+)");

      // General cases
  static std::regex regName   (R"([\s]*[#[:alpha:] \.]+)");
  static std::regex regChar3  (R"([\s]*[A-Z]{3})");
  static std::regex regInt    (R"([\s]*[0-9]+)");
  static std::regex regDouble (R"([\s]*[+-]?[0-9]{0,15}[\.]?[0-9]{1,15})"); // @robustness - could overflow floating point, @broken per 06.04.17
  static std::regex regPhone  (R"([\s]*[+][0-9]{1,3}[ ]?(([0-9]{8})|(([0-9]{2}[ ]){3}[0-9]{2})|([0-9]{3}[ ][0-9]{2}[ ][0-9]{3})))");
  static std::regex regTime   (R"([\s]*(([0-1][0-9])|([2][0-4]))[:]([0-5][0-9])(([:]([0-5][0-9]))?)(([:]([0-9]{3}))?))"); // @friendlyness, demands 00:00:00:999 for milliseconds
  static std::regex regDate   (R"([\s]*(([0][1-9])|([1-2][0-9])|([3][0-1]))[\.]([0][1-9]|[1][0-2])[\.](([1][9])|([2][0]))?([0-9]{2})$)"); //  @robustness - Does not account for varying month-length and year-length
  static std::regex regMedals (R"([\s]*(([0][1-9]?)|[1-9]{1,2})([-](([0][1-9]?)|[1-9]{1,2})){2})");
  static std::regex regEmail  (R"([\s]*([A-Za-z0-9\.-_]{3,128})*[@][A-Za-z0-9\.]{3,128}[.][a-z]{2,6})");  // @robustness - pseudo email address.


  //
  // @brief
  //  @regex example siganture 'Langrenn_10km-klassisk'
  //
  bool isDiciplineID(const std::string& value);

  //
  // @brief
  //  @regex validates if only characters
  //
  bool isName(const std::string& value);

  //
  // @brief
  //  @regex validates to true if:
  //      1. 3 letter word
  //      2. All uppercase
  //      3. A-Z
  //
  bool isChar3(const std::string& value);

  //
  // @brief
  //  @regex validates to true if:
  //      - A string consisting only of numeric-characters 0-9
  //
  bool isInt(const std::string& value);

  //
  // @brief
  //  @regex validates to true if:
  //     1. 0-15 numberic characters,
  //     2. followed by a period, 
  //     3. followd by 1-15 numeric characters.
  //
  bool isDouble(const std::string& value);

  //
  // @brief
  //  @regex validates to true if:
  //     1. Mandatory + at beginning
  //     2. 1,2 or 3 numbers
  //     3. Mandatory space
  //     4. 8 numerics in one of these patterns xxx xx xxx, or xx xx xx xx or xxxxxxxx
  //
  bool isPhone(const std::string& value);

  //
  // @brief
  //  @regex validates to true if:
  //     1. Minimum of 3 aplha-numeric character or _, -, . jonas.solsvik
  //     2. Mandatory @
  //     3. Minimum of 3 aplha-numeric character or .   ex. stud.ntnu
  //     4. Mandatory . 
  //     5. Betwenn 2-6 lowercase alpha-letters.    ex. com or no
  //
  bool isEmail(const std::string& value);
  
  bool isTime(const std::string& value);
  bool isDate(const std::string& value);
  bool isMedals(const std::string& value);
  bool isEnum(const std::string& value, const std::vector<std::string>& validStrings);
}
