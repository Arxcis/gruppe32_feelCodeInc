#include "Participant.h"

int Participant::getID()
{ return ID_; }

auto Participant::getContact() -> dat::Contact
{	return contact_; }

auto Participant::getNation() -> dat::char3
{	return nation_; }
