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
  static const int maxMenus_ = 12;

  menu::ConsoleMenu* currentMenu_;
  menu::ConsoleMenu* allMenus_[maxMenus_] = 
  {
    new menu::Begin           ({ -1,1,2,3,4,5 }),      // 0
    new menu::NationBase      ({ 0,9,6        }),      // 1
    new menu::ParticipantBase ({ 0,10,7        }),      // 2
    new menu::SportBase       ({ 0,11,8        }),      // 3
    new menu::PointStats      ({ 0,4          }),      // 4
    new menu::MedalStats      ({ 0,5          }),      // 5

    new menu::Nation          ({ 1,6          }),      // 6
    new menu::Participant     ({ 2,7          }),      // 7
    new menu::Sport           ({ 3,8          }),      // 8

    new menu::NewNation       ({ 1,  9, 6     }),      // 9
    new menu::NewParticipant  ({ 2, 10, 7     }),      // 10
    new menu::NewSport        ({ 3, 11, 8     }),      // 11
  };
};
