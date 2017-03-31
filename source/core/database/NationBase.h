#pragma once

#include "../Nation.h"
#include "../../tool/Unpacker.h"
#include "DataBase.h"
namespace db
{
  class NationBase : public DataBase<Nation>
  {
    List& nations; //aliasing the list
  public:
    NationBase();
    virtual ~NationBase(){}
    // Inherited via DataBase
    virtual Nation * unpack(dat::Object * object) override;
    virtual dat::Container readFile(const std::string& filepath) override;
  };

}
