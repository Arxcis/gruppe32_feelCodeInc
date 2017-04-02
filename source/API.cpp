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
  { loadAllBases();}

void API::loadAllBases()
{
  std::cout << "loading all bases...\n";        // @debug
  dbContainerCache[NATION]      = nationBase_.getContainer();
  dbContainerCache[PARTICIPANT] = participantBase_.getContainer();
  dbContainerCache[SPORT]       = sportBase_.getContainer();
  dbContainerCache[POINT]       = pointBase_.getContainer("data/point.format");
  dbContainerCache[MEDAL]       = medalBase_.getContainer("data/medal.format");
}

//
// @class function add()
//
bool API::add(const dat::Object& object )
{  return 1;  }

//
// @class function update()
//  @param entity valid values
//       : NATION
//       : PARTICIPANT
//       : SPORT
//
auto API::update (const Entity entity, const dat::Object& object) -> const dat::Object
{  
  return dbContainerCache[entity][0];
}

//
// @class function updateAll()
//  @param entity valid values
//        : STARTS
//        : RESULTS
//
void API::updateAll (const Entity entity, const dat::Container& list, const std::string& id) 
  {}

//
// @class function remove()
//  @param entity valid values:
//      : DICIPLINE
//      : STARTS
//      : RESULTS
//
bool API::remove(const Entity entity, const std::string& id)
  {  return 1;  }


//
// @class function get()
//  @param entity valid values:
//      : NATION       
//      : PARTICIPANT
//      : SPORT
//
auto API::get(const Entity entity, const std::string& id) -> const dat::Object
{

  switch(entity)
  {
    case NATION:
    case PARTICIPANT:
    case SPORT:
      return dbContainerCache[entity][0];

    default:
      assert(false);    // Not a valid command.. abort mission
  }
}

//
// @class function getAll()
//  @param entity - valid values
//       : NATION
//       : PARTICIPANT
//       : SPORT
//       : POINT
//       : MEDAL
//       : STARTS
//       : RESULTS
//
auto API::getAll(const Entity entity, const std::string& id)  -> const dat::Container
{
  switch(entity)
  {
    case NATION:
    case PARTICIPANT:
    case SPORT:
    case POINT:
    case MEDAL:
      return dbContainerCache[entity];
      break;
    
    case STARTS:
      return test::startList;

    case RESULTS:
      return test::resultList;

    default:
      assert(false);     // Not a valid command.. abort mission
  }
}

//
// @class function quit()
//
void API::quit()
{
  
}

