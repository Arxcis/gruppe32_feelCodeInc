#pragma once
//
// @file    API.h
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the application. Glues together
//           Core-module with the User-module

#include <stdio.h>  
#include <stdlib.h>
#include <../tool/typedef.h>

//#include "data/testData.h"
#include "enum.h"


// @class API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              database.
// 
class API 
{ 
public:
  bool add (dat::Object* object);

  bool addAll (dat::Container* container);

  bool update (dat::Object* object);

  bool remove (Entity entity, int id);
  auto get    (Entity entity, int id) -> dat::Object*;
  auto getAll (Entity entity)  -> dat::Container*;
  void quit();
  API(){};
private:
};
