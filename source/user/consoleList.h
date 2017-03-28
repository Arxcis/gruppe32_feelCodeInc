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
  void nations      (const std::vector<std::vector<std::string>>* containers, int step);
  void participants (const std::vector<std::vector<std::string>>* containers, int step);
  void sports       (const std::vector<std::vector<std::string>>* containers, int step);
  void diciplines   (const std::vector<std::vector<std::string>>* containers, int step);
  void diciplineList(const std::vector<std::vector<std::string>>* containers, int step);
}