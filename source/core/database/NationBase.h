#pragma once

#include "DataBase.h"
#include "../Nation.h"
#include "../../tool/Unpacker.h"

class NationBase : public DataBase<Nation>
{
  List& nations = elements; //aliasing the list
public:
  virtual bool add(dat::Object* object) override;
};