#include "Participant.h"

int Participant::GetID()
{ return ID_; }

auto Participant::GetContact() -> dat::Contact
{	return contact_; }

auto Participant::GetNation() -> dat::char3
{	return nation_; }
