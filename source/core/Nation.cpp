#include "Nation.h"

auto Nation::getShortName() -> dat::char3
{ return shortName_; }

auto Nation::getName() -> std::string
{ return name_; }

auto Nation::getContact() -> dat::Contact
{	return contact_; }

int Nation::getParticipantCount()
{	return participantCount_; }
