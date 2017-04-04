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

#include "enum.h"
#include "core/database/NationBase.h"
#include "core/database/ParticipantBase.h"
#include "core/database/SportBase.h"
#include "core/database/MedalBase.h"
#include "core/database/PointBase.h"

//
// @class API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              database.
// 
class API 
{ 
public:
  bool add       (const dat::Object& object);
  bool remove    (const Entity entity, const std::string& id);
  void update    (const dat::Object& object);
  void updateAll (const dat::Container& list, const std::string& id="");
  auto get       (const Entity entity, const std::string& id)     -> const dat::Object;
  auto getAll    (const Entity entity, const std::string& id="")  -> const dat::Container;

  void quit();

  API();
  ~API(){}

private:
  void loadAllBases();

  //
  // All the bases
  //
  db::NationBase       nationBase_;
  db::ParticipantBase  participantBase_;
  db::SportBase        sportBase_;
  db::PointBase        pointBase_;
  db::MedalBase        medalBase_;
  dat::Container       dbContainerCache[6];

};
