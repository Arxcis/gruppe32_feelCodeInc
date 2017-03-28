#pragma once
// @file    core/Event.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Event is stored within
//

#include <string>
#include "../tool/Time.h"
#include "../tool/Date.h"
#include "../tool/array.h"
#include "Participant.h"
#include "Result.h"

class Event
{
private:
	std::string name_;
  dat::Time time_;
  dat::Date date_;

	dat::array<Participant> participants;
  dat::array<Result> result;
public:

};
