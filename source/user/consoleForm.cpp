#include "consoleForm.h"

enum ProtoForms 
{
  NATION_P,
  PARTICIPANT_P, 
  SPORT_P,
  DICIPLINE_P,
  START_P,
  RESULT_P,
};

namespace form
{
  dat::Container protos = 
  {
    {
      {"type",     "Nation"},
      {"Code",           ""},   //PK              
      {"Name",           ""},                    
      {"#Participants", "0"},  
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
    },

    {
      {"Type", "Participant"},
      {"ID"  ,         ""},
      {"Name",         ""},  // PK
      {"Phone",        ""},
      {"Email",        ""},
      {"CountryCode",  ""},  // FK
      {"Sex",          ""},
    },

    {
       {"Type",   "Sport"},
       {"Name",        ""},    // PK
       {"ScoreType",   ""},
       {"#Diciplines", "0"},
    },

    {
      {"Type",    "Start"},
      {"ID",      ""},        // PPK
      {"StartNR", ""},
    },

    {
      {"Type",  "Result"},
      {"ID",    ""},        // PPK
      {"", ""},
    },
  };
  dat::Object submit;     // Temp-object which is used to send data.

  auto printKey = [](const std::string key)
                  { std::cout << key << ": " << std::endl; };



  //
  // @function form::object - Based on type information, this function queries for a object-prototype.
  //             It then loops through this prototype, and fills in the blanks.
  //
  auto object(const std::string type) ->dat::Object&
  {
    dat::Object proto;

    if (type == "Nation")     
    {
      proto = form::protos[NATION_P];

      printKey(proto[1].first);  stream::readChar3(std::cin,  proto[1].second);   // @robustness - PK code check if Nation-code already exists
      printKey(proto[2].first);  stream::readString(std::cin, proto[2].second); 
      printKey(proto[3].first);  stream::readString(std::cin, proto[3].second);
      printKey(proto[4].first);  stream::readPhone(std::cin,  proto[4].second);
      printKey(proto[5].first);  stream::readEmail(std::cin,  proto[5].second);
    }
    else if (type == "Participant")
    {
      proto = form::protos[PARTICIPANT_P];

      printKey(proto[1].first);  stream::readString(std::cin, proto[1].second); // @robustness - PK name, check if already exist 
      printKey(proto[2].first);  stream::readPhone(std::cin,  proto[2].second);
      printKey(proto[3].first);  stream::readEmail(std::cin,  proto[3].second);
      printKey(proto[4].first);  stream::readChar3(std::cin,  proto[4].second);  // @robustness - FK NationCode - check if already exist
      printKey(proto[5].first);  stream::readEnum(std::cin,   proto[5].second, {"Male", "Female"});
    }
    else if (type == "Sport")      
    {
      proto = form::protos[SPORT_P];

      printKey(proto[1].first);  stream::readString(std::cin, proto[1].second);  // @robustness - PK should be checked if exst
      printKey(proto[2].first);  stream::readEnum(std::cin,   proto[2].second, {"Point", "Time"});
    }

    form::submit = proto;
    return form::submit;
  }

  //
  // @funciton appendDicipline()
  //  Appends a new dicipline to existing sport
  //
  void appendDicipline(dat::Object sport)
  {
    
  }

  //
  // @function form::field
  //  @brief - A function that changes a specific field of a dat::object
  //     1. Print info about field to be changed
  //     2. Type check, and call correct input-function for the job.
  //
  void field(dat::Field& field)
  {

    const std::string fieldType = field.first;
    std::cout << fieldType << " : " << std::endl;         // 1. 

    if (fieldType.find("Code")  != std::string::npos)     // 2. 
      { stream::readChar3 (std::cin, field.second); }

    else if (fieldType.find("Name")  != std::string::npos) 
      { stream::readString(std::cin, field.second); }

    else if (fieldType.find("Phone") != std::string::npos) 
      { stream::readPhone (std::cin, field.second); }

    else if (fieldType.find("Email") != std::string::npos) 
      { stream::readEmail (std::cin, field.second); }

    else if (fieldType.find("Time")  != std::string::npos) 
      { stream::readTime  (std::cin, field.second); }

    else if (fieldType.find("Point") != std::string::npos) 
      { stream::readInt (std::cin, field.second); }

    else if (fieldType.find("Medal") != std::string::npos) 
      { stream::readMedals (std::cin, field.second); }

    else if (fieldType.find("Date")  != std::string::npos) 
      { stream::readDate  (std::cin, field.second); }

    else if (fieldType.find("Sex")   != std::string::npos) 
      { stream::readEnum  (std::cin, field.second, { "Male", "Female"   }); }

    else if (fieldType.find("ScoreType") != std::string::npos) 
      { stream::readEnum  (std::cin, field.second, { "Point" , "Time" }); }

    else 
      { assert(false); } // Field-types should be one of the listed above.
  }


  //
  // Add to list @functions
  //
  void startList(dat::Container& starts)
  {
    int size = stream::readInt("How many participants do you want to add?\n");
    for (int it = 0; it < size; it++)
    {
      dat::Object startProto = protos[START_P];
      printKey(startProto[1].first);   stream::readInt(std::cin, startProto[1].second);
      // printKey(startProto[2].first);   stream::readString(std::cin, startProto[2].second);

      starts.push_back(startProto);
    }
  }

  void resultList(dat::Container& results, const int size)
  {
    for (int it=0; it < size; it++)
    {
      dat::Object resultProto = protos[RESULT_P];

      printKey(resultProto[1].first + resultProto[2].first);  // stream::readInt(std::cin, resultProto[1].second); // ID may not be necessarry
      printKey(resultProto[2].first);   stream::readString(std::cin, resultProto[2].second);
    
      results.push_back(resultProto);
    }
  }
}
