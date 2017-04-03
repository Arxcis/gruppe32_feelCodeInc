
//
// @file    user/testing_halvor.cpp
// @repo    gruppe32
// @created 28.03.17 by Halvor
// @brief   Testing program modules
//

#include <stdio.h>
#include <iostream>

#include "NationBase.h"

// @local files

  dat::Object
    nation0
  {
    { "Type",          "Nation" },
    { "Code",          "NOR" },       //PK              
    { "Name",          "Norge" },
    { "#Participants", "150" },
    { "ContactName",   "Jonas" },
    { "ContactPhone",  "452000864" },
    { "ContactEmail",   "jonas.solsvik@gmail.com" },
  };

  dat::Object
    nation1
  {
    { "Type",          "Nation" },
    { "Code",          "SWE" },       //PK              
    { "Name",          "Sverige" },
    { "#Participants", "150" },
    { "ContactName",   "Jonas" },
    { "ContactPhone",  "452000864" },
    { "ContactEmail",   "jonas.solsvik@gmail.com" },
  };
  
  dat::Object
    nation2
  {
    { "Type",          "Nation" },
    { "Code",          "DAN" },       //PK              
    { "Name",          "Danmark" },
    { "#Participants", "150" },
    { "ContactName",   "Jonas" },
    { "ContactPhone",  "452000864" },
    { "ContactEmail",   "jonas.solsvik@gmail.com" },
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
    dicipline
  {
    { "Type","Dicipline" },
    { "#Starts", "2" },
    { "#Results","2" },
    { "Name", "Finale" },     //PK
    { "Time", "19:00" },
    { "Date","29.03.18" },
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

  dat::Object
    startList
  {
    { "Type", "StartList" },
    { "#Entries", "2" },
    { "1001", "1001" },
    { "1002", "1002" },
  };

  dat::Object
    resultList
  {
    { "Type", "ResultList" },
    { "#Entries", "2" },
    { "1001", "00:48:01" },
    { "1002", "00:28:55" },
  };


  dat::Container
    nations
  {
    nation0,
    nation1,
    nation2,
  };

  dat::Container
    participants
  {
    participant,
    participant,
    participant,
  };

  dat::Container
    sports
  {
    sport,
    sport,
    sport,
  };

  dat::Container
    diciplines
  {
    dicipline,
    dicipline,
    dicipline,
  };

  dat::Object* nulldata = nullptr;
  dat::Container* nulldatas = nullptr;

int main() 
{
  //sprintf("%s", test::nation[1].second.c_str());
  db::NationBase base;
  base.add(&nations[0]);
  base.add(&nations[1]);
  base.add(&nations[2]);
  
  if (base.findID("SWE")) { printf("\n\tSWE was found!\n"); }
  
  
  base.display();

  return 0;
}
