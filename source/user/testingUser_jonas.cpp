//
// @file    user/testingUser_jonas.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the user-module. Used for testing
//          components of the user-module.
//

#include <stdio.h>

// @local files
#include "Console.h"

int main()
{
    Console console;

  if(console.run())
  {
    printf("Program exited normally...\n");
  }
  else {
    printf("Program exited in an unexpected manner..\n");
  }

  printf("Hello from user module\n");
}
