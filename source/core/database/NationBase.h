#pragma once

#include "../Nation.h"
#include "../../tool/Unpacker.h"
#include "DataBase.h"
namespace db
{
  class NationBase : public DataBase<Nation>
  {
  public:
    NationBase();
    virtual ~NationBase(){}
    // Inherited via DataBase
    virtual Nation * unpack(dat::Object * object) override;
    auto getContainer() -> const dat::Container;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List& nations; //aliasing the list
    const std::string baseFile = "data/nation.format";
  };

}
