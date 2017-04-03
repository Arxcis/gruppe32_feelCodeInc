#pragma once
//
// @file    core/Dicipline.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Dicipline is stored within
//

#include <string>
#include "../tool/Time.h"
#include "../tool/Date.h"

struct Dicipline
{
  std::string name = 0;
  dat::Time time   = {0,0,0};
  dat::Date date   = {0,0,0};
};
