#include "consoleForm.h"

namespace form
{
  dat::Container protos = 
  {
    {
      {"type",     "Nation"},
      {"Code",           ""},       //PK              
      {"Name",           ""},                    
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
      {"#Participants", "0"},  
    },

    {
      {"Type", "Participant"},
      {"Name",            ""},
      {"Phone",           ""},
      {"Email",           ""},
      {"CountryCode",     ""},
      {"Gender",          ""},
    },

    {
       {"Type",    "Sport"},
       {"Name",         ""},     //PK
       {"ScoreType",    ""},
       {"#Diciplines", "0"},
    },

    {
      {"Type","Dicipline"},
      {"#Starts",     "0"},
      {"#Results",    "0"},
      {"Name",         ""},            //PK
      {"Time",         ""}, 
      {"Date",         ""},
    },
  };

  dat::Object submit;     // Temp-object which is used to send data.
}


//
// @function form::object - Based on type information, this function queries for a object-prototype.
//             It then loops through this prototype, and fills in the blanks.
//
auto form::object(const std::string type) ->dat::Object*
{
  dat::Object proto;

  if (type == "Nation")     
  {
    proto = form::protos[NATION];
    stream::readString(std::cin, proto[1].second); // @robustness - check if Nation-name already exists
  }
  else if (type == "Participant")
  {
    proto = form::protos[PARTICIPANT];
  }
  else if (type == "Sport")      
  {
    proto = form::protos[SPORT];
  }
  else if (type == "Dicipline")  
  {
    proto = form::protos[DICIPLINE];
  }

  form::submit = proto;
  return &form::submit;
}

//
// @function form::field
//  @brief - A function that changes a specific field of a dat::object
//
void form::field(dat::Field& field)
{
    std::cout << std::get<0>(field) << " : ";
    stream::readString(std::cin, std::get<1>(field)); }


//
// Add to list @functions
//
void form::startList()
{
  std::string buffer = "";
    std::cout << "ParticipantID: ";
    stream::readString(std::cin, buffer);
}

void form::resultList()
{
  std::string buffer = "";
    std::cout << "Result: ";
    stream::readString(std::cin, buffer);
}
