#pragma once
//
// @file    tool/Time.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Time in hour minutes and seconds
//

#include "Measure.h"

namespace dat
{
  struct Time : public Measure
  {
    int hour;
    int minute;
    int second;

    Time(int hour_, int minute_, int second_);
    virtual ~Time();

    virtual void display() override;
    virtual int  castToInt() override;
  };
}