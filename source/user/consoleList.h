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
#include "../API.h"

namespace list
{
  void nations      (const dat::Container* container);
  void participants (const dat::Container* container);
  void sports       (const dat::Container* container);
  void diciplines   (const dat::Container* container);
  void diciplineList(const dat::Container* container);
}