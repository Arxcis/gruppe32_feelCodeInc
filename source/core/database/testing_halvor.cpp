
//
// @file    user/testing_halvor.cpp
// @repo    gruppe32
// @created 28.03.17 by Halvor
// @brief   Testing program modules
//

#include <stdio.h>
#include <iostream>

#include "API.h"

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
    { "ContactEmail",  "jonas.solsvik@gmail.com" },
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

  const dat::Container resultList
  {
    { {"Type",  "Point"    },
      {"ID",    "101"     },  //participant ID
      {"Value", "1203"} },

    { { "Type",  "Point"    },
      { "ID",    "102"     }, //participant ID
      { "Value", "1121"} },

    { { "Type",  "Point"    },
      { "ID",    "203"     }, //participant ID
      { "Value", "9203"} },

     { { "Type",  "Point"    },
      { "ID",    "104"     }, //participant ID
      { "Value", "1243"} },

   { { "Type",  "Point"    },
      { "ID",    "202"     }, //participant ID
      { "Value", "9240"} },

    { { "Type",  "Point"    },
      { "ID",    "302"     }, //participant ID
      { "Value", "9202"} }
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
  API& api = API::getInstance();

  dat::Container participants = api.getAll(PARTICIPANT);
  for (size_t i = 0; i < participants.size(); i++)
  {
    for (size_t j = 0; j < participants[i].size(); j++)
    { 
      printf("%s\t\t\t%s\n",
      participants[i][j].first.c_str(),
      participants[i][j].second.c_str());
    }
  }
  
  std::cout << "\n\n\n\n";
  api.updateAll(RESULTS, resultList, "test");
  std::cout << "\n\n\n\n";

  dat::Container medals = api.getAll(MEDAL);
  for (size_t i = 0; i < medals.size(); i++)
  {
    for (size_t j = 0; j < medals[i].size(); j++)
    {
      printf("%s\t\t\t%s\n",
        medals[i][j].first.c_str(),
        medals[i][j].second.c_str());
    }
  }
  std::cout << "\n\n\n\n";
  dat::Container points = api.getAll(POINT);
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < points[i].size(); j++)
    {
      printf("%s\t\t\t%s\n",
             points[i][j].first.c_str(),
             points[i][j].second.c_str());
    }
  }
  return 0;
}
