#pragma once
//
// @file    tool/Medals.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Medals statistics
//

#include "Measure.h"

namespace dat 
{
  struct Medals : public Measure
  {
    int gold;
    int silver;
    int bronze;

    Medals(int gold_, int silver_, int bronze_);
    virtual ~Medals();

    virtual void display() override;
    virtual int castToInt() override;
  };
}


