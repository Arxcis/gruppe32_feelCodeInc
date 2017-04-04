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
  //
  // @class PointBase
  //  @brief
  //   After every resultList, the 6 first Nations get 7,5,4,3,2,1 points.
  //
  class PointBase : public DataBase<Rank>
  {
  public:
    PointBase()
    :DataBase(pointsFile)
    ,points(elements)
      { readContainer(); }
    
    virtual ~PointBase() {}
    virtual auto pack  (const Rank* object)        -> dat::Object override;
    virtual auto unpack(dat::Object& object) -> Rank*       override;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* points;
  };
}
