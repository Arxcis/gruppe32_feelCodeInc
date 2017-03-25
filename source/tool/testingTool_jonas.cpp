//
// @file    tool/testingTool_jonas.cpp
// @repo    gruppe32
// @created 23.03.1q7 by Jonas
// @brief   Main hub of the tool-module. Used for testing
//          components of the tool-module.
//

// @foreign
#include <iostream>

// uncomment to disable assert()
// #define NDEBUG
#include <assert.h>

// @local files
#include "Contact.h"
#include "Medals.h"
#include "Date.h"
#include "Time.h"


void testContact()
{
  dat::Contact contact(
    "Jonas Solsvik",
    "Snorres Veg 2a",
    "+47 45200864");

  std::cout << contact.name << std::endl;
}

void testMeasureClasses()
{
  dat::Medals medal1 { 1,2,3 };
  dat::Medals medal2 { 2,1,0 };
  dat::Medals medal3 { 0,0,100 };
  dat::Medals medal4 { 1,2,3 };

  assert(medal1.castToInt() >= medal3.castToInt());
  assert(medal1.castToInt() <= medal2.castToInt() );
  assert(medal1.castToInt() >= medal3.castToInt() );
  assert(medal1.castToInt() == medal4.castToInt() );

  std::cout << "Medal-int:" << medal1.castToInt() << std::endl;

  dat::Date date = {1,2,3};
  std::cout << "Date-int:" << date.castToInt() << std::endl;
  
  dat::Time time = {1,2,3};
  std::cout << "Time-int:" << time.castToInt() << std::endl;
}


int main()
{
  testContact();
  testMeasureClasses();
  return 0; 
}
