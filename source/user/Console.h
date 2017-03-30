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
#include "../enum.h"
#include "../tool/typedef.h"
#include "../tool/stream.h"
#include "../API.h"
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
  void switchMenu();

private:
  
  static bool instantiated_;
  static const int maxMenus_ = 16;

  //
  // @setup of all the connections between each menu.
  //
  API api_;
  int currentMenu_;
  dat::TransitionMap map_;
  menu::ConsoleMenu* allMenus_[maxMenus_]; 


  //
  // Setting up temp variables
  //
  dat::Container container;
  dat::Object       object;
  dat::Field         field;

  dat::Container& containerRef = container;
  dat::Object&       objectRef = object;
  dat::Field&         fieldRef = field;
};
