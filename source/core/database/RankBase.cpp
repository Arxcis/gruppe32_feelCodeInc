#include "RankBase.h"

namespace db
{ 
  //
  // @class function RankBase::unpack
  //
  Rank * RankBase::unpack(dat::Object * object)
  { 
    dat::Object obj = *object;
    //@SUGGESTED IMPLEMENTATION
    /*
    if(obj[0].second.compare("Medal"))
    { dat::unpacking::medal(obj); }
    else
    { dat::unpacking::point(obj); }
    */
    return nullptr;
  }

  //
  // @funciton db::ParticipantBase::getContainer
  //  @brief returns a container of all participants in base
  //
  auto RankBase::getContainer(const std::string& filepath) -> const dat::Container
    { return readFile(filepath); }

  //
  // @class function Rankbase::readFile
  //
  auto RankBase::readFile(const std::string& filepath) -> dat::Container
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
