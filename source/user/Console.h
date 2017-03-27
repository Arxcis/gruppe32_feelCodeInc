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
#include "../enum.h"  // @global dependency fysh og fy
#include "../API.h"   // @global dependency
#include "../tool/stream.h"
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
  static const int maxMenus_ = 6;

  menu::ConsoleMenu* currentMenu_;
  menu::ConsoleMenu* allMenus_[maxMenus_] = 
  {
    new menu::Begin           ({ -1,1,2,3,4,5 }),      // 0
    new menu::NationBase      ({ 0,1,1        }),      // 1
    new menu::ParticipantBase ({ 0,2,2        }),      // 2
    new menu::SportBase       ({ 0,3,3        }),      // 3
    new menu::PointStats      ({ 0,4          }),      // 4
    new menu::MedalStats      ({ 0,5          }),      // 5

  };
};
