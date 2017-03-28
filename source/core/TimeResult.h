#pragma once

#include "Result.h"
#include "../tool/Time.h"

class TimeResult : public Result
{
private:
  dat::Time timeStamp_;
public:
  auto GetTimeStamp() -> dat::Time;
};