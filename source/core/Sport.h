#pragma once

// @file    core/Sport.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Sport is stored within.
//

#include <string>
#include "../tool/typedef.h"
#include "ListTool2B.h"

class Sport : public TextElement
{
private:
	std::string name_;
	//ScoreType scoreType_;
	//BetterArray dicipline;

public:
	//	GETTERS

    auto GetName() -> std::string;
	//ScoreType GetScoreType();
	//BetterArray GetDiciplines();
};
