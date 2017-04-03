//
// @file    tool/Contact.cpp
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Contact data to Participants
//

#include "Contact.h"

using namespace dat;


void dat::Contact::display()
{
  printf("\nName:\t%s\nAddress:\t%s\nPhone:\t%s\n", name.c_str(), mailAddress.c_str(), phone.c_str());
}


