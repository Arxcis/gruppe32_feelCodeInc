#include "Nation.h"

Nation::Nation(dat::char3 shortName, std::string name, dat::Contact contact, int participantCount) : 
  /*TextElement(shortName) @TODO make a char3 to char conversion (implicit pls),*/
  shortName_(shortName), name_(name), contact_(contact), participantCount_(participantCount){}

Nation::~Nation()
{}

auto Nation::getShortName() -> dat::char3
{ return shortName_; }

auto Nation::getName() -> std::string
{ return name_; }

auto Nation::getContact() -> dat::Contact
{	return contact_; }

int Nation::getParticipantCount()
{	return participantCount_; }
