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
  dat::Object cancelObject = {{ "Type", "Cancel" }};
  API& formAPI = API::getInstance();

  auto printKey = [](const std::string key)
                  { std::cout << key << ": " << std::endl; };



  //
  // @function form::object - Based on type information, this function queries for a object-prototype.
  //             It then loops through this prototype, and fills in the blanks.
  //
  auto object(const std::string type) ->dat::Object
  {
    bool submit = true;
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

      submit = thisField(proto[1], submit);   // @robustness - PK code check if Nation-code already exists
      submit = thisField(proto[2], submit); 
      submit = // #Participants
      submit = thisField(proto[4], submit);
      submit = thisField(proto[5], submit);
      submit = thisField(proto[6], submit);
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

      submit = thisField(proto[2], submit);    
      submit = thisField(proto[3], submit);  
      submit = thisField(proto[4], submit);    // @robustness - FK NationCode - check if already exist
      submit = thisField(proto[5], submit);
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
      submit = thisField(proto[1], submit);  // @robustness - PK should be checked if exst
      submit = thisField(proto[2], submit); 
    }

    if (submit)
    { return proto; }
    else 
    { return cancelObject; }
  }

  //
  // @funciton appendDicipline()
  //  Appends a new dicipline to existing sport
  //
  void appendDicipline(dat::Object sport)
  {

    size_t suffixNumber = (std::stoi(sport[3].second)+1);

    dat::Object proto = 
    {
      {"Type", "Dicipline"},
      {"Name",  ""},
      {"Time",  ""},
      {"Date",  ""},
    };
  }

  //
  // @function form::thisField
  //  @brief - A function that changes a specific field of a dat::object
  //     1. Print info about field to be changed
  //     2. Type check, and call correct input-function for the job.
  //  
  //   This functions is where we give the user userfull error messages.
  //  As long as the submit value statys 'true', program will continue to read fields.
  //
  bool thisField(dat::Field& field, bool submit)
  {
    if (!submit) 
    { return false; }
    bool valid = false;
    const std::string fieldType = field.first;
    std::cout << fieldType << ":  " << std::endl;         // 1. 

    if (fieldType.find("Code")  != std::string::npos)     // 2. 
    { 
      do 
      { valid = stream::readChar3 (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type Code..."));
    }

    else if (fieldType.find("Name")  != std::string::npos) 
    { 
      do 
      { valid = stream::readName (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type navn..."));
    }

    else if (fieldType.find("Phone") != std::string::npos) 
    { 
      do 
      { valid = stream::readPhone (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type telefon..."));
    }

    else if (fieldType.find("Email") != std::string::npos) 
    { 
      do 
      { valid = stream::readEmail (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type email..."));
    }

    else if (fieldType.find("Time")  != std::string::npos) 
    { 
      do 
      { valid = stream::readTime (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type tid..."));
    }

    else if (fieldType.find("Point") != std::string::npos) 
    {  
      do 
      { valid = stream::readInt (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type poeng..."));
    }

    else if (fieldType.find("Medal") != std::string::npos) 
    { 
      do 
      { valid = stream::readMedals (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type medaljer..."));
    }

    else if (fieldType.find("Date")  != std::string::npos) 
    { 
      do 
      { valid = stream::readDate (field.second, std::cin); }
      while (askAgain(valid, field.second, "Feil type dato..."));
    }

    else if (fieldType.find("Sex")   != std::string::npos) 
    { 
      do 
      { valid = stream::readEnum (field.second, std::cin, { "Male", "Female" }); }
      while (askAgain(valid, field.second, "Feil type kjonn..."));
    }

    else if (fieldType.find("ScoreType") != std::string::npos) 
    { 
      do 
      { valid = stream::readEnum(field.second, std::cin, { "Point" , "Time" }); }
      while (askAgain(valid, field.second, "Feil type score type..."));
    }

    else 
    { assert(false); } // Field-types should be one of the listed above.

    if (field.second == "0")
    { 
      submit = false;     // Aborting filling in field or object.
      return false; 
    }     
    
    else 
    { return true; } 
  }


  //
  // @function askAgain - asks again unless input was '0', or it was valid.
  //
  bool askAgain(bool valid, const std::string& value, const std::string& errorMessage)
  {
    if (value == "0") 
    { return false; }

    else if (!valid)
    {
      std::cout << errorMessage << std::endl; 
      return true;
    }
    else
    { return false; }
  }

  //
  // Add to list @functions
  //
  void startList(dat::Container& starts)
  {
    int size = stream::readInput("How many participants do you want to add?\n");
    for (int it = 0; it < size; it++)
    {
      dat::Object startProto =
      {
        {"Type",    "Start"},
        {"ID",      ""},        // PPK
        {"StartNR", ""},
      };
    printKey(startProto[1].first);   stream::readInt(startProto[1].second, std::cin);
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
      thisField(resultProto[2]);
      results.push_back(resultProto);
    }
  }
}
