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
  class MedalBase : public RankBase
  {
  public:
    MedalBase() {}
    virtual ~MedalBase() {}
    virtual Rank * unpack(dat::Object * object) override;
  };
}
