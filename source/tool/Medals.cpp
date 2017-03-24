//
// @file    tool/Medals.cpp
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Medals statistics
//

#include "Medals.h"

using namespace dat;

void Medals::display(){}
int  Medals::castToInt()
{
  return ((gold*1001*1001) + (silver*1001) + bronze);
}