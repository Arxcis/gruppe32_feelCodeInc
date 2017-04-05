#include "ParticipantBase.h"


namespace db 
{

  //
  // @class function pack()
  //
  auto ParticipantBase::pack(const Participant* participant) -> dat::Object
  {
    dat::Contact contact = participant->getContact();
    auto participantObj = dat::Object
    {
      { "Type",        "Participant" },                
      { "ID",          std::to_string(participant->getID())},   // PK
      { "Name",        contact.name }, 
      { "Phone",       contact.phone },
      { "Email",       contact.mailAddress },
      { "CountryCode", (char*)participant->getNation() },       // FK
      { "Sex",         participant->getSex()},
    };
    return participantObj;
  }

  //
  // @class function unpack()
  //
  auto ParticipantBase::unpack(const dat::Object& object) -> Participant*
  { 

    //
    // If participant does not already have an ID. Generate a UNIQUE ID.
    //  the uniqeness is taken care of by a static int 
    //
    size_t ID;
    if (object[1].second == "")
      { ID = ++participantCount; }
    else
      { ID = std::stoi(object[1].second); }
      
    dat::Contact contact = dat::packing::unpackContact(object[2], object[3], object[4]);
    dat::char3 shortName = object[5].second.c_str();
    std::string sex      = object[6].second;

    return new Participant(ID, contact, shortName, sex);
  }


  //
  // @class funciton readFile()
  //    @brief Used to fill the database with data;
  //
  auto ParticipantBase::readFile(const std::string& filepath) -> dat::Container
  { 
    auto tempContainer = dat::Container{}; // @delete @temp @testing

    auto prototype = dat::Object
    {
        {"Type",        ""},  // Participant
        {"ID",          ""},
        {"Name",        ""},  // PK
        {"Phone",       ""},
        {"Email",       ""},
        {"CountryCode", ""},  // FK
        {"Sex",         ""},
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
    assert(stream::readInt(objectCount, ss));

      // Loop through all objects
    for(int i=0; i < std::stoi(objectCount); i++)
    {
      std::cout << "Participant " << i+1 << " of " << objectCount << "\n";

      assert(stream::readName (prototype[0].second, ss));
      assert(stream::readInt    (prototype[1].second, ss));
      assert(stream::readName (prototype[2].second, ss));
      assert(stream::readPhone  (prototype[3].second, ss));
      assert(stream::readEmail  (prototype[4].second, ss));
      assert(stream::readChar3  (prototype[5].second, ss));
      assert(stream::readEnum   (prototype[6].second, ss, {"Male", "Female"}));

      add(prototype);                       // Add to internal list
      tempContainer.push_back(prototype);   // Add to optional return container
    }
    return tempContainer;
  }
}
