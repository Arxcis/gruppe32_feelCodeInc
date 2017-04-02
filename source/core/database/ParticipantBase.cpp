#include "ParticipantBase.h"

db::ParticipantBase::ParticipantBase() : participants(*elements) {}

Participant * db::ParticipantBase::unpack(dat::Object * object)
{
  dat::Object obj = *object;
  int ID = stoi(obj[1].second);
  dat::Contact contact = *dat::unpacking::contact(obj[2], obj[3], obj[4]);
  dat::char3 shortName = obj[5].second.c_str();
  Participant::Gender gender = (Participant::Gender)stoi(obj[6].second);
  return new Participant(ID,contact,shortName, gender);
}

dat::Object * db::ParticipantBase::pack(Participant * participant)
{
  dat::Contact contact = participant->getContact();
  auto participantObj = new dat::Object
  {
    { "Type",        "Participant" },  // Participant
    { "ID",          std::to_string(participant->getID())},
    { "Name",        contact.name },  // PK
    { "Phone",       contact.phone },
    { "Email",       contact.mailAddress },
    { "CountryCode", participant->getNation() },  // FK
    { "Gender",      participant->getGender() ? "Male" : "Female" }
  };
  return participantObj;
}

//
// @funciton db::ParticipantBase::readFile()
//    Used to fill the database with data;
//
auto db::ParticipantBase::readFile(const std::string& filepath) -> dat::Container
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
      {"Gender",      ""}
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
    std::cout << "Participant " << i << "\n";

    stream::readString (ss, prototype[0].second);
    stream::readInt    (ss, prototype[1].second);
    stream::readString (ss, prototype[2].second);
    stream::readPhone  (ss, prototype[3].second);
    stream::readEmail  (ss, prototype[4].second);
    stream::readChar3  (ss, prototype[5].second);
    stream::readEnum   (ss, prototype[6].second, {"Male", "Female"});

    tempContainer.push_back(prototype);
  } 
  writeFile(filepath, tempContainer);   // @testing @debug @delete me
  return tempContainer;
}