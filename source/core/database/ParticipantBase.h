#pragma once

#include "../Participant.h"
#include "../../tool/Unpacker.h"
#include "DataBase.h"
namespace db
{
  class ParticipantBase : public DataBase<Participant>
  {
  public:
    ParticipantBase();
    virtual ~ParticipantBase(){}
    // Inherited via DataBase
    virtual dat::Object * pack(Participant * participant) override;
    virtual Participant * unpack(dat::Object * object) override;
    auto getContainer() -> const dat::Container;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List& participants; //aliasing the list
    const std::string baseFile = "data/participant.format";

  };
}
