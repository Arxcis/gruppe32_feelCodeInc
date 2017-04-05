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
  bool readChar3 (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isChar3(value);
  }

  template<typename T>
  bool readString(T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isString();
  }

  template<typename T>
  bool readPhone (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isPhone(value);
  }

  template<typename T>
  void readEmail (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isEmail(value);
  }

  template<typename T>
  void readInt   (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isInt(value);
  }

  template<typename T>
  void readDouble(T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDouble(value);
  } 

  template<typename T>
  void readTime  (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isTime(value);
  }

  template<typename T>
  void readDate  (T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isDate(value);
  }

  template<typename T>
  void readMedals(T& stream, std::string& value)
  {
    getline(stream, value, ';');
    eatSpaces(stream);
    return valid::isMedals(value);
  }

  template<typename T>
  void readEnum(T& stream, std::string& value, const std::vector<std::string>& validStrings)
  {
    getline(stream, value, ';');
    bool oneHit = false;
    for(const auto& str: validStrings)
    {  if(value == str) oneHit = true; }
    eatSpaces(stream);
    return oneHit;
  }