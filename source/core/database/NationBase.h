#pragma once

#include "DataBase.h"
#include "../Nation.h"
#include "../../tool/Unpacker.h"

class NationBase : public DataBase
{
  List* nations = elements; //aliasing the list
public:
  NationBase();
  virtual ~NationBase();
  virtual bool add(dat::Object* object) override;

  virtual void readFile();
};