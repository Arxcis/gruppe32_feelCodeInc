#include "ConsoleMenu.h"
#include <string>


int menu::ConsoleMenu::getNext(int userInput)
{
  return mapNext_[userInput];
}

void menu::Begin::view(){}

/*void menu::NationBase::view(){}
void menu::ParticipantBase::view(){}
void menu::SportBase::view(){}
void menu::ListBase::view(){}

void menu::Nation::view(){}
void menu::Participant::view(){}
void menu::Sport::view(){}
void menu::Dicipline::view(){}

void menu::NewNation::view(){}
void menu::NewParticipant::view(){}
void menu::NewSport::view(){}
void menu::NewDicipline::view(){}

void menu::EditNation::view(){}
void menu::EditParticipant::view(){}
void menu::EditSport::view(){}
void menu::EditDicipline::view(){}

void menu::DeleteDicipline::view(){}
void menu::DeleteList::view(){}

void menu::AppendList::view(){}
void menu::AppendResult::view(){}

void menu::PointStats(){}
void menu::MedalStats(){}*/


