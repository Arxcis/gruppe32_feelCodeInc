#pragma once

#include "DataBase.h"
#include "../Sport.h"

namespace db
{
  class SportBase : public DataBase<Sport>
  {
    List& sports;
  public:
    SportBase();
    virtual ~SportBase(){}
    // Inherited via DataBase
    virtual Sport * unpack(dat::Object * object) override;
    //List& sports = *elements; //aliasing the list
    virtual dat::Container readFile(const std::string& filepath) override;
  };
}

