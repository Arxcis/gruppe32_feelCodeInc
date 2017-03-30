#include "ParticipantBase.h"

db::ParticipantBase::ParticipantBase() : participants(*elements) {}

Participant * db::ParticipantBase::unpack(dat::Object * object)
{
  //UNPACK UR STUFF PLS
  return nullptr;
}

//
// @funciton db::ParticipantBase::readFile()
//    Used to fill the database with data;
//
void db::ParticipantBase::readFile(const std::string& filepath)
{ 
  dat::Container tempContainer; // @delete @temp @testing

  dat::Object prototype =
  {
      {"Type",        ""},  // Participant
      {"ID",          ""},
      {"Name",        ""},  // PK
      {"Phone",       ""},
      {"Email",       ""},
      {"CountryCode", ""},  // FK
      {"Gender",      ""}
  };

  std::ifstream innFile(filepath);

  // Crashing the program if file not found.
  assert(innFile);
  std::cout << "Opening "<< filepath << "...\n";  // @debug
      
  // Flushing filebuffer into a stringstream and closing the file
  ss << innFile.rdbuf();
  innFile.close();

  // Reading number of objects.
  std::string objectCount;
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
} 
