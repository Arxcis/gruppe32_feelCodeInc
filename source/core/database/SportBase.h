#pragma once

#include "DataBase.h"
#include "../Sport.h"

class NationBase : public DataBase<Sport>
{
  List& sports = elements; //aliasing the list
};