#pragma once

#include "DataBase.h"
#include "../Nation.h"

class NationBase : public DataBase<Nation>
{
  List& nations = elements; //aliasing the list
};