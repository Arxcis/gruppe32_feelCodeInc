#pragma once
//
// @file    testdata.h
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief     a collection of test data that simulate data
//            which controller recieves from the database.
//            This could also serves as a standard for the dataformat,
//            on different containers throughout the program.
//


#include <vector>
#include <string>
#include "../tool/typedef.h"

//
// @namespace test - testdata
//
namespace test 
{
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
    { "Name1", "Final" },
    { "Time1", "10:00:12" },
    { "Date1", "12.03.91" },
    { "Name2", "Semi-final" },
    { "Time2", "10:00:12" },
    { "Date2", "12.03.02" },
  };


  dat::Object
  testmedal
  {
    { "Type", "Medal" },
    { "Code",  "NOR"},
    { "Medals", "01-02-03" },
  };

  dat::Object
  testpoint
  {
    { "Type", "Point"},
    { "Code",  "NOR" },
    { "#Points", "80"  },
  };

  dat::Object* nulldata = nullptr;
  dat::Container* nulldatas = nullptr;
}
