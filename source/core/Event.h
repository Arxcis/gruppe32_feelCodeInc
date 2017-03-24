#pragma once
// @file    core/Event.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Event is stored within
//

#include <string>
//#include "Time.h"
//#include "Date.h"
#include "../tool/array.h"
#include "Participant.h"
class Event
{
	std::string name_;
	dat::array<Participant, 0> participants;
	//dat::array<Results, 0> results;
};
