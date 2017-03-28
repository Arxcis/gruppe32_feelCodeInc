#include "Nation.h"

auto Nation::GetShortName() -> dat::char3
{ return shortName_; }

auto Nation::GetName() -> std::string
{ return name_; }

auto Nation::GetContact() -> dat::Contact
{	return contact_; }

int Nation::GetParticipantCount()
{	return participantCount_; }
