#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"
#include "TimeResult.h"
#include "Result.h"

namespace dat { namespace packing
{
  Contact    unpackContact     (const Field&  name_, const Field & phone_, const Field & mailAddress_);
  Time       unpackTime        (const Field&  time_);
  Date       unpackDate        (const Field&  date_);
  Medals     unpackMedals      (const Field&  medals_);
  Result     unpackPointResult (const Object& pointRes_);
  TimeResult unpackTimeResult  (const Object& timeRes_);
}}
