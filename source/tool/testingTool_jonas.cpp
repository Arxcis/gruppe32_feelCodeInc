//
// @file    tool/testingTool_jonas.cpp
// @repo    gruppe32
// @created 23.03.1q7 by Jonas
// @brief   Main hub of the tool-module. Used for testing
//          components of the tool-module.
//

#include <iostream>
#include "Contact.h"
#include "Measure.h"
#include "Medals.h"

void testContact()
{
  dat::Contact contact;
  contact.name = "Jonas";
  std::cout << contact.name << std::endl;
}

void testMeasure()
{

}

void testMedals()
{
  dat::Medals medals;
}

void testTime(){}
void testDate(){}

int main()
{
  testContact();
  testMeasure();
  testMedals();
  testTime();
  testDate();
  return 0; 
}