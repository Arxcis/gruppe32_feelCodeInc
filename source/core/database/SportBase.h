#pragma once

#include "DataBase.h"
#include <array>
#include "../Sport.h"
#include "../Dicipline.h"

namespace db
{
  class SportBase : public DataBase<Sport>
  {
  public:
    SportBase()
    :DataBase("data/sport.format")
    ,sports(*elements)
    {}

    virtual ~SportBase(){}
    virtual auto pack  (Sport*       object) -> dat::Object override;
    virtual auto unpack(dat::Object& object) -> Sport*      override; 

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List& sports;
    std::array <Dicipline, 20> diciplines;
  };
}

