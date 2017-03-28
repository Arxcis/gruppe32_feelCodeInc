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
  
  void nation(const std::vector<std::string>* nation);
  void participant(const std::vector<std::string>* participant);
  void sport(const std::vector<std::string>* sport);
  void dicipline(const std::vector<std::string>* dicipline);
}