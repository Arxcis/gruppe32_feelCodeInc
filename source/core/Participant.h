#pragma once

// @file    core/Participant.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Participant is stored within.

#include "ListTool2B.h"
#include "../tool/Contact.h"
#include "../tool/char3.h"

class Participant : public NumElement
{
private:
  int ID_;
  dat::Contact contact_;
  dat::char3 nation_;
  //Gender gender;
public:
  int getID();
  auto getContact() -> dat::Contact;
  auto getNation() -> dat::char3;
  //Gender getGender();
};
