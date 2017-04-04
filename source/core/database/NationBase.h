#pragma once

//
// @file    core/database/NationBase.h
//

#include "../Nation.h"
#include "DataBase.h"
namespace db
{
  class NationBase : public DataBase<Nation>
  {
  public:
    NationBase() 
    :DataBase(nationsFile)
    ,nations(elements)
      { readContainer(); }

    virtual ~NationBase(){}
    virtual auto pack  (const Nation* object) -> dat::Object override;
    virtual auto unpack(dat::Object&  object) -> Nation*     override;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* nations;
    //aliasing the list
  };

}
