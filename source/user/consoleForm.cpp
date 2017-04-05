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
      proto =     
      {                           // dat::Object
        {"Type",     "Nation"},
        {"Code",           ""},   //PK              
        {"Name",           ""},                    
        {"#Participants", "0"},  
        {"ContactName",    ""},                    
        {"ContactPhone",   ""},             
        {"ContactEmail",   ""},
      };

      field(proto[1]);   // @robustness - PK code check if Nation-code already exists
      field(proto[2]); 

      field(proto[4]);
      field(proto[5]);
      field(proto[6]);
    }
    else if (type == "Participant")
    {
      proto =     
      {
        {"Type", "Participant"},
        {"ID"  ,         ""},
        {"Name",         ""},  // PK
        {"Phone",        ""},
        {"Email",        ""},
        {"CountryCode",  ""},  // FK
        {"Sex",          ""},
      };

      field(proto[2]);    
      field(proto[3]);  
      field(proto[4]);    // @robustness - FK NationCode - check if already exist
      field(proto[5]);
    }
    else if (type == "Sport")      
    {
      proto =
      { 
        {"Type",   "Sport"},
        {"Name",        ""},    // PK
        {"ScoreType",   ""},
        {"#Diciplines", "0"},
      };
      field(proto[1]);  // @robustness - PK should be checked if exst
      field(proto[2]); 
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
    dat::Object proto = 
    {
      {"Type", "Dicipline"},
      {"Name",  ""},
      {"Time",  ""},
      {"Date",  ""},
    };
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
    std::cout << fieldType << ":  " << std::endl;         // 1. 

    if (fieldType.find("Code")  != std::string::npos)     // 2. 
    { stream::readChar3(std::cin, field.second); }

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
      dat::Object startProto =
      {
        {"Type",    "Start"},
        {"ID",      ""},        // PPK
        {"StartNR", ""},
      };
      printKey(startProto[1].first);   stream::readInt(std::cin, startProto[1].second);
      // printKey(startProto[2].first);   stream::readString(std::cin, startProto[2].second);

      starts.push_back(startProto);
    }
  }

  void resultList(
    dat::Object&       sport, 
    dat::Container&    starts, 
    dat::Container&    results)
  { 
    const std::string& scoreType = sport[2].second;
    const size_t size = starts.size();

    for (size_t it=0; it < size; it++)
    {
      dat::Object resultProto = 
      {
        {"Type",  "Result"},
        {"ID",    ""},        // PPK
        {scoreType, ""},     // @TODO , here we need either Time-result or Point-result
      };

      printKey(starts[it][1].first + " - " + starts[it][1].second + "      " + starts[it][2].first + " - " +  starts[it][2].second); 
      field(resultProto[2]);
      results.push_back(resultProto);
    }
  }
}
