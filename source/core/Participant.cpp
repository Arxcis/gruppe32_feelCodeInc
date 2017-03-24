#include "Participant.h"

int Participant::getID()
{
	return ID_;
}

dat::Contact Participant::getContact()
{
	return contact_;
}

char3 Participant::getNation()
{
	return nation_;
}
