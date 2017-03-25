//
// @file    user/Console.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   User-interface class. Basic Console/shell 
//

#include <assert.h>
#include <iostream>

// @local files
#include "consoleMenu.h"
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
  static bool instantiated_;
  MenuState menuState = BASE;     // The most recent command from the user
};