#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"

namespace dat { namespace packing
{
  Object* packContact(const std::string & name_, const std::string & phone_, const std::string & mailAddress_);
  auto packInt(const int myint)     -> const std::string;
  auto packTime(const Time& time)       -> std::string;
  auto packDate(const Date& date)       -> std::string;
  auto packMedals(const Medals& medals) -> std::string;
}}
