#include "API.h"


//
// @namespace test - testdata
//
namespace test 
{
  const dat::Object 
  nation
  {
      {"Type",          "Nation"},               
      {"Code",          "NOR"},       //PK              
      {"Name",          "Norge"},                    
      {"#Participants", "150"},  
      {"ContactName",   "Jonas"},                    
      {"ContactPhone",  "452000864"},             
      {"ContactEmail",   "jonas.solsvik@gmail.com"},  
  };

  const dat::Object
  participant 
  {
      {"type", "Participant"},
      {"ID"  , "1002"},     //PK
      {"Name", "Jonas"},
      {"Phone", "452000864"},
      {"Email", "jonas.solsvik@gmail.com"},
      {"CountryCode", "NOR"},
      {"Gender", "Male"},
  };

  const dat::Object
  sport 
  {   
      {"Type", "Sport"},
      {"Name", "Fotball"},     //PK
      {"ScoreType", "Points"},
      {"#Diciplines", "3"},
      {"1", "Final"},
      {"2", "Semi-final"},
      {"3", "1/4-final"},
  };

  const dat::Object
  dicipline 
  {
      {"Type","Dicipline"},
      {"#Starts", "2"},
      {"#Results","2"},
      {"Name", "Finale"},     //PK
      {"Time", "19:00"}, 
      {"Date","29.03.18"},
  };

  const dat::Object
  medalStats
  {
      {"Type", "MedalStats"},
      {"#Entries", "3"},
      {"NOR", "1-2-3"},
      {"SWE", "0-2-3"},
      {"DAN", "0-0-5"},
  };

  const dat::Object
  pointStats
  {
      {"Type", "PointStats"},
      {"#Entries", "3"},
      {"NOR", "100"},
      {"SWE", "90"},
      {"DAN", "80"},
  };

  const dat::Object
  startList
  {
    {"Type", "StartList"},
    {"#Entries", "2"},
    {"1001", "1001"},
    {"1002", "1002"},
  };

  const dat::Object
  resultList
  {
    {"Type", "ResultList"},
    {"#Entries", "2"},
    {"1001", "00:48:01"},
    {"1002", "00:28:55"},
  };


  const dat::Container
  nations 
  {
    nation, 
    nation, 
    nation,
  };  

  const dat::Container
  participants 
  {
    participant, 
    participant, 
    participant,
  };  

  const dat::Container
  sports 
  {
    sport, 
    sport, 
    sport,
  };  

  const dat::Container
  diciplines 
  {
    dicipline, 
    dicipline, 
    dicipline,
  };  

  const dat::Object* nulldata = nullptr;
  const dat::Container* nulldatas = nullptr;
}


API::API()
{ 
  loadAllBases();
}

void API::loadAllBases()
{
  std::cout << "loadAllBases...\n";
  file::readNations(nationBase_, "toight");
}

//
// @class function add()
//
bool API::add( const dat::Object* object )
{  return 1;  }

//
// @class function update()
//
bool API::update (const dat::Object* object)
{  return 1;  }

//
// @class function remove()
//
bool API::remove(const Entity entity, const dat::Field& id)
{  return 1;  }

//
// @class function get()
//
auto API::get(const Entity entity, const dat::Field& id) -> const dat::Object*
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
auto API::getAll(const Entity entity)  -> const dat::Container*
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

