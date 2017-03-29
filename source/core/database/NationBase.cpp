#include "NationBase.h"

NationBase::NationBase(){}
NationBase::~NationBase()
  { delete elements; };

bool NationBase::add(dat::Object* object) 
{
  //Unpacking
  dat::Object obj = *object;
  dat::char3 shortName = "YAY";
  std::string name = obj[2].second;
  int participants = std::stoi(obj[3].second);
  dat::Contact contact = *dat::unpacking::UnpackContact(obj[4], obj[5], obj[6]);
  return nations->add(new Nation(shortName, name, contact, participants)); //if this fails, shouldn't the nation be deleted?
}
