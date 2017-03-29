#include "file.h"

namespace file
{ 
  //
  // @prototype objects
  //
  dat::Container protos = 
  {
    {
      {"type",           ""},   // Nation
      {"Code",           ""},   //PK              
      {"Name",           ""},                    
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
      {"#Participants",  ""},  
    },

    {
      {"Type",        ""},  // Participant
      {"Name",        ""},  // PK
      {"Phone",       ""},
      {"Email",       ""},
      {"CountryCode", ""},  // FK
      {"Gender",      ""},
    },

    {
       {"Type",         ""},  // Sport
       {"Name",         ""},  // PK
       {"ScoreType",    ""},
       {"#Diciplines",  ""},
    },

    {
      {"Type",         ""},   // Dicipline
      {"#Starts",      ""},
      {"#Results",     ""},
      {"Name",         ""},  // PK
      {"Time",         ""}, 
      {"Date",         ""},
    },
  };

  //
  // @function file::readNations
  //
  void readNations      (NationBase&      nationBase,      const std::string& filepath)
  { 
    std::ifstream inFile(filepath);
    std::stringstream ss;

    if (inFile)
    {
      ss << inFile.rdbuf();     // Flushing filestream contents into stringstream buffer
      inFile.close();

    }
    else 
      { std::cout << filepath << " not found ....\n"; }
  }

  //
  // @function file::readParticipants
  //
  void readParticipants (ParticipantBase& participantBase, const std::string& filepath)
  {
    std::ifstream inFile(filepath);
    std::stringstream ss;

    if (inFile)
    {
      ss << inFile.rdbuf();     // Flushing filestream contents into stringstream buffer
      inFile.close();

    }
    else 
      { std::cout << filepath << " not found ....\n"; }
  }

  //
  // @function file::readSports
  //
  void readSports       (SportBase&       sportBase,       const std::string& filepath)
  {
    std::ifstream inFile(filepath);
    std::stringstream ss;

    if (inFile)
    {
      ss << inFile.rdbuf();     // Flushing filestream contents into stringstream buffer
      inFile.close();

    }
    else 
      { std::cout << filepath << " not found ....\n"; }
  }

}