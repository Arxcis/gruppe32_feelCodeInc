#pragma once
//
// @file    core/database/PointBase.h
// @repo    gruppe32
// @created 31.03.17 by Halvor
// @brief   A database for medal ranks
//
#include "RankBase.h"

namespace db
{
  class PointBase : public DataBase<Rank>
  {
  public:
    PointBase() {}
    virtual ~PointBase() {}
    virtual auto unpack(dat::Object * object) ->  Rank* override;
    virtual auto pack(Rank * object) -> dat::Object* override;
    auto getContainer() -> const dat::Container;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    const std::string baseFile =  "data/point.format";
  };
}
