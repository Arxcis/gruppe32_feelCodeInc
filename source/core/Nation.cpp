#include "Nation.h"

Nation::Nation(dat::char3 shortName, std::string name, dat::Contact contact, int participantCount) : 
  TextElement(shortName),
  shortName_(shortName), 
  name_(name), 
  contact_(contact), 
  participantCount_(participantCount){}

Nation::~Nation()
{}

auto Nation::getShortName() const -> dat::char3
{ return shortName_; }

auto Nation::getName() const -> std::string
{ return name_; }

auto Nation::getContact() const -> dat::Contact
{	return contact_; }

int Nation::getParticipantCount() const
{	return participantCount_; }

void Nation::display()
{
  printf("\n   =====   Nation   =====    "); 
  printf("\nNation Code:\t%s\nNation Name:\t%s\nParticipants:\t%d\n", (char*)shortName_, name_.c_str(), participantCount_);
  contact_.display();
}
