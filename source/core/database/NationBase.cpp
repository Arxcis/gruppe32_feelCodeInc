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
  auto NationBase::unpack(const dat::Object& object) -> Nation*
  {
    dat::char3 shortName = object[1].second.c_str();
    std::string name = object[2].second;
    int participants = std::stoi(object[3].second);
    dat::Contact contact = dat::packing::unpackContact(object[4], object[5], object[6]);
    return new Nation(shortName, name, contact, participants);
  }

  bool NationBase::add(const dat::Object & nationObj)
  {
    if (nations->noOfElements() >= maxNations)
    { return false; }
    else
    { return DataBase<Nation>::add(nationObj); }
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
      {"#Participants",  ""},
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
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
      std::cout << "Nation " << i+1 << " of " << objectCount << "\n";      // @debug

      assert(stream::readName  (prototype[0].second, ss, ';'));
      assert(stream::readChar3 (prototype[1].second, ss, ';'));
      assert(stream::readName  (prototype[2].second, ss, ';'));
      assert(stream::readInt   (prototype[3].second, ss, ';'));
      assert(stream::readName  (prototype[4].second, ss, ';'));
      assert(stream::readPhone (prototype[5].second, ss, ';'));
      assert(stream::readEmail (prototype[6].second, ss, ';'));

      add(prototype);                       // Add to internal list
      tempContainer.push_back(prototype);   // Add to optional return container
    } 
    return tempContainer;
  }
}



