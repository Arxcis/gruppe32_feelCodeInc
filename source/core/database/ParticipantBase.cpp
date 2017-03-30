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
  if(innFile)
  {
    std::cout << "Opening "<< filepath << "...\n";  // @debug
  }
  else 
    { std::cout << "File "<< filepath << " not found...\n"; }   // @debug
}
