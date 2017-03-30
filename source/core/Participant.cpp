#include "Participant.h"

int Participant::getID()
{ return ID_; }

auto Participant::getContact() -> dat::Contact
{	return contact_; }

auto Participant::getNation() -> dat::char3
{	return nation_; }

void Participant::display()
{
  contact_.display();
  printf("Nationality:\t%s\nParitcipantID:\t%s\n", (char*)nation_, ID_);
}
