//
// @file    tool/Contact.cpp
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Contact data to Participants
//

#include "Contact.h"

using namespace dat;

dat::Contact::Contact()
{}

Contact::Contact(
  std::string name_, 
  std::string address_, 
  std::string phone_)
:name(name_)
,address(address_)
,phone(phone_)
{}

void dat::Contact::display()
{
  printf("Name:\t%s\nAddress:\t%s\nPhone:\t%s\n", name.c_str(), address.c_str(), phone.c_str());
}


