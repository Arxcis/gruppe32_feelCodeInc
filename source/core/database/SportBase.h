#pragma once

#include "DataBase.h"
#include "../Sport.h"

class SportBase : public DataBase<Sport>
{
  List* sports = elements; //aliasing the list

public:
  virtual void readFile();
};
