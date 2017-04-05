//
// @file    main.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   main.cpp
//

#include <stdio.h>
#include "user/Console.h"
#include "user/testingUser_jonas.h"

void MacSleep(size_t time)
{
#ifndef WIN32
  sleep(time);
#endif
}

int main()
{ 
  
  std::cout << "Booting system......\n"; MacSleep(10);
  Console console;
  console.run();

  return 0;
}
