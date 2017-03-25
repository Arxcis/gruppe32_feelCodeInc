#include "consoleForm.h"

std::vector<std::string> container;

auto form::nation() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Nation");
  std::string temp = "";

  while(!stream::readString("ContryCode[ex.NOR]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Name[ex.Norway]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readInt("NumberOfParticipants[ex.150]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("ContactName[ex.Jonas Solsvik]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readPhone("ContactPhone[ex.+4745200864]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readEmail("ContactMail[ex.jonas.solsvik@gmail.com]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);

  container = formBuilder;
  return &container;
}

auto form::participant() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Participant");
  std::string temp = "";

  while(!stream::readString("Name[ex.Jonas]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Phone[ex.+4745200864]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Mail[ex.jonas.solsvik@gmail.com]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("ContryCode[ex.NOR]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Gender[female=0, male=1]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);

  container = formBuilder;
  return &container;
}

auto form::sport() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Sport");
  std::string temp = "";

  while(!stream::readString("Name[ex.Fotball", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("ScoreType[medals=0, points=1]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);

  container = formBuilder;
  return &container;
}

auto form::event() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Event");
  std::string temp = "";

  while(!stream::readString("Name[ex.10km]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Time[ex.10:00:00]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);
  while(!stream::readString("Date[ex.24.01.17]", temp)) {  std::cout << "Wrong input...\n"; }
  formBuilder.push_back(temp);

  container = formBuilder;
  return &container;        // ship container
}

int form::nationField(std::vector<std::string>*, const int index)
{
  return 1;
} 

int form::participantField(std::vector<std::string>*, const int index)
{
  return 1;
}

int form::sportField(std::vector<std::string>*, const int index)
{
  return 1;
} 

int form::eventField(std::vector<std::string>*, const int index)
{
  return 1;
} 
