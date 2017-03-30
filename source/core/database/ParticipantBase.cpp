#include "ParticipantBase.h"

db::ParticipantBase::ParticipantBase() : participants(*elements) {}

Participant * db::ParticipantBase::unpack(dat::Object * object)
{
  //UNPACK UR STUFF PLS
  return nullptr;
}

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
}
