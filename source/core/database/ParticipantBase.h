#pragma once

#include "../Participant.h"
#include "DataBase.h"
namespace db
{
  class ParticipantBase : public DataBase<Participant>
  {
  public:
    ParticipantBase()
    :DataBase("data/participant.format")
    ,participants(*elements)
    {}

    virtual ~ParticipantBase(){}
    virtual auto pack  (Participant* participant) -> dat::Object  override;
    virtual auto unpack(dat::Object& object)      -> Participant* override;

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List& participants;         //aliasing the list
  };
}
