#pragma once

#include "../Participant.h"
#include "../../tool/Unpacker.h"
#include "DataBase.h"
namespace db
{
  class ParticipantBase : public DataBase<Participant>
  {
    List& participants; //aliasing the list
  public:
    ParticipantBase();
    virtual ~ParticipantBase(){}
    // Inherited via DataBase
    virtual Participant * unpack(dat::Object * object) override;
    virtual dat::Container readFile(const std::string& filepath) override;
  };
}
