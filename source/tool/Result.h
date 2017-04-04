#pragma once


// @remove MAYBE REDUDANT !!!! @TODO

// @file    core/Participant.h
// @repo    gruppe32
// @created 28.03.17 by Halvor
// @brief   All data relevant to Results are stored within.

#include <string>
#include "../tool/typedef.h"
#include "ListTool2B.h"

class Result : public NumElement 
{
protected:
	int ID_;
	int value_;

public:
  Result(const int ID, const int value)
  :ID_(ID)
  ,value_(value)
  {}

  int getID();
  int getValue();
  void display();
};