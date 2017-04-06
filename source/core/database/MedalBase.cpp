#include "MedalBase.h"

namespace db
{ 
  //
  // @class function pack()
  //
  auto MedalBase::pack(const Rank* rank) -> dat::Object
  { 
    dat::Medals medals = ((MedalRank*)rank)->getMedals();
    auto rankObj = dat::Object
    {
      { "Type",    "Medal" },    
      { "Code",    (char*)rank->getNation() },           // NationCode  
      { "Medal",   dat::packing::packMedals( medals ) } // Medal values [GOLD-SILVER-BRONZE]
    };
    return rankObj;
  }

  //
  // @class function unpack()
  //
  auto MedalBase::unpack(const dat::Object& object) -> Rank*
  {
    dat::char3 nationCode = object[1].second.c_str();
    dat::Medals medals = dat::packing::unpackMedals(object[2]);
    return new MedalRank(medals, nationCode);
  }


  //
  // @class function readFile()
  //
  auto MedalBase::readFile(const std::string& filepath) -> dat::Container
  {
    std::stringstream ss;                // Buffer for reading from files
    auto tempContainer = dat::Container{}; // @delete @temp @testing
    auto prototype = dat::Object
    {
      {"Type",     ""},  // Medal/Point
      {"Nation",   ""},  
      {"Medal",    ""},  
    };

    stream::loadFile(ss, filepath);

    // Reading number of objects.
    auto objectCount = std::string{};
    assert(stream::readInt(objectCount, ss, ';'));

      // Loop through all objects
    for(int i=0; i < std::stoi(objectCount); i++)
    {
      assert(stream::readEnum  (prototype[0].second, ss,  {"Medal", "Point"}, ';'));
      assert(stream::readChar3 (prototype[1].second, ss, ';'));
      assert(stream::readMedals(prototype[2].second, ss, ';')); 

      std::cout << "Medals" << i+1 << " of " << objectCount << "\n";

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
