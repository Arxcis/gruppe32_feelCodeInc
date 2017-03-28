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
#include <string>

#include "MenuState.h"
#include "consoleMenu.h"
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
  int begin();
  
  int nationBase();
  int participantBase();
  int sportBase();
  int listBase();

  int pointStats();
  int medalStats();

  int sport();
  int nation();
  int participant();
  int dicipline();

  int deleteDicipline();
  int deleteList();
}