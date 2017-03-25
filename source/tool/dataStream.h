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

// @local files
#include "Date.h"
#include "Time.h"
#include "Medals.h"
#include "valid.h"

namespace stream
{
  template<class T> std::string readString(T stream& ss);
  template<class T> std::string readPhone(T stream& ss);
  template<class T> std::string readEmail(T stream& ss);
  template<class T> int         readInt(T stream& ss);
  template<class T> double      readDouble(T stream& ss);
  template<class T> dat::Time   readTime(T stream& ss);
  template<class T> dat::Date   readDate(T stream& ss);
  template<class T> dat::Medals readMedals(T stream& ss);

  template<class T> void writeString(T stream& ss, const std::string& value);
  template<class T> void writeInt(T stream& ss, const int value);
  template<class T> void writeDouble(T stream& ss, const double value);
  template<class T> void writeTime(T stream& ss, const dat::Time& value);
  template<class T> void writeDate(T stream& ss, const dat::Date& value);
  template<class T> void writeMedals(T stream& ss, const dat::Medals& value);
}