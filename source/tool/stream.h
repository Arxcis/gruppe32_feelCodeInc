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
  template<typename T> bool readChar3 (std::string& value, T& stream);
  template<typename T> bool readName  (std::string& value, T& stream);
  template<typename T> bool readPhone (std::string& value, T& stream);
  template<typename T> bool readEmail (std::string& value, T& stream);
  template<typename T> bool readInt   (std::string& value, T& stream);
  template<typename T> bool readDouble(std::string& value, T& stream);
  template<typename T> bool readTime  (std::string& value, T& stream);
  template<typename T> bool readDate  (std::string& value, T& stream);
  template<typename T> bool readMedals(std::string& value, T& stream);
  template<typename T> bool readEnum  (
                          T& stream, 
                          std::string& value, 
                          const std::vector<std::string>& validStrings);

}
