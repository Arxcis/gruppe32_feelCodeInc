#include "PointBase.h"

namespace db
{

  //
  // @class function pack()
  //
  auto PointBase::pack(const Rank* rank) -> dat::Object
  {
    auto prototype = dat::Object
    {
      {"Type",   "Point"  },                        // Medal/Point
      {"Code", (char*)rank->getNation()},      // Nation char3
      {"Point",  std::to_string(rank->getValue())}, 
    };
    return prototype;
  };

  //
  // @class function unpack()
  //
  auto PointBase::unpack(const dat::Object& object) -> Rank*
  {
    dat::char3 nationCode = dat::char3{ object[1].second.c_str() };
    int value = std::stoi(object[2].second);
    return new Rank(value, nationCode);
  }

  //
  // @class function readFile()
  //
  auto PointBase::readFile(const std::string& filepath) -> dat::Container
  {
    auto tempContainer = dat::Container{}; // @delete @temp @testing

    auto prototype = dat::Object
    {
      {"Type",        ""},  // Medal/Point
      {"Nation",      ""}, // Nation char3
      {"Point",       ""},  
    };

    auto fileToStream  = [filepath, this]()
    { 
      auto innFile = std::ifstream { filepath };
      assert(innFile);
      std::cout << "Opening "<< filepath << "...\n";  // @debug
            
      ss << innFile.rdbuf();    // Swapping buffers
      innFile.close();
    };
    
    fileToStream();

    // Reading number of objects.
    auto objectCount = std::string{};
    assert(stream::readInt(objectCount, ss, ';'));

      // Loop through all objects
    for(int i=0; i < std::stoi(objectCount); i++)
    {
      assert(stream::readEnum  (prototype[0].second, ss, {"Medal", "Point"}, ';'));
      assert(stream::readChar3 (prototype[1].second, ss, ';'));
      assert(stream::readInt   (prototype[2].second, ss, ';'));
      std::cout << "Points" << i+1 << " of " << objectCount << "\n";
      

      add(prototype);                       // Add to internal list
      tempContainer.push_back(prototype);   // Add to optional return container
    }
    return tempContainer;
  }

  /*
  FORMAT: (POSITION/RANK is given by the list sorting)
  Medal;  TYPE
  NOR;    NATIONCODE
  1-2-3;  MEDALS [GOLD-SILVER-BRONZE]
  */
}
