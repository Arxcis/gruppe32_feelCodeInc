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
#include "tool/Unpacker.h"

//
// @class API - Application Layer Interface
// @brief     API that the user-level code can use to communicate with,
//              database.
// 
class API 
{ 
public:
    // C++ 11         // @url http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
    // =======

    // We can use the better technique of deleting the methods
    // we don't want. We do this because we dont want more than 1 copy of our class.
    // The getInstance() method as implemented here with static API, does not work earlier than C++11
    API(API const&)             = delete; // Assign by () ->  delete
    void operator=(API const&)  = delete; // Assign by = ->  delete

    static API& getInstance()
    {
        static API instance; // Guaranteed to be destroyed. Instantiated on first use.
        return instance;
    }

  bool add       (const dat::Object object); //Add object to the base of objects type
  void remove    (const Entity entity, const std::string& id); //Remove the Object with the given ID of type entity
  void update    (const dat::Object& object);
  
  /*
  @params:
    list: the new data to fill into file.
    id: the id of the file. defaults to empty, as it's not used by most databases
  */
  void updateAll (const Entity entity, const dat::Container& list, const std::string& id="");

  bool find (const Entity entity, const std::string& id);
  auto get       (const Entity entity, const std::string& id)     -> const dat::Object;
  
  /*
  @params:
  entity: The type of data you want to extract.
  id: the id of the file. defaults to empty, as it's not used by most databases
  */
  auto getAll    (const Entity entity, const std::string& id="")  -> const dat::Container;

  void quit();

  ~API(){}

private:
  API();

  void updateMedals(const dat::Container& resultList);
  void updatePoints(const dat::Container& resultList);

  void loadAllBases();

  int parseToEntityType(const std::string& id);

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
