#pragma once

#include "typedef.h"
#include "Contact.h"
#include "Time.h"
#include "Date.h"
#include "Medals.h"

namespace dat { namespace unpacking
{
  Contact* UnpackContact(const Field & name, const Field & phone, const Field & address);
  dat::Time* UnpackTime(const Field*);
}}