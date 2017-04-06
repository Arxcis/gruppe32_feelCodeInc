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

// SLeep include cross platform
#ifdef WIN32
//  #include "windows.h"
#else
  #include "unistd.h"
#endif

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
  API& api_ = API::getInstance();
  static bool instantiated_;
  static const int maxMenus_ = 23;

  //
  // Static state variables
  //
  menu::ConsoleMenu* allMenus_[maxMenus_]; 

  //
  // Dynamic state variables. Keeps track of the state of the front-end.
  //
  int input = 0;
  int selectedMenu = START_MENU;
  bool silentCommand = false;

  dat::TransitionMap currentMap;
  dat::Container     selectedContainer;
  dat::Object        selectedObject;
  dat::Container        selectedStarts;
  dat::Container        selectedResults;

  dat::Field         selectedField;
  std::string        selectedID = "";
  std::string        selectedDiciplineID = "";
};
