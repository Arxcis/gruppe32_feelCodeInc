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

  void readNations      (NationBase&      nationBase,      const std::string& filepath)
  {

  }

  void readParticipants (ParticipantBase& participantBase, const std::string& filepath)
  {

  }

  void readSports       (SportBase&       sportBase,       const std::string& filepath)
  {

  }

}