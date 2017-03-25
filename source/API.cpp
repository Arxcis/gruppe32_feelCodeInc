#include "API.h"


//
// @namespace test - testdata
//
namespace test {
  std::vector<std::string> 
  nation
  {
      "nation",                   // Type of object
      "NOR",                      // Code
      "Norge",                    // Name
      "150",                      // Number of participants
      "Jonas",                     // Name of contact
      "452000864",                // Phone
      "jonas.solsvik@gmail.com",  // Email
  };

  std::vector<std::string>
  participant 
  {
      "participant",                 // Type of object
      "1002",                    // ID
      "Jonas",                   // Name
      "452000864",               // Phone
      "jonas.solsvik@gmail.com", // Email
      "NOR",                     // Nation Code 
      "Male"                     // enum Gender
  };

  std::vector<std::string>
  sport 
  {   
      "sport",                // Type of object
      "Fotball",                // Sport name
      "Points",                 // Score type
      "3",                      // Number of events
      "Event1",                 // Event 1
      "Event2",                 // Event 2
      "Event3",                 // Event 3
  };

  std::vector<std::string>
  event 
  {
      "event",                  // Type of object
      "Finale - Golden Goal",   // Name of event
      "19:00",                  // Time of event
      "29.03.18",               // Date of event
      "2",                      // number of participants
      "1001",                   // participant 1
      "1002",                   // participant 2
      "2",                      // number of Results
      "1",                      // Result 1
      "0",                      // Result 2
  };

  std::vector<std::vector<std::string>>
  nations 
  {
    nation, 
    nation, 
    nation,
  };  

  std::vector<std::vector<std::string>>
  participants 
  {
    participant, 
    participant, 
    participant,
  };  

  std::vector<std::vector<std::string>>
  sports 
  {
    sport, 
    sport, 
    sport,
  };  

  std::vector<std::vector<std::string>>
  events 
  {
    event, 
    event, 
    event,
  };  

  std::vector<std::string>* nulldata = nullptr;
  std::vector<std::vector<std::string>>* nulldatas = nullptr;
}

//
// @class function add()
//
bool API::add( std::vector<std::string>* container)
{  return 1;  }

//
// @class function addAll()
//
bool API::addAll (std::vector<std::vector<std::string>>* containers) 
{ return 1; }

//
// @class function update()
//
bool API::update (std::vector<std::string>* container)
{  return 1;  }

//
// @class function remove()
//
bool API::remove(Entity entity, int id)
{  return 1;  }

//
// @class function get()
//
auto API::get(Entity entity, int id) -> std::vector<std::string>*
{
  switch(entity)
  {
    case NATION: 
      return &test::nation;
    case PARTICIPANT:
      return &test::participant;
    case SPORT:
      return &test::sport;
    case EVENT:
      return &test::event;
    default:
      return test::nulldata;
  }
}

//
// @class function getAll()
//
auto API::getAll(Entity entity)  -> std::vector<std::vector<std::string>>*
{
  switch(entity)
  {
    case NATION: 
      return &test::nations;
    case PARTICIPANT:
      return &test::participants;
    case SPORT:
      return &test::sports;
    case EVENT: 
      return &test::events;
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

