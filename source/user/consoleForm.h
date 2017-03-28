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
#include "../tool/typedef.h"


namespace form
{
  auto nation() ->dat::Object*;
  auto participant() ->dat::Object*;
  auto sport() ->dat::Object*;
  auto dicipline() ->dat::Object*;

  void nationField(dat::Object*, const int index);     
  void participantField(dat::Object*, const int index);
  void sportField(dat::Object*, const int index);      
  void diciplineField(dat::Object*, const int index);  

  void listAdd();
  void listResult();    
}