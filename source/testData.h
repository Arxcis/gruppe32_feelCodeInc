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
      "150",                      // Number of athletes
      "Jonas"                     // Name of contact
      "452000864",                // Phone
      "jonas.solsvik@gmail.com",  // Email
  };

  std::vector<std::string>
  athlete 
  {
      "athlete",                 // Type of object
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
      "2",                      // number of Athletes
      "1001",                   // Athlete 1
      "1002",                   // Athlete 2
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
  athletes 
  {
    athlete, 
    athlete, 
    athlete,
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