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
  start
  {
    {"Type", "Start"},
    {"ID", "1001"},
    {"Name", "Jonas Styggardson"},
  };

  const dat::Container
  startList
  {
    start,
    start,
    start,
    start,
  };

  const dat::Object
  result
  {
    {"Type", "Result"},
    {"ID",   "1001"},
    {"Value", "00:03:58"},
  };

  const dat::Container
  resultList
  {
    result,
    result,
    result,
    result,
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
  assert(entity == NATION || entity == PARTICIPANT || entity == SPORT);
  return dbContainerCache[entity][0];
}

//
// @class function getAll()
//
auto API::getAll(const Entity entity)  -> const dat::Container
{
  assert(entity == NATION || entity == PARTICIPANT || entity == SPORT);
  return dbContainerCache[entity];
}

auto API::getStarts (const std::string& id)  -> const dat::Container
{
  return test::startList;
}

auto API::getResults(const std::string& id)  -> const dat::Container
{
 return test::resultList;
}

void API::setStarts (const std::string& id, const dat::Container& starts)
{
}

void API::setResults(const std::string& id, const dat::Container& results)
{
}

// DELETE FUNCTIONS
void API::deleteStarts(const std::string& id)
{
}

void API::deleteResults(const std::string& id)
{
}

void API::deleteDicipline(const std::string& id){}


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

