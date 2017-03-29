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
  int  readInt(const std::string& message);
  // Reading from stringstream - File Input
  void readChar3 (std::stringstream& stream, std::string& value);
  void readString(std::stringstream& stream, std::string& value);
  void readPhone (std::stringstream& stream, std::string& value);
  void readEmail (std::stringstream& stream, std::string& value);
  void readInt   (std::stringstream& stream, std::string& value);
  void readDouble(std::stringstream& stream, std::string& value);
  void readTime  (std::stringstream& stream, std::string& value);
  void readDate  (std::stringstream& stream, std::string& value);
  void readMedals(std::stringstream& stream, std::string& value);

  // Reading from cin - Keyboard input
  void readChar3 (std::istream& stream, std::string& value);
  void readString(std::istream& stream, std::string& value);
  void readPhone (std::istream& stream, std::string& value);
  void readEmail (std::istream& stream, std::string& value);
  void readInt   (std::istream& stream, std::string& value);
  void readDouble(std::istream& stream, std::string& value);
  void readTime  (std::istream& stream, std::string& value);
  void readDate  (std::istream& stream, std::string& value);
  void readMedals(std::istream& stream, std::string& value);

  template<class T> void writeString(T& stream, const std::string& value, bool assert=false);
  template<class T> void writeInt   (T& stream, const std::string& value, bool assert=false);
  template<class T> void writeDouble(T& stream, const std::string& value, bool assert=false);
  template<class T> void writeTime  (T& stream, const std::string& value, bool assert=false);
  template<class T> void writeDate  (T& stream, const std::string& value, bool assert=false);
  template<class T> void writeMedals(T& stream, const dat::Medals& value, bool assert=false);


}
