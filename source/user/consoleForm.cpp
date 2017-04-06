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
  API& api = API::getInstance();

  auto printKey = [](const std::string key)
                  { std::cout << key << ": " << std::endl; };

  //
  // @function form::object - Based on type information, this function queries for a object-prototype.
  //             It then loops through this prototype, and fills in the blanks.
  //
  void object(const std::string type)
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

      submit = thisField(proto[1], submit); 

      //
      // @Integrity check NATION CODE
      //
      while(api.find(NATION, proto[1].second) && submit)
      { 
        std::cout << "Nasjon med koden " << proto[1].second << " finnes allerede.....\n";
        submit = thisField(proto[1], submit); 
      } 
     
      submit = thisField(proto[2], submit); 

      submit = thisField(proto[4], submit);
      submit = thisField(proto[5], submit);
      submit = thisField(proto[6], submit);

    }
    else if (type == "Participant")
    {
      proto =     
      {
        {"Type", "Participant"},
        {"ID"  ,         ""},  // PK
        {"Name",         ""},  
        {"Phone",        ""},
        {"Email",        ""},
        {"CountryCode",  ""},  // FK
        {"Sex",          ""},
      };

      submit = form::thisField(proto[2], submit);  
      submit = form::thisField(proto[3], submit);  
      submit = form::thisField(proto[4], submit);    // @robustness - FK NationCode - check if already exist
      submit = form::thisField(proto[5], submit);

      //
      // @Integrity check NATION CODE
      //
      while(!api.find(NATION, proto[5].second) && submit)
      { 
        std::cout << "Ingen nasjon med koden " << proto[5].second << " finnes.....\n"; 
        submit = form::thisField(proto[5], submit);
      }
      submit = form::thisField(proto[6], submit);
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
      submit = form::thisField(proto[1], submit);  // @robustness - PK should be checked if exst

      //
      // @Integrity check SPORT NAME
      //
      while(api.find(SPORT, proto[1].second) && submit)
      { 
        std::cout << "Sporten " << proto[1].second << " finnes allerede.....\n"; 
        submit = form::thisField(proto[1], submit);
      } 

      submit = thisField(proto[2], submit); 
    }

    if (submit)
    { api.add(proto); }
  }

  //
  // @funciton appendDicipline()
  //  Appends a new dicipline to existing sport
  //
  void appendDicipline(dat::Object sport)
  {

    // Unique number of new dicipline in the given sport
    const std::string newNumber = std::to_string(std::stoi(sport[3].second) + 1);
    bool submit = true;

    dat::Object proto = 
    {
      {"Type",     "Dicipline"},
      {"DiciplineID",     ""},
      {"Time",            ""},
      {"Date",            ""},
    };

    submit = form::thisField(proto[1], submit);
    
    //
    // @integrity - checking if diciplineID already exists..
    //
    bool correct = false;
    while (!correct && submit) {
      correct = true;
      for (const auto& field: sport)
      {
        if (field.second.substr(
               field.second.find("_")+1) == proto[1].second)
        { 
          correct = false;
          break;
        } 
      }
      if(!correct)
      { 
        std::cout << "Dicipline already exist....\n";
        submit = form::thisField(proto[1], submit); 
      }
    }

    submit = form::thisField(proto[2], submit);
    submit = form::thisField(proto[3], submit);

    // Making dicipline fields unique within the sport, by appending the new dicipline number.
    proto[2].first += newNumber;
    proto[3].first += newNumber;

    // Pushing back new fields
    sport.push_back(proto[1]);
    sport.push_back(proto[2]);
    sport.push_back(proto[3]);

    // Incrementing number of diciplines
    sport[3].second = newNumber;

    //for(auto& field: sport){  std::cout << field.first << ": " << field.second << "\n"; } // @debug

    if (submit)
    { api.add(sport); }
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
    if (!submit)        // Early return if user has canceled
    { return false; }

    bool valid = false;
    const std::string fieldType = field.first;
    std::cout << fieldType << ":  " << std::endl;         // 1. 

    if (fieldType.find("Code")  != std::string::npos)     // 2. 
    { 
      do 
      { valid = stream::readChar3 (field.second, std::cin); }
      while (askAgain(valid, field.second, 
                  " Feil type landskode (3 karakterer)...\n"
                  "   Ex1:  NOR  \n"
                  "   Ex2:  SWE  \n"));
    }

    else if (fieldType.find("Name")  != std::string::npos) 
    { 
      do 
      { valid = stream::readName (field.second, std::cin); }
      while (askAgain(valid, field.second, 
                  " Feil type navn...\n"
                  "   Ex1: Jonas Hanson\n"
                  "   Ex2: Henrik J. Johnson\n"
                  "   Ex3: U.S.S.R.\n"));
    }

    else if (fieldType.find("DiciplineID")  != std::string::npos) 
    { 
      do 
      { valid = stream::readDiciplineID(field.second, std::cin); }
      while (askAgain(valid, field.second, R"(
                                           " Feil type øvelsenavn...\n"
                                           "   Ex1: 50km-klassisk\n",
                                           "   Ex2: Hockey-Finale-Menn\n)"));
    }

    else if (fieldType.find("Phone") != std::string::npos) 
    { 
      do 
      { valid = stream::readPhone (field.second, std::cin); }
      while (askAgain(valid, field.second, 
                    " Feil type telefon...\n"
                    "   Ex1: +4712345678\n"
                    "   Ex2: +47 12345678\n"
                    "   Ex3: +47 123 45 678\n"
                    "   Ex4: +45 12 34 56 78\n"));
    }

    else if (fieldType.find("Email") != std::string::npos) 
    { 
      do 
      { valid = stream::readEmail (field.second, std::cin); }
      while (askAgain(valid, field.second, 
                    " Feil type email...\n"
                    "   Ex1: jon.sol@gma.co\n"
                    "   Ex2: jonassur_golfurson@fjatt.foobar"));
    }

    else if (fieldType.find("Time")  != std::string::npos) 
    { 
      do 
      { valid = stream::readTime (field.second, std::cin); }
      while (askAgain(valid, field.second, 
                    " Feil type tid...\n"
                    "   Ex1: 12:00\n"
                    "   Ex2: 00:37:55"
                    "   Ex3: 00:00:55:678"));
    }

    else if (fieldType.find("Point") != std::string::npos) 
    {  
      do 
      { valid = stream::readInt(field.second, std::cin); }
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
  // @function startList()
  //  @api-call updateAll(STARTS)
  //
  void startList(
    const std::string& diciplineID,
    const dat::Object& sport)
  {
    bool submit = true;
    bool valid  = true;
    dat::Container starts;
    std::string numberOfParticipants;

    do 
    {
      std::cout << "How many participants do you want to add?\n";
      valid = stream::readInt(numberOfParticipants, std::cin);
    }
    while (askAgain(valid, numberOfParticipants, "Not an int...\n" ));

    size_t it = 0;
    while (it < std::stoi(numberOfParticipants) && submit)
    {
      it++;
      dat::Object startProto =
      {
        {"Type",    "Start"},
        {"ID",      ""},        // PPK
        {"StartNR", ""},
      };
      submit = form::thisField(startProto[1], submit);
      starts.push_back(startProto);
    }
    if (submit) 
    { api.updateAll(STARTS, starts, diciplineID); }
  }

  //
  // @function resultList()
  //  @api-call updateAll(RESULTS)
  //
  void resultList(
    const std::string&    diciplineID,
    const dat::Object&    sport, 
    const dat::Container& starts)
  { 
    bool submit = true;
    dat::Container    results;
    const std::string scoreType = sport[2].second;
    const size_t      size      = starts.size();

    size_t it = 0;
    while (it < size && submit)
    { 
      it++;
      dat::Object resultProto = 
      {
        {"Type",    "Result"},
        {"ID",      ""},        // PPK
        {scoreType, ""},     // @TODO , here we need either Time-result or Point-result
      };

      printKey(starts[it][1].first + " - " + starts[it][1].second + "      " + starts[it][2].first + " - " +  starts[it][2].second); 
      submit = form::thisField(resultProto[2], submit);
      results.push_back(resultProto);
    }

    if (submit) 
    { api.updateAll(RESULTS, results, diciplineID); }
  }

  //
  // @function askAgain() - asks again unless input was '0', or it was valid.
  //
  bool askAgain (bool valid_, const std::string& value, const std::string& errorMessage)
  {
    if (value == "0") 
    { return false; }
    else if (!valid_)
    {
      std::cout << errorMessage << std::endl; 
      return true;
    }
    else
    { return false; }
  };
}
