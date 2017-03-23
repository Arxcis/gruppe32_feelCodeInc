


#include <vector>
#include <string>

//
// @namespace test - testdata
// @brief     a collection of test data that simulate data
//            which controller recieves from the database.
//
namespace test {
  std::vector<std::string> 
  nation 
  {
      "Norge", 
      "NOR", 
      "100",
      "452000864",
      "jonas.solsvik@gmail.com",
  };

  std::vector<std::string>
  athlete 
  {
      "1002", 
      "Jonas",
      "452000864",
      "jonas.solsvik@gmail.com", 
      "100",
      "Male"
  };

  std::vector<std::string>
  sport 
  {
      "Fotball", 
      "Points",
      "3", 
      "Event1",
      "Event2",
      "Event3",
  };

  std::vector<std::string>
  event 
  {
      "Finale - Golden Goal",
      "19:00",
      "29.03.18",
      "2",
      "Oddvar FK",
      "Brå BK",
      "2",
      "1",
      "0",
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