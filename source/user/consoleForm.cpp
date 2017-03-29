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