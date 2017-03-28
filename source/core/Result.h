#pragma once

// @file    core/Participant.h
// @repo    gruppe32
// @created 28.03.17 by Halvor
// @brief   All data relevant to Results are stored within.

#include <string>
#include "../tool/typedef.h"
#include "ListTool2B.h"

class Result : public NumElement 
{
private:
	std::string name_;
	int score_;
public:
	auto getName()->std::string;
  int getScore();
};