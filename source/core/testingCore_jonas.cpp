//
// @file    core/testingCore_jonas.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the core-module. Used for testing
//          components of the core-module.
//

#include "core/database/NationBase.h"
#include "core/database/ParticipantBase.h"
#include "core/database/SportBase.h"
#include "core/database/MedalBase.h"
#include "core/database/PointBase.h"

  dat::Object
    nation0
  {
    { "Type",          "Nation" },
    { "Code",          "NOR" },       //PK              
    { "Name",          "Norge" },
    { "#Participants", "150" },
    { "ContactName",   "Jonas" },
    { "ContactPhone",  "452000864" },
    { "ContactEmail",  "jonas.solsvik@gmail.com" },
  };

    dat::Object
    participant
  {
    { "type", "Participant" },
    { "ID"  , "1002" },     //PK
    { "Name", "Jonas" },
    { "Phone", "452000864" },
    { "Email", "jonas.solsvik@gmail.com" },
    { "CountryCode", "NOR" },
    { "Gender", "Male" },
  };

  dat::Object
  sport
  {
    { "Type", "Sport" },
    { "Name", "Fotball" },     //PK
    { "ScoreType", "Points" },
    { "#Diciplines", "3" },
    { "1", "Final" },
    { "2", "Semi-final" },
    { "3", "1/4-final" },
  };


  dat::Object
  medalStats
  {
    { "Type", "MedalStats" },
    { "#Entries", "3" },
    { "NOR", "1-2-3" },
    { "SWE", "0-2-3" },
    { "DAN", "0-0-5" },
  };

  dat::Object
  pointStats
  {
    { "Type", "PointStats" },
    { "#Entries", "3" },
    { "NOR", "100" },
    { "SWE", "90" },
    { "DAN", "80" },
  };

void testPacking()
{

}

int main()
{
    
  printf("Hello from core module\n");
  return 0;
}
