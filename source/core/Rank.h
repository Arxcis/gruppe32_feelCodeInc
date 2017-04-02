#pragma once

#include "ListTool2B.h"
#include "../tool/char3.h"

class Rank : public NumElement
{
public:
  Rank(int value, dat::char3 nation);
protected:
  int value_;         //poeng/medaljer
  dat::char3 nation_;
};