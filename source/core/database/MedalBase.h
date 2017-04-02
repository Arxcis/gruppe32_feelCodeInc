#pragma once
//
// @file    core/database/MedalBase.h
// @repo    gruppe32
// @created 31.03.17 by Halvor
// @brief   A database for medal ranks
//
#include "DataBase.h"
#include "../Rank.h"
#include "../../tool/Unpacker.h"
#include "../../tool/packer.h"
#include "../../tool/Medals.h"
#include "../MedalRank.h"

namespace db
{
  class MedalBase : public DataBase<Rank>
  {
  public:
    MedalBase()
    :DataBase("data/medal.format")
    ,medals(elements)
    {}

    virtual ~MedalBase() {}
    virtual auto pack  (Rank*        object) -> dat::Object override;
    virtual auto unpack(dat::Object& object) -> Rank*       override;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* medals;
  };
}