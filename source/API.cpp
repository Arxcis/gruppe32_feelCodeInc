#include "API.h"


//
// @namespace test - testdata
//
namespace test 
{
  const dat::Object
  start
  {
    { "Type",     "Start"},
    { "ID",      "1001" },
    { "StartNR", "1" },
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
    { "Type", "Result"},
    { "ID",   "1001"},
    { "Value", "00:03:58"},
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
  std::cout << "API loading all bases...\n";        // @debug
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
{
  if(!object[0].second.compare("Nation"))
  { return nationBase_.add(object); }

  else if(!object[0].second.compare("Participant"))
  { return participantBase_.add(object); }

  else if(!object[0].second.compare("Sport"))
  { return sportBase_.add(object); }

  else if(!object[0].second.compare("Medal"))
  { return medalBase_.add(object); }

  else if(!object[0].second.compare("Point"))
  { return pointBase_.add(object); }

  return false;
}

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
{ 
   if(!object[0].second.compare("Nation"))
  { nationBase_.update(object); }

  else if(!object[0].second.compare("Participant"))
  { participantBase_.update(object); }

  else if(!object[0].second.compare("Sport"))
  { sportBase_.update(object); }

  else if(!object[0].second.compare("Medal"))
  { medalBase_.update(object); }

  else if(!object[0].second.compare("Point"))
  { pointBase_.update(object); }
}

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


/*



*/
void API::updateAll(const Entity entity, const dat::Container& list, const std::string& id) 
{
  assert(entity == STARTS || entity == RESULTS);// Only these are allowed in updateAll
  if (list.size() > 0)
  {
    switch (entity)
    {
      case STARTS:  sportBase_.writeStarts(id, list);  break;
      case RESULTS: sportBase_.writeResults(id, list); updateMedals(list); updatePoints(list); break;
    }
  }
}

//
// @class function remove()
//  @param  <entity>   + <id>
//        : DICIPLINE  + "<sport>_<dicipline>"
//        : STARTS     + "<sport>_<dicipline>" 
//        : RESULTS    + "fotball_1/4-finale"
//
void API::remove(const Entity entity, const std::string& id)
{  
  dat::Container empty;
  switch (entity)
  {
    case DICIPLINE: sportBase_.removeDicipline(id);     break;
    case STARTS:    sportBase_.writeStarts(id, empty);  break;
    case RESULTS:   sportBase_.writeResults(id, empty); break;
    default: assert(false); //
  }
}


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
  dat::Object tempObj;
  switch(entity)
  {
    case NATION:      nationBase_.getID(tempObj, id); break;                  //   ID TextElement
    case PARTICIPANT: participantBase_.getID(tempObj, std::stoi(id)); break;  //      Numelement
    case SPORT:       sportBase_.getID(tempObj, id); break;                   //      textElement
    case POINT:       pointBase_.getID(tempObj, std::stoi(id)); break;        //      Numelement
    case MEDAL:       medalBase_.getID(tempObj, std::stoi(id)); break;        //      Numelement
 
    default: assert(false);// Not a valid command.. abort mission
  }
  return tempObj;
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
  dat::Container tempContainer;
  switch(entity)
  {
    case NATION:      tempContainer = nationBase_.getContainer();      break;
    case PARTICIPANT: tempContainer = participantBase_.getContainer(); break;
    case SPORT:       tempContainer = sportBase_.getContainer();       break;
    case POINT:       tempContainer = pointBase_.getContainer();       break;
    case MEDAL:       tempContainer = medalBase_.getContainer();       break;
    
    case STARTS:
      if (!sportBase_.readStarts(tempContainer, id))
      { assert(false); }

    case RESULTS:
      if (!sportBase_.readResults(tempContainer, id))
      { assert(false); }

    default: assert(false);  // Not a valid command.. abort mission
  }
  return tempContainer;
}

void API::updateMedals(const dat::Container& results)
{
  const dat::Container medals = medalBase_.getContainer();

  List resultList(Sorted);
  
  dat::Object temp;

  if(results.size() > 0)
  { 
    Result* top[3];
    size_t listSize = resultList.noOfElements();
    if(results[0][2].first.compare("Point"))
    {
      for (size_t i = 0; i < results.size(); i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = listSize-1; i >= listSize-3; i--)
      {  top[i] = (Result*)resultList.removeNo(i); }
    }
    else
    {
      for (size_t i = 0; i < results.size(); i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = 0; i < 3; i++)
      { top[i] = (Result*)resultList.removeNo(i); }
    }
    for (size_t i = 0; i < 3; i++)
    {
      assert(participantBase_.getID(temp, std::to_string(top[i]->getID()))); //pull the participant in the resultlist at top[i] -> dat:Object 
      for (size_t j = 0; j < medals.size(); j++) //loop on medalranks (per nation)
      {
        if (!medals[j][1].second.compare(temp[5].second)) //find the medalrank where CODE matches the new top[i]-participant
        {
          MedalRank* nationMedals = (MedalRank*)medalBase_.unpack(medals[j]);
          nationMedals->giveMedal(i+1);
          medalBase_.update(medalBase_.pack(nationMedals));
        }
      }
      resultList.add(top[i]);
    }
  }
}

void API::updatePoints(const dat::Container& results)
{
  dat::Container points = pointBase_.getContainer();
  List resultList(Sorted);
  
  dat::Object temp;

  if(results.size() > 0)
  { 
    Result* top[6];
    size_t listSize = resultList.noOfElements();
    if(results[0][2].first.compare("Point"))
    {
      for (size_t i = 0; i < results.size(); i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = listSize-1; i >= listSize-6; i--)
      {  top[i] = (Result*)resultList.removeNo(i); } 
    }
    else
    {
      for (size_t i = 0; i < results.size(); i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = 0; i < 6; i++)
      { top[i] = (Result*)resultList.removeNo(i); }
    }
    for (size_t i = 0; i < 6; i++)
    {
      assert(participantBase_.getID(temp, std::to_string(top[i]->getID()))); //pull the participant in the resultlist at top[i] -> dat:Object 
      for (size_t j = 0; j < points.size(); j++) //loop on medalranks (per nation)
      {
        if (!points[j][1].second.compare(temp[5].second)) //find the medalrank where CODE matches the new top[i]-participant
        {
          Rank* nationPoints = pointBase_.unpack(points[j]);
          nationPoints->givePoint(i + 1);
          pointBase_.update(medalBase_.pack(nationPoints));
        }
      }
      resultList.add(top[i]);
    }
  }
}

//
// @class function quit()
//
void API::quit()
{
  
}

