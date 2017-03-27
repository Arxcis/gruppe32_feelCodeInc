#pragma once
//
// @file    user/consoleList.h
// @repo    gruppe32
// @created 26.03.17 by Jonas
// @brief   List generator for the console app.
//          

#include <iostream>
#include <vector>
#include <string>

namespace list
{
  void nations      (const std::vector<std::vector<std::string>>* containers);
  void participants (const std::vector<std::vector<std::string>>* containers);
  void sports       (const std::vector<std::vector<std::string>>* containers);
  void diciplines   (const std::vector<std::vector<std::string>>* containers);
  void diciplineList(const std::vector<std::vector<std::string>>* containers);
}