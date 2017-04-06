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

  void loadFile(std::stringstream& ss, const std::string& filePath)
  {
    auto innFile = std::ifstream{ filePath };

    assert(innFile);
    skipBOM(innFile);
    std::cout << "Loading " << filePath << "...\n";  // @debug
    ss.clear();
    ss << innFile.rdbuf();    // Swapping buffers
    innFile.close();
  };

  //
  // @function readInt()
  //  @brief sometimes you just want an int, and get it over with
  //
  int  readInput(const std::string& message)
  {
    std::string myInt;
    std::cout << message << ": \n";
    readInt(myInt, std::cin);
    return std::stoi(myInt);
  }
  //
  // @function skipBOM()
  //  @brief skip byte order marks in file
  // @ref:
  // http://stackoverflow.com/questions/10417613/c-reading-from-file-puts-three-weird-characters
  //
  void skipBOM(std::ifstream &in)
  {
    char test[3] = { 0 };
    in.read(test, 3);
    if ((unsigned char)test[0] == 0xEF &&
        (unsigned char)test[1] == 0xBB &&
        (unsigned char)test[2] == 0xBF)
    {
      return;
    }
    in.seekg(0);
  };
}
