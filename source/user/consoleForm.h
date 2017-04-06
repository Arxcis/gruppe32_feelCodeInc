#pragma once
//
// @file    user/consoleForm.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Used to get data from user, and store it in an object
//

#include <string>
#include <iostream>

#include "../tool/stream.h"
#include "../tool/typedef.h"
#include "../API.h"


namespace form
{ 

  void object(const std::string type);
  bool thisField(dat::Field& field, bool submit=true);
  
  bool askAgain(bool valid, const std::string& value, const std::string& errorMessage);
  void appendDicipline(dat::Object sport); 
  void startList(dat::Container& starts);
  void resultList(
    dat::Object&    sport, 
    dat::Container& starts, 
    dat::Container& results);

}

