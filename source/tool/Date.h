#pragma once
//
// @file    tool/Date.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds the Date in year, month, days
//

#include "Measure.h"

namespace dat
{
  struct Date : public Measure
  {
    int year;
    int month;
    int day;

    Date(int year_, int month_, int day_);
    virtual ~Date();

    virtual void display() override;
    virtual int  castToInt() override;
  };
}