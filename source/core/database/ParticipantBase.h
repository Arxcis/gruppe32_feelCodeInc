#pragma once

#include "DataBase.h"
#include "../Participant.h"

class ParticipantBase : public DataBase<Participant>
{
  List* participants = elements; //aliasing the list

public:
  virtual void readFile();
};
