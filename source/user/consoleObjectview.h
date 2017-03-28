#pragma once
//
// @file    user/consoleObject.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   Displays all the objects in the system
//  

#include <string>
#include <vector>
#include <iostream>

#include "ConsoleMenu.h"

namespace object
{ 
  inline void printField(const int index, const dat::Field& field);
  void view(const dat::Object* view,           int startIndex);
}