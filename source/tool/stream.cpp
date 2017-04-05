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
  // @function readInt()
  //  @brief sometimes you just want an int, and get it over with
  //
  int  readInput(const std::string& message)
  {
    std::string myInt;
    std::cout << message << ": \n";
    readInt(myInt, std::cin, '\n');
    return std::stoi(myInt);
  }
}
