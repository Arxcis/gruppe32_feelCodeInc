#include "MedalBase.h"

namespace db
{
  //
  // @class function MedalBase::unpack
  //
  auto MedalBase::unpack(dat::Object * object) -> Rank*
  { 
    dat::Object obj = *object;
    dat::char3 nationCode = obj[1].second.c_str();
    int value = dat::packing::unpackMedals(obj[2])->castToInt();
    return new Rank(value,nationCode);
  }

  auto MedalBase::pack(Rank * rank) -> dat::Object*
  {
    auto rankObj = dat::Object
    {
      { "Type",        "Medal" },  // Medal/Point
      { "Rank",        "NULL" },  // Position - not assigned by database
      { "Code",        ""},//rank->getNation() },  // NationCode      //@incomplete
      { "Value",       ""},//dat::packing::unpackMedals( rank->getValue() ) }  // Medal values [GOLD-SILVER-BRONZE]
    };
  }

  //
  // @class funciton db::MedalBase::getContainer
  //  @brief returns a container of all points in base
  //
  auto MedalBase::getContainer() -> const dat::Container
  { return readFile(baseFile); }


  //
  // @class function Rankbase::readFile
  //
  auto MedalBase::readFile(const std::string& filepath) -> dat::Container
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

      stream::readMedals(ss, prototype[3].second); 
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