#include "NationBase.h"

namespace db 
{
  NationBase::NationBase() 
  :nations(*elements)
  {}

  //
  // @funciton db::Nationbase::unpack()
  //
  Nation * NationBase::unpack(dat::Object * object)
  {
    dat::Object obj = *object;
    dat::char3 shortName = obj[1].second.c_str();
    std::string name = obj[2].second;
    int participants = std::stoi(obj[3].second);
    dat::Contact contact = *dat::unpacking::contact(obj[4], obj[5], obj[6]);
    return new Nation(shortName, name, contact, participants);
  }

  //
  // @funciton db::NationBase::getContainer
  //  @brief returns a container of all nations in base
  //
  auto NationBase::getContainer() -> const dat::Container
    { return readFile(baseFile); }

  //
  // @funciton db::Nationbase::readFile()
  //    Used to fill the database with data;
  //
  auto NationBase::readFile(const std::string& filepath) -> dat::Container
  {
    auto tempContainer = dat::Container {}; // @delete @temp @testing

    auto prototype = dat::Object 
    {
      {"type",           ""},   // Nation
      {"Code",           ""},   //PK              
      {"Name",           ""},                    
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
      {"#Participants",  ""}
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
      std::cout << "Nation " << i << "\n";      // @debug

      stream::readString(ss, prototype[0].second);
      stream::readChar3 (ss, prototype[1].second);
      stream::readString(ss, prototype[2].second);
      stream::readInt   (ss, prototype[3].second);
      stream::readString(ss, prototype[4].second);
      stream::readPhone (ss, prototype[5].second);
      stream::readEmail  (ss, prototype[6].second);

      tempContainer.push_back(prototype);
    } 
    return tempContainer;
  }
}



