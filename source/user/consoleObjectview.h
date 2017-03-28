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

#include "consoleMenu.h"

namespace objectView
{
  inline 
  void field(const std::string key, const std::string value);
  
  void nation(const std::vector<std::string>* nation,           int startIndex);
  void participant(const std::vector<std::string>* participant, int startIndex);
  void sport(const std::vector<std::string>* sport,             int startIndex);
  void dicipline(const std::vector<std::string>* dicipline,     int startIndex);
}