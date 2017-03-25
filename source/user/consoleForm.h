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

#include "../tool/stream.h"


namespace form
{
  auto nation() ->std::vector<std::string>*;
  auto participant() ->std::vector<std::string>*;
  auto sport() ->std::vector<std::string>*;
  auto event() ->std::vector<std::string>*;

  int nationField(std::vector<std::string>*, const int index);     
  int participantField(std::vector<std::string>*, const int index);
  int sportField(std::vector<std::string>*, const int index);      
  int eventField(std::vector<std::string>*, const int index);      
}