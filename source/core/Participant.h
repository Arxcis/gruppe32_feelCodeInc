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
public:
  enum Gender
  { MALE, FEMALE, OTHER };
private:
  int ID_;
  dat::Contact contact_;
  dat::char3 nation_;
  Gender gender_;
public:
  Participant(int ID, dat::Contact contact, dat::char3 nation, Gender gender);

  int getID();
  auto getContact() -> dat::Contact;
  auto getNation() -> dat::char3;
  Gender getGender();

  // Inherited via TextElement
  virtual void display() override;

};
