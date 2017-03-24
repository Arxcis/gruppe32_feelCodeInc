#pragma once

// @file    core/Sport.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Sport is stored within.
//

#include <string>
#include "../tool/char3.h"
#include "ListTool2B.h"

class Sport : TextElement
{
private:
	std::string name_;
	//ScoreType scoreType_;
	//BetterArray events;

public:
	//	GETTERS

    auto getName() -> std::string;
	//ScoreType getScoreType();
	//BetterArray getEvents();
};
