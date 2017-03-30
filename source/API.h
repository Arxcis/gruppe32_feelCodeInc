#pragma once
//
// @file    API.h
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the application. Glues together
//           Core-module with the User-module

#include <stdio.h>  
#include <stdlib.h>
#include "tool/typedef.h"

//#include "core/file.h"   // file::readNations...
#include "enum.h"
#include "core/database/NationBase.h"

// @class API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              database.
// 
class API 
{ 
public:
  bool add       (dat::Object& object);
  bool update    (dat::Object& object);
  bool remove    (const Entity entity, dat::Field& id);
  auto get       (const Entity entity, dat::Field& id) -> dat::Object&;
  auto getAll    (const Entity entity)                -> dat::Container&;

  auto getStarts (const dat::Field id)  -> dat::Object&;
  auto getResults(const dat::Field id)  -> dat::Object&;
  auto getPoints () -> dat::Object&;
  auto getMedals () -> dat::Object&;
  void quit();

  API();
private:
  //
  // All the bases
  //
  //NationBase nationBase_;
  //void loadAllBases();
  //ParticipantBase participantBase_;
  //SportBase sportBase_;
};
