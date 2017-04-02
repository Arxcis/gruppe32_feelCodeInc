#pragma once

#include "DataBase.h"
#include "../Sport.h"

namespace db
{
  class SportBase : public DataBase<Sport>
  {
  public:
    SportBase();
    virtual ~SportBase(){}
    // Inherited via DataBase
    virtual Sport * unpack(dat::Object * object) override;
    // Inherited via DataBase
    virtual dat::Object * pack(Sport * object) override;
    //List& sports = *elements; //aliasing the list
    auto getContainer() -> const dat::Container;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List& sports;
    const std::string baseFile = "data/sport.format";
  };
}

