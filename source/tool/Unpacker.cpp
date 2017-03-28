#include "Unpacker.h"

namespace dat { namespace unpacking
{
  Contact* UnpackContact(const Field & name, const Field & phone, const Field & address)
  { return new Contact(name.second, phone.second, address.second); }

}}