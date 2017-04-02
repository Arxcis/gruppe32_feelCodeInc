#include "MedalBase.h"

namespace db
{ 
  //
  // @class function pack()
  //
  auto MedalBase::pack(Rank* rank) -> dat::Object
  { 
    dat::Medals medals = ((MedalRank*)rank)->getMedals();
    auto rankObj = dat::Object
    {
      { "Type",    "Medal" },    
      { "Nation",  (char*)rank->getNation() },                      // NationCode  
      { "Value",   dat::packing::packMedals( medals ) }, // Medal values [GOLD-SILVER-BRONZE]
    };
    return rankObj;
  }

  //
  // @class function unpack()
  //
  auto MedalBase::unpack(dat::Object& object) -> Rank*
  {
    dat::char3 nationCode = object[1].second.c_str();
    dat::Medals* medals = dat::packing::unpackMedals(object[2]);
    return new MedalRank(*medals, nationCode);
  }


  //
  // @class function readFile()
  //
  auto MedalBase::readFile(const std::string& filepath) -> dat::Container
  {
    auto tempContainer = dat::Container{}; // @delete @temp @testing
    auto prototype = dat::Object
    {
      {"Type",        ""},  // Medal/Point
      {"Nation",      ""},  
      {"Value",       ""},  
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
      stream::readChar3(ss, prototype[1].second);
      stream::readMedals(ss, prototype[2].second); 

      std::cout << "Medals" << i << "\n";
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