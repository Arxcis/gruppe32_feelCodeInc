#pragma once
//
// @file    tool/Contact.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   A struct that holds Contact data to Participants
//

#include <string>

namespace dat 
{
  struct Contact 
  {
    std::string name;
    std::string address;
    std::string phone;

    Contact();
  };
}