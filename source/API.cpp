#include "API.h"


//
// @namespace test - testdata
//
namespace test {
  dat::Object 
  nation
  {
      {"Type",          "Nation"},               
      {"Code",          "NOR"},                   
      {"Name",          "Norge"},                    
      {"#Participants", "150"},  
      {"ContactName",   "Jonas"},                    
      {"ContactPhone",  "452000864"},             
      {"ContactEmail",   "jonas.solsvik@gmail.com"},  
  };

  dat::Object
  participant 
  {
      {"type", "Participant"},
      {"ID"  , "1002"},
      {"Name", "Jonas"},
      {"Phone", "452000864"},
      {"Email", "jonas.solsvik@gmail.com"},
      {"CountryCode", "NOR"},
      {"Gender", "Male"},
  };

  dat::Object
  sport 
  {   
      {"Type", "Sport"},
      {"Name", "Fotball"},   
      {"ScoreType", "Points"},
      {"#Diciplines", "3"},
      {"1", "Final"},
      {"2", "Semi-final"},
      {"3", "1/4-final"},
  };

  dat::Object
  dicipline 
  {
      {"Type","Dicipline"},
      {"Name", "Finale"},
      {"Time", "19:00"}, 
      {"Date","29.03.18"},
      {"#Participants", "2"},
      {"1", "1001"},
      {"2", "1002"},
      {"#Results","2"},
      {"1", "00:48:01"},
      {"2", "00:28:55"},
  };

  dat::Object
  medalStas
  {
      {"Type", "MedalStats"},
      {"#Entries", "3"},
      {"NOR", "1-2-3"},
      {"SWE", "0-2-3"},
      {"DAN", "0-0-5"},
  };

  dat::Object
  pointStats
  {
      {"Type", "PointStats"},
      {"#Entries", "3"},
      {"NOR", "100"},
      {"SWE", "90"},
      {"DAN", "80"},
  };


  dat::Container
  nations 
  {
    nation, 
    nation, 
    nation,
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
}

//
// @class function add()
//
bool API::add( dat::Object* object )
{  return 1;  }

//
// @class function addAll()
//
bool API::addAll (dat::Container* container) 
{ return 1; }

//
// @class function update()
//
bool API::update (dat::Object* object)
{  return 1;  }

//
// @class function remove()
//
bool API::remove(Entity entity, int id)
{  return 1;  }

//
// @class function get()
//
auto API::get(Entity entity, int id) -> dat::Object*
{
  switch(entity)
  {
    case NATION: 
      return &test::nation;
    case PARTICIPANT:
      return &test::participant;
    case SPORT:
      return &test::sport;
    case DICIPLINE:
      return &test::dicipline;
    default:
      return test::nulldata;
  }
}

//
// @class function getAll()
//
auto API::getAll(Entity entity)  -> dat::Container*
{
  switch(entity)
  {
    case NATION: 
      return &test::nations;
    case PARTICIPANT:
      return &test::participants;
    case SPORT:
      return &test::sports;
    case DICIPLINE: 
      return &test::diciplines;
    default: 
      return test::nulldatas;
  }
}

//
// @class function quit()
//
void API::quit()
{
  
}

