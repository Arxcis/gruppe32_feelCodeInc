#include "NationBase.h"

Nation * NationBase::unpack(dat::Object * object)
{
  dat::Object obj = *object;
  dat::char3 shortName = obj[1].second.c_str();
  std::string name = obj[2].second;
  int participants = std::stoi(obj[3].second);
  dat::Contact contact = *dat::unpacking::unpackContact(obj[4], obj[5], obj[6]);
  return new Nation(shortName, name, contact, participants);
}
