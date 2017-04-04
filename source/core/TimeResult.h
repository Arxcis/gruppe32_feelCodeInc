#pragma once

#include "Result.h"
#include "../tool/Time.h"

class TimeResult : public Result
{
private:
  dat::Time timeStamp_;
    
public:
  TimeResult(const int ID, dat::Time time)
  :Result(ID, time.castToInt())
  ,timeStamp_(time)
  {}

  auto getTimeStamp() -> dat::Time;
};
