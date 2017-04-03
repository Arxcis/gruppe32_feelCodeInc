#include "Participant.h"

int Participant::getID() const
  { return ID_; }

auto Participant::getContact() const -> dat::Contact
  {	return contact_; }

auto Participant::getNation() const -> dat::char3 
  {	return nation_; }

auto Participant::getSex() const -> std::string 
  { return sex_; }

void Participant::display()
{

  printf("\n   =====   Participant   =====    ");  

  printf("\n\nNationality:\t%s\nParitcipantID:\t%d", (char*)nation_, ID_);
  contact_.display();
}
