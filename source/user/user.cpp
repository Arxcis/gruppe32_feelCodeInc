//
// @file    user.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the user-module. Used for testing
//          components of the user-module.
//

#include <stdio.h>  
#include <stdlib.h>

enum Entity
{ 
  NATION,
  ATHLETE,
  SPORT,
  EVENT,
};

// @namespace app
// @brief     API that the user-level code can use to communicate with,
//              application layer.
// 
namespace app 
{ 
  template<class T, class S>
  bool post(
    Entity entity, 
    const T id, 
    const S field);

  template<class T, class S>
  bool add(
    Entity entity,
    const T id,
    const S tuple);

  template<class T>
  bool remove(
    Entity entity,
    const T id);

  template<class T, class S>
  const S get(
    Entity entity,
    const T id);

  void quit();
};


int main()
{
  printf("Hei\n");
  return 0;
}