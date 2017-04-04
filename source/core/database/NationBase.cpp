#include "NationBase.h"

namespace db 
{

  //
  // @class function pack()
  //
  auto NationBase::pack(const Nation* nation) -> dat::Object
  {
    dat::Contact contact = nation->getContact();
    auto nationObj = dat::Object
    {
      {"Type",           "Nation"},   // Nation
      {"Code",           (char*)nation->getShortName()},   //PK              
      {"Name",           nation->getName()},                    
      {"#Participants",  std::to_string(nation->getParticipantCount())},
      {"ContactName",    contact.name},                    
      {"ContactPhone",   contact.phone},             
      {"ContactEmail",   contact.mailAddress},
    };
    return nationObj;
  }

  //
  // @class function unpack()
  //
  auto NationBase::unpack(dat::Object& object) -> Nation*
  {
    dat::char3 shortName = object[1].second.c_str();
    std::string name = object[2].second;
    int participants = std::stoi(object[3].second);
    dat::Contact contact = dat::packing::unpackContact(object[4], object[5], object[6]);
    return new Nation(shortName, name, contact, participants);
  }

  //
  // @class function readFile()
  //    Used to fill the database with data;
  //
  auto NationBase::readFile(const std::string& filepath) -> dat::Container
  {
    auto tempContainer = dat::Container {}; // @delete @temp @testing
    auto prototype = dat::Object 
    {
      {"Type",           ""},   // Nation
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
      std::cout << "Nation " << i+1 << " of " << objectCount << "\n";      // @debug

      stream::readString(ss, prototype[0].second);
      stream::readChar3 (ss, prototype[1].second);
      stream::readString(ss, prototype[2].second);
      stream::readInt   (ss, prototype[3].second);
      stream::readString(ss, prototype[4].second);
      stream::readPhone (ss, prototype[5].second);
      stream::readEmail (ss, prototype[6].second);

      add(prototype);                       // Add to internal list
      tempContainer.push_back(prototype);   // Add to optional return container
    } 
    return tempContainer;
  }
}



