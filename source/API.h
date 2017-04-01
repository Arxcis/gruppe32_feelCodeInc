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
#include "core/database/ParticipantBase.h"
#include "core/database/SportBase.h"
#include "core/database/RankBase.h"

// @class API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              database.
// 
class API 
{ 
public:
  bool add       (const dat::Object& object);
  auto update    (const Entity entity, const dat::Object& object) -> const dat::Object;
  bool remove    (const Entity entity, const std::string& id);
  auto get       (const Entity entity, const std::string& id) -> const dat::Object;
  auto getAll    (const Entity entity)                 -> const dat::Container;

  auto getStarts (const dat::Field& id)  -> const dat::Object;
  auto getResults(const dat::Field& id)  -> const dat::Object;
  auto getPoints () -> const dat::Container;
  auto getMedals () -> const dat::Container;
  void quit();

  API();
  ~API(){}
private:
  void loadAllBases();

  //
  // All the bases
  //
  db::NationBase      nationBase_;     
  db::ParticipantBase participantBase_;         
  db::SportBase       sportBase_;        
  db::RankBase        pointBase_;     
  db::RankBase        medalBase_;      
  dat::Container      dbContainerCache[6];

};
