#include "API.h"


//
// @namespace test - testdata
//
namespace test 
{
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
}


API::API()
  { loadAllBases();}

void API::loadAllBases()
{
  std::cout << "loading all bases...\n";        // @debug
  dbContainerCache[NATION]      = nationBase_.getContainer();
  dbContainerCache[PARTICIPANT] = participantBase_.getContainer();
  dbContainerCache[SPORT]       = sportBase_.getContainer();
  dbContainerCache[POINT]       = pointBase_.getContainer();
  dbContainerCache[MEDAL]       = medalBase_.getContainer();
}

//
// @class function add()
//  @param object
//      example {   
//                  {"Type", "Sport"}, 
//                  {"Name", "Fotball"},
//                  {...},
//               }
bool API::add(const dat::Object& object )
{  return 1;  }

//
// @class function update()
//  @param dat::Object object
//     example {   
//                  {"Type", "Sport"}, 
//                  {"Name", "Fotball"},
//                  {...},
//             }
//
void API::update (const dat::Object& object)
{  }

//
// @class function updateAll()
//  @param dat::Container list 
//     example {
//                {{"Type", "Start"}, {....}, ..}, 
//                {{"Type", "Start"}, {....}, ..},
//             }
//  @param std::string id
//     example  "<sport>_<dicipline>"   or   "fotball_semi-final
//
void API::updateAll(const dat::Container& list, const std::string& id) 
  {}

//
// @class function remove()
//  @param  <entity>   + <id>
//        : DICIPLINE  + "<sport>_<dicipline>"
//        : STARTS     + "<sport>_<dicipline>"
//        : RESULTS    + "fotball_1/4-finale"
//
bool API::remove(const Entity entity, const std::string& id)
  {  return 1;  }


//
// @class function get()
//  @param entity valid values:
//      : NATION       
//      : PARTICIPANT
//      : SPORT
//  @param std::string id
//        example   "NOR"  or "Petter Northug"  or "Soccer"
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
//  @optional parameter std::string id
//        example "<sport>_<dicipline>" for getting STARTS and RESULTS
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

