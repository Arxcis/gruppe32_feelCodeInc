#pragma once

// @file    core/Nation.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Nation is stored within, shortName is PK
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

	auto getName();
	//ScoreType getScoreType();
	//BetterArray getEvents();
};