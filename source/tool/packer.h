#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"

namespace dat { namespace packing
{
  Object * packContact(const std::string & name_, const std::string & phone_, const std::string & mailAddress_);
  Object * packTime(const Field & time_);
  Object * packDate(const Field & date_);
  Object * packMedals(const int & medals);
}}