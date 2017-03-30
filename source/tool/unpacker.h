#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"

namespace dat { namespace unpacking
{
  Contact* contact(const Field & name_, const Field & phone_, const Field & address_);
  Time* time(const Field & time_);
  Date* date(const Field & date_);
  Medals* medals(const Field & medals);
}}