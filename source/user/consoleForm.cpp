#include "consoleForm.h"

std::vector<std::string> container;

auto form::nation() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Nation");
  std::string buffer = "";

  stream::readString("ContryCode[ex.NOR]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Name[ex.Norway]", buffer);
  formBuilder.push_back(buffer);
  stream::readInt("NumberOfParticipants[ex.150]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("ContactName[ex.Jonas Solsvik]", buffer);
  formBuilder.push_back(buffer);
  stream::readPhone("ContactPhone[ex.+4745200864]", buffer);
  formBuilder.push_back(buffer);
  stream::readEmail("ContactMail[ex.jonas.solsvik@gmail.com]", buffer);
  formBuilder.push_back(buffer);

  container = formBuilder;
  return &container;
}

auto form::participant() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Participant");
  std::string buffer = "";

  stream::readString("Name[ex.Jonas]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Phone[ex.+4745200864]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Mail[ex.jonas.solsvik@gmail.com]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("ContryCode[ex.NOR]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Gender[female=0, male=1]", buffer);
  formBuilder.push_back(buffer);

  container = formBuilder;
  return &container;
}

auto form::sport() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Sport");
  std::string buffer = "";

  stream::readString("Name[ex.Fotball", buffer);
  formBuilder.push_back(buffer);
  stream::readString("ScoreType[medals=0, points=1]", buffer);
  formBuilder.push_back(buffer);

  container = formBuilder;
  return &container;
}

auto form::event() ->std::vector<std::string>*
{
  std::vector<std::string> formBuilder;
  formBuilder.push_back("Event");
  std::string buffer = "";

  stream::readString("Name[ex.10km]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Time[ex.10:00:00]", buffer);
  formBuilder.push_back(buffer);
  stream::readString("Date[ex.24.01.17]", buffer);
  formBuilder.push_back(buffer);

  container = formBuilder;
  return &container;        // ship container
}

//
// @edit field functions 
//  @brief - This 4 functions are identical at the moment, but perhaps they will differ
//   Ideally they will be the same funciton.
//
void form::nationField(std::vector<std::string>* container, const int index)
{
  std::string buffer = "";
  stream::readString("edit: ", buffer);
  (*container)[index-1] = buffer;
} 

void form::participantField(std::vector<std::string>* container, const int index)
{
  std::string buffer = "";
  stream::readString("edit: ", buffer);
  (*container)[index-1] = buffer;
}

void form::sportField(std::vector<std::string>* container, const int index)
{
  std::string buffer = "";
  stream::readString("edit: ", buffer);
  (*container)[index-1] = buffer;
} 

void form::eventField(std::vector<std::string>* container, const int index)
{
  std::string buffer = "";
  stream::readString("edit: ", buffer);
  (*container)[index-1] = buffer;
} 
