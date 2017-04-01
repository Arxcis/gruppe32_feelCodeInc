#include "API.h"


//
// @namespace test - testdata
//
namespace test 
{
  const dat::Object
  dicipline 
  {
      {"Type","Dicipline"},
      {"Name", "Finale"},     //PK
      {"Time", "19:00"}, 
      {"Date","29.03.18"},
      {"#Starts", "2"},
      {"#Results","2"},
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
  diciplines 
  {
    dicipline, 
    dicipline, 
    dicipline,
  };  
}


API::API()
{ 
  loadAllBases();
}

void API::loadAllBases()
{
  std::cout << "loading all bases...\n";        // @debug
  dbContainerCache[NATION]      = nationBase_.readFile("data/nation.format");
  dbContainerCache[PARTICIPANT] = participantBase_.readFile("data/participant.format");
  dbContainerCache[SPORT]       = sportBase_.readFile("data/sport.format");
  dbContainerCache[POINT]       = pointBase_.readFile("data/point.format");
  dbContainerCache[MEDAL]       = medalBase_.readFile("data/medal.format");
}

//
// @class function add()
//
bool API::add(const dat::Object& object )
{  return 1;  }

//
// @class function update()
//
auto API::update (const Entity entity, const dat::Object& object) -> const dat::Object
{  
  return dbContainerCache[entity][0];
}

//
// @class function remove()
//
bool API::remove(const Entity entity, const std::string& id)
{  return 1;  }

//
// @class function get()
//
auto API::get(const Entity entity, const std::string& id) -> const dat::Object
{
  if(entity == NATION || entity == PARTICIPANT || entity == SPORT)
    { return dbContainerCache[entity][0]; }
  else if (entity == PARTICIPANT)
    { return test::dicipline; }
  else 
    { return {}; }
  
}

//
// @class function getAll()
//
auto API::getAll(const Entity entity)  -> const dat::Container
{
  if(entity == NATION || entity == PARTICIPANT || entity == SPORT)
    { return dbContainerCache[entity]; }
  else if(entity == DICIPLINE)
    { return test::diciplines; }
  else
    { return {}; }
  
}

auto API::getStarts (const dat::Field& id)  -> const dat::Object
{
  return test::startList;
}

auto API::getResults(const dat::Field& id)  -> const dat::Object
{
 return test::resultList;
}

auto API::getPoints () -> const dat::Container
{
  return dbContainerCache[POINT];
}

auto API::getMedals () -> const dat::Container
{
 return dbContainerCache[MEDAL];
}
//
// @class function quit()
//
void API::quit()
{
  
}

