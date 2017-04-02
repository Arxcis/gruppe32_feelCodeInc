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
    virtual Rank* unpack(dat::Object * object) override;
    auto getContainer(const std::string& filepath) -> const dat::Container;
    
    
  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    const std::string baseFile[2] = 
    { 
      "data/point.format",
      "data/medal.format",
    };
  };
}
