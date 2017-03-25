#pragma once
//
// @file    core/File.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Reads and verfies lines of file data. Maintains the file format.
//

// @foreign
#include <string>
#include <sstream>

// @local files
#include "Date.h"
#include "Time.h"
#include "Medals.h"
#include "valid.h"

namespace file
{
  std::string readString(std::stringstream& ss);
  std::string readPhone(std::stringstream& ss);
  std::string readEmail(std::stringstream& ss);
  int         readInt(std::stringstream& ss);
  double      readDouble(std::stringstream& ss);
  dat::Time   readTime(std::stringstream& ss);
  dat::Date   readDate(std::stringstream& ss);
  dat::Medals readMedals(std::stringstream& ss);

  void writeString(std::stringstream& ss, const std::string value);
  void writeInt(std::stringstream& ss, const int value);
  void writeDouble(std::stringstream& ss, const double value);
  void writeTime(std::stringstream& ss, const dat::Time& value);
  void writeDate(std::stringstream& ss, const dat::Date& value);
  void writeMedals(std::stringstream& ss, const dat::Medals& value);
}