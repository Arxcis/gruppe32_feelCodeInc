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

namespace objectView
{
  inline 
  void field(const dat::Field);
  
  void nation(const dat::Object* nation,           int startIndex);
  void participant(const dat::Object* participant, int startIndex);
  void sport(const dat::Object* sport,             int startIndex);
  void dicipline(const dat::Object* dicipline,     int startIndex);
}