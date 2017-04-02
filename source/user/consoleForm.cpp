#include "consoleForm.h"

namespace form
{
  dat::Container protos = 
  {
    {
      {"type",     "Nation"},
      {"Code",           ""},   //PK              
      {"Name",           ""},                    
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
      {"#Participants", "0"},  
    },

    {
      {"Type", "Participant"},
      {"Name",            ""},  // PK
      {"Phone",           ""},
      {"Email",           ""},
      {"CountryCode",     ""},  // FK
      {"Gender",          ""},
    },

    {
       {"Type",    "Sport"},
       {"Name",         ""},    // PK
       {"ScoreType",    ""},
       {"#Diciplines", "0"},
    },

    {
      {"Type","Dicipline"},
      {"#Starts",     "0"},
      {"#Results",    "0"},
      {"Name",         ""},     // PK
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
auto form::object(const std::string type) ->dat::Object&
{
  dat::Object proto;

  auto printKey = [](const std::string key)
                    { std::cout << key << ": " << std::endl; };

  if (type == "Nation")     
  {
    proto = form::protos[NATION];

    printKey(proto[1].first);  stream::readChar3(std::cin, proto[1].second);   // @robustness - PK code check if Nation-code already exists
    printKey(proto[2].first);  stream::readString(std::cin, proto[2].second); 
    printKey(proto[3].first);  stream::readString(std::cin, proto[3].second);
    printKey(proto[4].first);  stream::readPhone(std::cin, proto[4].second);
    printKey(proto[5].first);  stream::readEmail(std::cin, proto[5].second);
  }
  else if (type == "Participant")
  {
    proto = form::protos[PARTICIPANT];

    printKey(proto[1].first);  stream::readString(std::cin, proto[1].second); // @robustness - PK name, check if already exist 
    printKey(proto[2].first);  stream::readPhone(std::cin,  proto[2].second);
    printKey(proto[3].first);  stream::readEmail(std::cin,  proto[3].second);
    printKey(proto[4].first);  stream::readChar3(std::cin,  proto[4].second);  // @robustness - FK NationCode - check if already exist
    printKey(proto[5].first);  stream::readEnum(std::cin,   proto[5].second, {"Male", "Female"});
  }
  else if (type == "Sport")      
  {
    proto = form::protos[SPORT];

    printKey(proto[1].first);  stream::readString(std::cin, proto[1].second);  // @robustness - PK should be checked if exst
    printKey(proto[2].first);  stream::readEnum(std::cin,   proto[2].second, {"Point", "Time"});
  }
  else if (type == "Dicipline")  
  {
    proto = form::protos[DICIPLINE];

    printKey(proto[3].first);  stream::readString(std::cin, proto[3].second);  // @robustness - PK should be checked if exst
    printKey(proto[4].first);  stream::readTime(std::cin,   proto[4].second);  
    printKey(proto[5].first);  stream::readDate(std::cin,   proto[5].second);  
    
  }

  form::submit = proto;
  return form::submit;
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
