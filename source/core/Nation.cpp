#include "Nation.h"

char3 Nation::getShortName()
{
	return shortName_;
}

auto Nation::getName() -> std::string
{
	return name_;
}

/*
Contact Nation::getContact()
{
	return contact_;
}
*/

int Nation::getParticipantCount()
{
	return participantCount_;
}
