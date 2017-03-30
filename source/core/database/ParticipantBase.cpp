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
void db::ParticipantBase::readFile(const std::string filepath)
{
  dat::Object prototype =
  {
      {"Type",        ""},  // Participant
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
  } 
}
