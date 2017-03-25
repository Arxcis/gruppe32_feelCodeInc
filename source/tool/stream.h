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

// @local files
#include "Date.h"
#include "Time.h"
#include "Medals.h"
#include "valid.h"

namespace stream
{ 
  // Reading from std::stingstream (preferably a file) 
  bool readString(std::string& value, std::stringstream& ss);
  bool readPhone(std::string& value, std::stringstream& ss);
  bool readEmail(std::string& value, std::stringstream& ss);
  bool readInt(int& value, std::stringstream& ss);
  bool readDouble(double& value, std::stringstream& ss);
  bool readTime(dat::Time& value, std::stringstream& ss);
  bool readDate(dat::Date& value, std::stringstream& ss);
  bool readMedals(dat::Medals& value, std::stringstream& ss);

  // Reading from cin
  bool readString(std::string& value);
  bool readPhone(std::string& value);
  bool readEmail(std::string& value);
  bool readInt(std::string& value);
  bool readDouble(std::string&value);
  bool readTime(std::string& value);
  bool readDate(std::string& value);
  bool readMedals(std::string& value);

  template<class T> void writeString(T& stream, const std::string& value);
  template<class T> void writeInt(T& stream, const int value);
  template<class T> void writeDouble(T& stream, const double value);
  template<class T> void writeTime(T& stream, const dat::Time& value);
  template<class T> void writeDate(T& stream, const dat::Date& value);
  template<class T> void writeMedals(T& stream, const dat::Medals& value);
}