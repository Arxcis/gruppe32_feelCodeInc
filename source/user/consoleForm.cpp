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

dat::Object formSubmit;     // Temp-object which is used to send data.

//
// @function form::object - Based on type information, this function queries for a object-prototype.
//             It then loops through this prototype, and fills in the blanks.
//
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
// @function form::field
//  @brief - A function that changes a specific field of a dat::object
//
void form::field(dat::Field& field)
  { stream::readString(std::get<0>(field), std::get<1>(field)); }


//
// Add to list @functions
//
void form::startList()
{
  std::string buffer = "";
  stream::readString("ParticipantID: ", buffer);
}

void form::resultList()
{
  std::string buffer = "";
  stream::readString("Result: ", buffer);
}