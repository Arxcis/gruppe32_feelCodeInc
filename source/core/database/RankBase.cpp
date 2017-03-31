#include "RankBase.h"

namespace db
{ 
  //
  // @class function Rankbase::unpack
  //
  Rank * RankBase::unpack(dat::Object * object)
  { 
    // @missing implementatino
    return nullptr;
  }

  //
  // @class function Rankbase::unpack
  //
  dat::Container RankBase::readFile(const std::string& filepath)
  {
    dat::Container tempContainer; // @delete @temp @testing

    dat::Object prototype =
    {
      {"Type",        ""},  // Medal/Point
      {"Rank",        ""},  // FK
      {"Code",        ""},  // PPK
      {"Value",       ""},  // PPK
    };

    std::ifstream innFile(filepath);

    // Crashing the program if file not found.
    assert(innFile);
    std::cout << "Opening "<< filepath << "...\n";  // @debug
        
    // Flushing filebuffer into a stringstream and closing the file
    ss << innFile.rdbuf();
    innFile.close();

    // Reading number of objects.
    std::string objectCount;
    stream::readInt(ss,objectCount);

      // Loop through all objects
    for(int i=0; i < std::stoi(objectCount); i++)
    {
      stream::readEnum(ss, prototype[0].second, {"Medal", "Point"});
      stream::readInt(ss, prototype[1].second);
      stream::readChar3(ss, prototype[2].second);

      if(prototype[0].second == "Medal")
        { 
          stream::readMedals(ss, prototype[3].second); 
          std::cout << "Medals" << i << "\n";
        }
      else 
        { 
          stream::readInt(ss, prototype[3].second); 
          std::cout << "Points" << i << "\n";
        }

      tempContainer.push_back(prototype);
    }
    return tempContainer;
  }
}
