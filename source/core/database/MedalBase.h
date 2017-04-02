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
  class MedalBase : public DataBase<Rank>
  {
  public:
    MedalBase() {}
    virtual ~MedalBase() {}
    virtual auto unpack(dat::Object * object) -> Rank*        override;
    virtual auto pack(Rank * object)          -> dat::Object* override;
    auto getContainer() -> const dat::Container;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    const std::string baseFile = "data/medal.format";
  };
}
