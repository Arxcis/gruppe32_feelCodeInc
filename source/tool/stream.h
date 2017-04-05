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

  int  readInt(const std::string& message);
  // Reading from stringstream - File Input
  template<typename T> bool readChar3 (T& stream, std::string& value);
  template<typename T> bool readName  (T& stream, std::string& value);
  template<typename T> bool readPhone (T& stream, std::string& value);
  template<typename T> bool readEmail (T& stream, std::string& value);
  template<typename T> bool readInt   (T& stream, std::string& value);
  template<typename T> bool readDouble(T& stream, std::string& value);
  template<typename T> bool readTime  (T& stream, std::string& value);
  template<typename T> bool readDate  (T& stream, std::string& value);
  template<typename T> bool readMedals(T& stream, std::string& value);
  template<typename T> bool readEnum  (
                          T& stream, 
                          std::string& value, 
                          const std::vector<std::string>& validStrings);

}
