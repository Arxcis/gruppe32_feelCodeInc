#include "consoleForm.h"

dat::Object formSubmit;

auto form::nation() ->dat::Object*
{
  dat::Object 
  proto
  {            
      {"Code",          ""},       //PK              
      {"Name",          ""},                    
      {"#Participants", ""},  
      {"ContactName",   ""},                    
      {"ContactPhone",  ""},             
      {"ContactEmail",  ""},  
  };
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Nation"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::participant() ->dat::Object*
{
  dat::Object 
  proto
  {
      {"Name", ""},
      {"Phone", ""},
      {"Email", ""},
      {"CountryCode", ""},
      {"Gender", ""},
  };
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Participant"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::sport() ->dat::Object*
{
  dat::Object 
  proto
  {
      {"Name",      ""},     //PK
      {"ScoreType", ""},
  };
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Sport"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::dicipline() ->dat::Object*
{
  dat::Object 
  proto
  {
      {"Name", ""},     //PK
      {"Time", ""}, 
      {"Date", ""},
  };
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Dicipline"});
  formSubmit = proto;
  return &formSubmit;        // ship container
}
/*
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

void form::diciplineField(std::vector<std::string>* container, const int index)
{
  std::string buffer = "";
  stream::readString("edit: ", buffer);
  (*container)[index-1] = buffer;
} 

void form::listAdd()
{
  std::string buffer = "";
  stream::readString("ParticipantID: ", buffer);
}

void form::listResult()
{
  std::string buffer = "";
  stream::readString("Result: ", buffer);
}*/
