#include "Participant.h"

Participant::Participant(int ID, dat::Contact contact, dat::char3 nation, Participant::Gender gender) :
ID_(ID), contact_(contact), nation_(nation), gender_(gender){}

int Participant::getID()
{ return ID_; }

auto Participant::getContact() -> dat::Contact
{	return contact_; }

auto Participant::getNation() -> dat::char3
{	return nation_; }

Participant::Gender Participant::getGender()
{ return gender_; }

void Participant::display()
{
  contact_.display();
  printf("Nationality:\t%s\nParitcipantID:\t%d\n", (char*)nation_, ID_);
}
