//
// @file    core/testingCore_jonas.cpp
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the core-module. Used for testing
//          components of the core-module.
//

#include "database/NationBase.h"
#include "database/ParticipantBase.h"
#include "database/SportBase.h"
#include "database/MedalBase.h"
#include "database/PointBase.h"

  dat::Object
  testnation
  {
    { "Type",          "Nation" },
    { "Code",          "NOR" },       //PK              
    { "Name",          "Norge" },
    { "#Participants", "150" },
    { "ContactName",   "Jonas" },
    { "ContactPhone",  "+47452000864" },
    { "ContactEmail",  "jonas.solsvik@gmail.com" },
  };

  dat::Object
  testparticipant
  {
    { "type", "Participant" },
    { "ID"  , "" },     //PK
    { "Name", "Jonas" },
    { "Phone", "+47452000864" },
    { "Email", "jonas.solsvik@gmail.com" },
    { "CountryCode", "NOR" },
    { "Sex", "Male" },
  };

  dat::Object
  testsport
  {
    { "Type", "Sport" },
    { "Name", "Fotball" },     //PK
    { "ScoreType", "Point" },
    { "#Diciplines", "2" },
    { "Dicipline1", "Final" },
    { "Time1", "10:00:12" },
    { "Date1", "12.03.91" },
    { "Dicipline2", "Semi-final" },
    { "Time2", "10:00:12" },
    { "Date2", "12.03.02" },
  };


  dat::Object
  testmedal
  {
    { "Type", "Medal" },
    { "Code",  "NOR"},
    { "Value", "01-02-03" },
  };

  dat::Object
  testpoint
  {
    { "Type", "Point"},
    { "Code",  "NOR" },
    { "Value", "80"  },
  };


void printObject(const dat::Object& obj)
{
  std::cout << "\n\n";
  for (const auto& field: obj) 
  {
    std::cout << field.first << ": " << field.second << "\n";
  }
}

void testPackingAndOtherRelatedFunctions()
{
  db::NationBase       nationBase     ;     
  db::ParticipantBase  participantBase;         
  db::SportBase        sportBase      ;        
  db::PointBase        pointBase      ;
  db::MedalBase        medalBase      ;


  // Test ADD
  nationBase.add(testnation);
  participantBase.add(testparticipant);
  sportBase.add(testsport);
  pointBase.add(testpoint);
  pointBase.add(testpoint);
  pointBase.add(testpoint);
  pointBase.add(testpoint);
  medalBase.add(testmedal);

  // Test DISPLAY
  nationBase.display();
  participantBase.display();
  sportBase.display();
  
  medalBase.display();

  // Test FIND FUNCTIONS
  if (nationBase.findID("SWE"))
    { std::cout << "\n Found Nation!"; }
  else
    { std::cout << "\n No found........."; }

  if (participantBase.findID(1002))
    { std::cout << "\n Found Participant!"; }
  else
    { std::cout << "\n No found........."; }

  if (sportBase.findID("Fotball"))
   { std::cout << "\n Found Sport!"; }
  else
    { std::cout << "\n No found........."; }


/*  // Test GETID functions
  dat::Object getNation;
  dat::Object getPart;
  dat::Object getSport;

  nationBase.getID(getNation, "NOR");
  participantBase.getID(getPart, 1001);
  sportBase.getID(getSport, "Fotball");


  // PRINTING OBJECTS --
  std::cout << "\n-----PRINTING OBJECTS----\n";
  printObject(getNation);
  printObject(getPart);
  printObject(getSport);

  dat::Container getPoints = pointBase.getContainer();
  dat::Container getMedals = medalBase.getContainer();

  for (auto& obj: getPoints) 
    { printObject(obj); }
  for (auto& obj: getMedals) 
    { printObject(obj); }

  pointBase.display();*/
}

int main()
{
  testPackingAndOtherRelatedFunctions();
  printf("\n\n=======================" );
  printf("\n\nHello from core module\n");
  return 0;
}
