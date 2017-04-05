#include "stream.h"

namespace stream 
{
 
////////////////////////////////////////////////////////////////

            // READING FROM stream of Type type
  
////////////////////////////////////////////////////////////////

  //
  // @function eatSpaces for file-streams. Ignore white-space.
  //
  void eatSpaces(std::stringstream& stream)
  {
    std::string spaces;
    getline(stream, spaces, '\n');
  }

  //
  // @function eatSpaces for keyboard-streams.
  // Since we dont want to cause an interrupt, this is empty.
  //
  void eatSpaces(std::istream& stream)
  {}


  //
  // @template function read-functions
  //  currently supports 
  //    std::istream  
  //    std::stringstream
  //
  template<typename T>
  bool readChar3 (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isChar3(value);
  }

  template<typename T>
  bool readString(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isString();
  }

  template<typename T>
  bool readPhone (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isPhone(value);
  }

  template<typename T>
  void readEmail (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isEmail(value);
  }

  template<typename T>
  void readInt   (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isInt(value);
  }

  template<typename T>
  void readDouble(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDouble(value);
  } 

  template<typename T>
  void readTime  (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isTime(value);
  }

  template<typename T>
  void readDate  (std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDate(value);
  }

  template<typename T>
  void readMedals(std::string& value, T& stream)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isMedals(value);
  }

  template<typename T>
  void readEnum(std::string& value, T& stream, const std::vector<std::string>& validStrings)
  {
    getline(stream, value, ';');
    bool oneHit = false;
    for(const auto& str: validStrings)
    {  if(value == str) oneHit = true; }
    eatSpaces(stream);
    return oneHit;
  }