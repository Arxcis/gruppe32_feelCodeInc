#include "Nation.h"

char3 Nation::getShortName()
{
	return shortName_;
}

std::string Nation::getName()
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
