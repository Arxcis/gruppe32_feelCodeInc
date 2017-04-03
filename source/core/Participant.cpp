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

  printf("\n   =====   Participant   =====    ");  

  printf("\n\nNationality:\t%s\nParitcipantID:\t%d", (char*)nation_, ID_);
  contact_.display();
}
