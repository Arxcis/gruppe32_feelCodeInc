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

//
// @function editField
//  @brief - A function that changes a specific field of a dat::object
//
void form::editField(dat::Field& field)
  { stream::readString(std::get<0>(field), std::get<1>(field)); }


//
// Add to list @functions
//
void form::listAdd()
{
  std::string buffer = "";
  stream::readString("ParticipantID: ", buffer);
}

void form::listResult()
{
  std::string buffer = "";
  stream::readString("Result: ", buffer);
}