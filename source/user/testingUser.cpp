//
// @file    testingUser.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the user-module. Used for testing
//          components of the user-module.
//

#include <tuple>
#include <vector>
#include <string>
#include <stdio.h>  
#include <stdlib.h>
#include <ctime>

#include "testData.h"


enum Entity 
{
  NATION,
  ATHLETE, 
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
  bool remove (Entity entity, std::string id);
  auto get    (Entity entity, std::string id) -> std::vector<std::string>*;
  auto getAll (Entity entity)  -> std::vector<std::vector<std::string>>*;
  void quit();
};

//
// @namespace test - testdata
//
int main()
{ 
  srand(time(NULL));
  printf("Hei\n");
  printf("Hei\n");
  return 0;
}


namespace API 
{
  //
  // @function add()
  //
  bool add( std::vector<std::string>* container)
  {  return 1;  }


  bool addAll (std::vector<std::vector<std::string>>* containers) 
  { return 1; }

  //
  // @function edit()
  //
  bool update (std::vector<std::string>* container)
  {  return 1;  }

  //
  // @function remove()
  //
  bool remove(Entity entity, std::string id)
  {  return 1;  }

  //
  // @function get()
  //
  auto get(Entity entity, std::string id) -> std::vector<std::string>*
  {
    switch(entity)
    {
      case NATION: 
        return &test::nation;
      case ATHLETE:
        return &test::athlete;
      case SPORT:
        return &test::sport;
      case EVENT:
        return &test::event;
      default:
        return test::nulldata;
    }
  }

  //
  // @function getAll()
  //
  auto getAll(Entity entity)  -> std::vector<std::vector<std::string>>*
  {
    switch(entity)
    {
      case NATION: 
        return &test::nations;
      case ATHLETE:
        return &test::athletes;
      case SPORT:
        return &test::sports;
      case EVENT: 
        return &test::events;
      default: 
        return test::nulldatas;
    }
  }

  //
  // @function quit()
  //
  void quit()
  {
    
  }
}

