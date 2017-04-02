#include "PointBase.h"

namespace db
{

  //
  // @class function pack()
  //
  auto PointBase::pack(Rank* object) -> dat::Object
  {
    //@incomplete
    return {};
  };

  //
  // @class function unpack()
  //
  auto PointBase::unpack(dat::Object& object) -> Rank*
  {
    //dat::char3 nationCode = object[1].second.c_str();
    //if (object[0].second.compare)
    //int value = std::stoi(object[2].second);
    return nullptr; //new Rank(value, nationCode);
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
      {"Rank",        ""},  // FK
      {"Code",        ""},  // PPK
      {"Value",       ""},  // PPK
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
    stream::readInt(ss,objectCount);

      // Loop through all objects
    for(int i=0; i < std::stoi(objectCount); i++)
    {
      stream::readEnum(ss, prototype[0].second, {"Medal", "Point"});
      stream::readInt(ss, prototype[1].second);
      stream::readChar3(ss, prototype[2].second);

      stream::readInt(ss, prototype[3].second); 
      std::cout << "Points" << i << "\n";
      

      tempContainer.push_back(prototype);
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