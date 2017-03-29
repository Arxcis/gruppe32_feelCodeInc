#pragma once
//
// @file    user/consoleForm.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Used to get data from user, and store it in an object
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "../tool/stream.h"
#include "../tool/typedef.h"


namespace form
{
  auto object(const std::string& type) ->dat::Object*;
  void field(dat::Field& field);

  void startList();
  void resultList();    
}