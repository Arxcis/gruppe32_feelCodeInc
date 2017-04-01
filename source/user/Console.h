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
#include "MenuEnum.h"
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
  void displayMenu();
  inline int  clamp(const int input, const int max) const;

private:
  
  static bool instantiated_;
  static const int maxMenus_ = 23;

  //
  // Static state variables
  //
  API api_;
  menu::ConsoleMenu* allMenus_[maxMenus_]; 

  //
  // Dynamic state variables. Keeps track of the state of the front-end.
  //
  int input = 0;
  int selectedMenu = START;
  int diciplineIndex = 0;
  bool activeObject = false;

  dat::TransitionMap currentMap;
  dat::Container     selectedContainer;
  dat::Object        selectedObject;
  dat::Object        selectedList;
  dat::Field         selectedField;
  std::string        selectedID = "";

};
