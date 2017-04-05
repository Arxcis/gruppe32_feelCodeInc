#pragma once
//
// @file    core/File.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Reads and verfies lines from any stream.getline(). 
//          Could be used to read from file, and read from keyboard
//           Maintains the correct file format.
//

// @foreign
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cassert>

// @local files
#include "Date.h"
#include "Time.h"
#include "Medals.h"
#include "valid.h"

namespace stream
{ 
  void eatSpaces(std::stringstream& stream);
  void eatSpaces(std::istream& stream);

  int readInput(const std::string& message);
  // Reading from stringstream - File Input

  //
  // @template function read-functions
  //  currently supports 
  //    std::istream  
  //    std::stringstream
  //

  // Special function to this system
  template<typename T>
  bool readDiciplineID(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDiciplineID(value);
  }

  // General functions
  template<typename T>
  bool readChar3 (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isChar3(value);
  }

  template<typename T>
  bool readName(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isName(value);
  }

  template<typename T>
  bool readPhone (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isPhone(value);
  }

  template<typename T>
  bool readEmail (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isEmail(value);
  }

  template<typename T>
  bool readInt   (std::string& value, T& stream, const char delimiter=';')
  {
    getline(stream, value, delimiter);
    eatSpaces(stream);
    return valid::isInt(value);
  }

  template<typename T>
  bool readDouble(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDouble(value);
  } 

  template<typename T>
  bool readTime  (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isTime(value);
  }

  template<typename T>
  bool readDate  (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDate(value);
  }

  template<typename T>
  bool readMedals(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isMedals(value);
  }

  template<typename T>
  bool readEnum(std::string& value, T& stream, const std::vector<std::string>& validStrings)
  {
    getline(stream, value, ';');
    bool oneHit = false;
    for(const auto& str: validStrings)
      {  if(value == str) oneHit = true; }
    eatSpaces(stream);
    return oneHit;
  }
}
