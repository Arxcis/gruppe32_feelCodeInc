#pragma once
//
// @file    core/database/MedalBase.h
// @repo    gruppe32
// @created 31.03.17 by Halvor
// @brief   A database for medal ranks
//
#include "RankBase.h"
#include "../../tool/unpacker.h"

namespace db
{
  class MedalBase : public RankBase
  {
  public:
    MedalBase() {}
    virtual ~MedalBase() {}
    virtual Rank * unpack(dat::Object * object) override;

    // Inherited via RankBase
    virtual dat::Object * pack(Rank * object) override;
  };
}
