#pragma once

#include "DataBase.h"
#include "../Sport.h"

namespace db
{
  class SportBase : public DataBase<Sport>
  {
  public:
    SportBase()
    :DataBase(sportsFile)
    ,sports(elements)
      { readContainer(); }

    virtual ~SportBase(){}
    virtual auto pack  (const Sport*       object) -> dat::Object override;
    virtual auto unpack(dat::Object& object) -> Sport*      override; 

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* sports;
  };
}

