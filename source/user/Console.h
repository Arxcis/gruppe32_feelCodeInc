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
#include "consoleMenu.h"
#include "consoleObjectview.h"
#include "consoleForm.h"
#include "MenuState.h"

//
// @class Console
//  @brief This class i instancieted once (Singleton-ish)
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
  MenuState menuState = BASE;     // The most recent command from the user
};