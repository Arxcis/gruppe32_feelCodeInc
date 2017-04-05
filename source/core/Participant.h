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
  std::string sex_;

public:
  Participant(size_t ID, dat::Contact contact, dat::char3 nation, std::string sex)
  :NumElement(ID)
  ,ID_(ID)
  ,contact_(contact)
  ,nation_(nation)
  ,sex_(sex)
  {}

  int getID() const;
  auto getContact() const -> dat::Contact;
  auto getNation()  const -> dat::char3;
  auto getSex()     const -> std::string;

  // Inherited via TextElement
  virtual void display() override;

};
