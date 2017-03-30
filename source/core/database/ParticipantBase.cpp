#include "ParticipantBase.h"

db::ParticipantBase::ParticipantBase() : participants(*elements) {}

Participant * db::ParticipantBase::unpack(dat::Object * object)
{
  //UNPACK UR STUFF PLS
  return nullptr;
}

void db::ParticipantBase::readFile(const std::string filepath){}
