//
// @file    tool/tool.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the tool-module. Used for testing
//          components of the tool-module.
//

#include <iostream>
#include <Contact.h>

void testContact()
{
  Contact contact;

  contact.name = "Jonas";
  std::cout << contact.name << std::endl;
}

int main()
{
  testContact();
  return 0; 
}