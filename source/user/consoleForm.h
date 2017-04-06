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

  void singleField(dat::Object& object, const std::string& fieldKey);
  void object(const std::string type);
  bool thisField(dat::Field& field, bool submit=true);
  
  void appendDicipline(dat::Object sport); 

  void startList(
    const std::string& diciplineID,
    const dat::Object& sport);

  void resultList(
    const std::string&    diciplineID,
    const dat::Object&    sport, 
    const dat::Container& starts);

  bool askAgain (bool valid_, const std::string& value, const std::string& errorMessage);
}

