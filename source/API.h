#pragma once
//
// @file    API.h
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the application. Glues together
//           Core-module with the User-module

#include <tuple>
#include <vector>
#include <string>
#include <stdio.h>  
#include <stdlib.h>

//#include "data/testData.h"


enum Entity 
{
  NATION,
  PARTICIPANT, 
  SPORT,
  EVENT,
};

// @namespace API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              application layer.
// 
namespace API 
{ 
  bool add    (std::vector<std::string>* container);
  bool addAll (std::vector<std::vector<std::string>>* containers);
  bool update (std::vector<std::string>* container);
  bool remove (Entity entity, int id);
  auto get    (Entity entity, int id) -> std::vector<std::string>*;
  auto getAll (Entity entity)  -> std::vector<std::vector<std::string>>*;
  void quit();
};
