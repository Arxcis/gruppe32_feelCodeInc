#pragma once
//
// @file    core/database/StatBase.h
// @repo    gruppe32
// @created 31.03.17 by Jonas
// @brief   A database for point and medal ranks
//
#include "../Rank.h"
#include "DataBase.h"

namespace db
{
  class RankBase : public DataBase<Rank>
  {
  public:
    RankBase(){}
    virtual ~RankBase(){}
    virtual Rank * unpack(dat::Object * object) override;
    virtual dat::Container readFile(const std::string& filepath) override;
  };
}