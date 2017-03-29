#pragma once
//
// @file    user/Console.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   User-interface class. Basic Console/shell 
//

#include <assert.h>
#include <iostream>
#include <string>

// @local files
#include "../tool/stream.h"
#include "ConsoleMenu.h"
#include "MenuState.h"

//
// @class Console
//  @brief This class i instancieted once (Singleton-ish)
//   Console launches the Console-user-level application.
//
class Console
{
public:
  Console();
  ~Console();
  int run();

private:
  
  static bool instantiated_;
  static const int maxMenus_ = 15;

  //
  // @setup of all the connections between each menu.
  //
  menu::ConsoleMenu* currentMenu_;
  menu::ConsoleMenu* allMenus_[maxMenus_]; 
};
