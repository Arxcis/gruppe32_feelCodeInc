#pragma once
//
// @file    user/Console.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   User-interface class. Basic Console/shell 
//

#include <assert.h>
#include <iostream>

// @local files
#include "../enum.h"  // @global dependency fysh og fy
#include "../API.h"   // @global dependency
#include "ConsoleMenu.h"

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
  API api_;
  static bool instantiated_;
  menu::ConsoleMenu* menuState;

  static const int maxStates_ = 1;
  menu::ConsoleMenu* allStates[maxStates_] = 
  {
    new menu::Begin(),
  };
};
