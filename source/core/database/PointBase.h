#pragma once
//
// @file    core/database/PointBase.h
// @repo    gruppe32
// @created 31.03.17 by Halvor
// @brief   A database for medal ranks
//
#include "DataBase.h"
#include "../Rank.h"

namespace db
{
  class PointBase : public DataBase<Rank>
  {
  public:
    PointBase()
    :DataBase("data/point.format")
    ,points(elements)
    {}
    
    virtual ~PointBase() {}
    virtual auto pack  (const Rank* object)        -> dat::Object override;
    virtual auto unpack(dat::Object& object) -> Rank*       override;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* points;
  };
}
