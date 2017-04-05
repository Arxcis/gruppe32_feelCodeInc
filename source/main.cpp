//
// @file    main.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   main.cpp
//

#include <stdio.h>
#include "user/Console.h"
#include "user/testingUser_jonas.h"


int main()
{ 
  std::cout << "Booting system......\n"; sleep(1);
  Console console;
  console.run();

  testFormField();

  printf("Hei main.cpp\n");
  return 0;
}
