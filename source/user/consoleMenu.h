#pragma once
//
// @file    user/consoleMenu.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   Has namespace menu, which produces the graphical
//          representation of all the menus in the console
//          application.
//

#include <iostream>   // stringstream
#include "MenuState.h"
#include <string>

//
// @namespace menu
// @brief One important thing to note about these functions is that
//        , every function returns a choice/command, from the user.
//        This command chould be processed by the Console object.
//
namespace menu
{  
  // Helper functions
  inline void header(std::string);
  inline void footer();
  inline void newPage();

  // Menu functions
  MenuState begin();
  
  int nationBase();
  int participantBase();
  int sportBase();

  int sport();
  int nation();
  int participant();
  //int eventBase();
  //int event();
}