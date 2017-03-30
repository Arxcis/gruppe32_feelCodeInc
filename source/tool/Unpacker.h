#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"

namespace dat { namespace unpacking
{
  Contact* unpackContact(const Field & name_, const Field & phone_, const Field & address_);
  Time* unpackTime(const Field & time_);
  Date* unpackDate(const Field & date_);
  Medals* unpackMedals(const Field & medals);
}}