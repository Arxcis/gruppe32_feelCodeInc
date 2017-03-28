#pragma once

#include "DataBase.h"
#include "../Participant.h"

class NationBase : public DataBase<Participant>
{
  List& participants = elements; //aliasing the list
};