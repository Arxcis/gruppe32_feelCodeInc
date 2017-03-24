//
// @file    tool/testingTool_jonas.cpp
// @repo    gruppe32
// @created 23.03.1q7 by Jonas
// @brief   Main hub of the tool-module. Used for testing
//          components of the tool-module.
//

#include <iostream>
#include "Contact.h"
#include "Medals.h"
#include "Date.h"
#include "Time.h"

void testContact()
{
  dat::Contact contact;
  contact.name = "Jonas";
  std::cout << contact.name << std::endl;
}

void testMeasureClasses()
{
  dat::Medals medals = { 1,2,3 };
  std::cout << "Medal-int:" << medals.castToInt() << std::endl;

  dat::Date date = {1,2,3};
  std::cout << "Date-int:" << date.castToInt() << std::endl;
  
  dat::Time time = {1,2,3};
  std::cout << "Time-int:" << time.castToInt() << std::endl;
}


int main()
{
  testMeasureClasses();
  return 0; 
}
