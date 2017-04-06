#pragma once
//
// @file    tool/Contact.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Contact data to Participants
//

#include <string>
#include <iostream>

namespace dat 
{
  struct Contact 
  {
    std::string name = "";
    std::string mailAddress = "";
    std::string phone = "";

    Contact(
      std::string name_, 
      std::string phone_,
      std::string mailAddress_)
    :name(name_)
    ,mailAddress(mailAddress_)
    ,phone(phone_)
    {}

    void display();
  };
}
