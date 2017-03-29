#include "consoleForm.h"

std::unordered_map<std::string, dat::Object> protos = 
{
  {
    "Nation",
    {
      {"Code",          ""},       //PK              
      {"Name",          ""},                    
      {"#Participants", ""},  
      {"ContactName",   ""},                    
      {"ContactPhone",  ""},             
      {"ContactEmail",  ""}
    }
  },
  {
    "Participant",
    {
      {"Name", ""},
      {"Phone", ""},
      {"Email", ""},
      {"CountryCode", ""},
      {"Gender", ""},
    }
  },
  {
    "Sport",
    {
      {"Name",      ""},     //PK
      {"ScoreType", ""},
    }
  },
  {
    "Dicipline",
    {
      {"Name", ""},          //PK
      {"Time", ""}, 
      {"Date", ""},
    }
  }
};


dat::Object formSubmit;


auto form::object(const std::string& type) ->dat::Object*
{
  dat::Object 
  proto = protos[type];
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", type});
  formSubmit = proto;
  return &formSubmit;
}

auto form::nation() ->dat::Object*
{
  dat::Object 
  proto = protos["Nation"];
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Nation"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::participant() ->dat::Object*
{
  dat::Object 
  proto = protos["Participant"];
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Participant"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::sport() ->dat::Object*
{
  dat::Object 
  proto = protos["Sport"];
  
  for(auto& field: proto)
    { stream::readString(std::get<0>(field), std::get<1>(field)); }

  proto.insert(proto.begin(), {"type", "Sport"});
  formSubmit = proto;
  return &formSubmit;
}

auto form::dicipline() ->dat::Object*
{
  dat::Object 
  proto = protos["Dicipline"];
  
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