#include "stream.h"

namespace stream 
{
 
////////////////////////////////////////////////////////////////

            // READING FROM std::stringstream (file)
  
////////////////////////////////////////////////////////////////

  void eatSpaces(std::stringstream& stream)
  {
    std::string spaces;
    getline(stream, spaces, '\n');
  }

  void readChar3 (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isChar3(value));
    eatSpaces(stream);
  }

  void readString(std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');

    eatSpaces(stream);
  }

  void readPhone (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isPhone(value));
    eatSpaces(stream);
  }

  void readEmail (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isEmail(value));
    eatSpaces(stream);
  }

  void readInt   (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isInt(value));
    eatSpaces(stream);
  }

  void readDouble(std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isDouble(value));
    eatSpaces(stream);
  }

  void readTime  (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isTime(value));
    eatSpaces(stream);
  }

  void readDate  (std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isDate(value));
    eatSpaces(stream);
  }

  void readMedals(std::stringstream& stream, std::string& value)
  {
    getline(stream, value, ';');
    assert(valid::isMedals(value));
    eatSpaces(stream);
  }

  void readEnum(std::stringstream& stream, std::string& value, const std::vector<std::string>& validStrings)
  {
    getline(stream, value, ';');
    bool oneHit = false;
    for(const auto& str: validStrings)
    {  if(value == str) oneHit = true; }
      assert(oneHit);
    eatSpaces(stream);
  }

////////////////////////////////////////////////////////////////

              // READING FROM std::istream (cin)

////////////////////////////////////////////////////////////////

  int  readInt(const std::string& message)
  {
    std::string myInt;
    std::cout << message << ": ";
    readInt(std::cin, myInt);
    return std::stoi(myInt);
  }

  void readString(std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
  }


  void readChar3 (std::istream& stream, std::string& value)
  { 
    getline(stream, value, '\n');
    while(!valid::isChar3(value))
    {
      std::cout << "Not a char3! ex: 'NOR'\n";
      getline(stream, value, '\n');
    }
  }

  void readPhone (std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isPhone(value))
    {
      std::cout << "Not a phone number! ex: '+4745200864'\n";
      getline(stream, value, '\n');
    }
  }

  void readEmail (std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isEmail(value))
    {
      std::cout << "Not an email! ex: 'jonas.solsvik@gmail.com'\n";
      getline(stream, value, '\n');
    }
  }

  void readInt   (std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isInt(value))
    {
      std::cout << "Not an int! ex: '1' or '42'\n";
      getline(stream, value, '\n');
    }
  }

  void readDouble(std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isDouble(value))
    {
      std::cout << "Not a double! ex: '0.99' or '3.14'\n";
      getline(stream, value, '\n');
    }
  }

  void readTime  (std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isTime(value))
    {
      std::cout << "Not a Time! ex: '13:37' or '12:22:22'\n";
      getline(stream, value, '\n');
    }
  }

  void readDate  (std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isDate(value))
    {
      std::cout << "Not a Date! ex: '12.03.1991' or '08.06.2000'\n";
      getline(stream, value, '\n');
    }
  }

  void readMedals(std::istream& stream, std::string& value)
  {
    getline(stream, value, '\n');
    while(!valid::isMedals(value))
    {
      std::cout << "Not a Medals! ex: '1-3-0'\n";
      getline(stream, value, '\n');
    }
  }

  void readEnum(std::istream& stream, std::string& value, const std::vector<std::string>& validStrings)
  {
    getline(stream, value, '\n');
    while(!valid::isEnum(value, validStrings)) 
    {
      std::cout << "Not a valid Enum! ex: ";
      for(const auto& string: validStrings)
        { std::cout << string << ", "; }
      std::cout << "\n";
      getline(stream, value, '\n');
    }
  }

////////////////////////////////////////////////////////////////

              // WRITING TO FILE

////////////////////////////////////////////////////////////////


  void writeString(std::istream& stream, const std::string& value)
  {

  }

  void writeInt(std::istream& stream, const std::string& value)
  {

  }

  void writeDouble(std::istream& stream, const std::string& value)
  {

  }

  void writeTime(std::istream& stream, const std::string& value)
  {

  }

  void writeDate(std::istream& stream, const std::string& value)
  {

  }

  void writeMedals(std::istream& stream, const dat::Medals& value)
  {

  }
}

