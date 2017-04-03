#include "Participant.h"

int Participant::getID()
  { return ID_; }

auto Participant::getContact() -> dat::Contact
  {	return contact_; }

auto Participant::getNation() -> dat::char3
  {	return nation_; }

auto Participant::getSex() -> std::string
  { return sex_; }

void Participant::display()
{
  contact_.display();
  printf("Nationality:\t%s\nParitcipantID:\t%d\n", (char*)nation_, ID_);
}
