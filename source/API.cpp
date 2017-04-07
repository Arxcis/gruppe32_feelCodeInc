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
bool API::add(const dat::Object object )
{
  if(object[0].second == "Nation")
  { 
    bool response = nationBase_.add(object);
    nationBase_.flush();
    return response;
  }

  else if(object[0].second == "Participant")
  { 
    bool response = participantBase_.add(object);
    participantBase_.flush();
    return response;
  }

  else if(object[0].second == "Sport")
  { 
    bool response = sportBase_.add(object);
    sportBase_.flush();
    return response;
  }

  else if(object[0].second == "Medal")
  { return medalBase_.add(object); }

  else if(object[0].second == "Point")
  { return pointBase_.add(object); }

  return false; //type was unreccognized or CANCELED; DON'T ADD.
}


//
// @class function add()
//  @param object
//      example {   
//                  {"Type", "Sport"}, 
//                  {"Name", "Fotball"},
//                  {...},
//               }
bool API::count(const Entity entity, const dat::Field& field)
{
  size_t count;
  switch (entity)
  {
    case NATION:      count = nationBase_.countMatchingFields(field);      break;
    case PARTICIPANT: count = participantBase_.countMatchingFields(field); break;
    case SPORT:       count = sportBase_.countMatchingFields(field);       break;
    case POINT:       count = pointBase_.countMatchingFields(field);       break;
    case MEDAL:       count = medalBase_.countMatchingFields(field);       break;

    default: assert(false);     //Not a valid command... abort mission
  }
  return false; //type was unreccognized or CANCELED; DON'T ADD.
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
  { 
    nationBase_.update(object); 
    nationBase_.flush();
  }

  else if(!object[0].second.compare("Participant"))
  { 
    participantBase_.update(object); 
    participantBase_.flush();
  }

  else if(!object[0].second.compare("Sport"))
  { 
    sportBase_.update(object); 
    sportBase_.flush();
  }

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
auto API::get(const Entity entity, const std::string& id) -> const dat::Object
{
  dat::Object tempObj;
  switch(entity)
  {
    case NATION:      nationBase_.getSortID(tempObj, id); setParticipantCount(tempObj); break;  //   ID TextElement
    case PARTICIPANT: participantBase_.getSortID(tempObj, std::stoi(id)); break;  //      Numelement
    case SPORT:       sportBase_.getSortID(tempObj, id); break;                   //      textElement
    case POINT:       pointBase_.getSortID(tempObj, std::stoi(id)); break;        //      Numelement
    case MEDAL:       medalBase_.getSortID(tempObj, std::stoi(id)); break;        //      Numelement
 
    default: assert(false);// Not a valid command.. abort mission
  }
  return tempObj;
}

//
// @class function find()
//  @param entity valid values:
//      : NATION       
//      : PARTICIPANT
//      : SPORT
//  @param std::string id
//        example   "NOR"  or "Petter Northug"  or "Soccer"
//
bool API::find(const Entity entity, const std::string& id)
{
  switch (entity)
  {
    case NATION:      return nationBase_.findSortID(id);                 //   ID TextElement
    case PARTICIPANT: return participantBase_.findSortID(std::stoi(id)); //      Numelement
    case SPORT:       return sportBase_.findSortID(id);                  //      textElement
    case POINT:       return pointBase_.findSortID(std::stoi(id));       //      Numelement
    case MEDAL:       return medalBase_.findSortID(std::stoi(id));       //      Numelement

    default: assert(false);// Not a valid command.. abort mission
  }
return false;
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
    case NATION:      
      tempContainer = nationBase_.getContainer();      
      setParticipantCount(tempContainer);                              break;
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

    default: assert(false);     //Not a valid command... abort mission
  }
  return tempContainer;
}

void API::setParticipantCount(dat::Object& nation)
{
  dat::Field protoField{ "CountryCode", nation[1].second };
  nation[3].second = std::to_string(participantBase_.countMatchingFields(protoField)); //update the containers objects participantCount;
}

void API::setParticipantCount(dat::Container& nations)
{
  for(size_t i = 0; i < nations.size(); i++)
  { setParticipantCount(nations[i]); }
}

void API::FilterObject(dat::Object& object, int...)
{

}

dat::Container API::getAllWithField(const Entity entity, const dat::Field & field)
{
  dat::Container tempContainer;
  switch (entity)
  {
    case NATION:      tempContainer = nationBase_.getWithMatchingField(field);      break;
    case PARTICIPANT: tempContainer = participantBase_.getWithMatchingField(field); break;
    case SPORT:       tempContainer = sportBase_.getWithMatchingField(field);       break;
    case POINT:       tempContainer = pointBase_.getWithMatchingField(field);       break;
    case MEDAL:       tempContainer = medalBase_.getWithMatchingField(field);       break;

    default: assert(false); break;     //Not a valid command... abort mission
  }
  return tempContainer;
}

void API::updateMedals(const dat::Container& results)
{
  const dat::Container medals = medalBase_.getContainer();

  List resultList(Sorted);
  dat::Object protoParticipant{ {"Type","Participant"} };
  dat::Object tempObject;

  if(results.size() > 0)
  { 
    Result* top[3];
    size_t listSize = results.size();
    if(results[0][0].second == "Point")
    {
      for (size_t i = 0; i < listSize; i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = listSize; i > listSize-3; i--)
      {  top[listSize-i] = (Result*)resultList.removeNo(i); }
    }
    else
    {
      for (size_t i = 0; i < listSize; i++)
      { resultList.add(new Result(dat::packing::unpackTimeResult(results[i]))); }
      for (size_t i = 0; i < 3; i++)
      { top[i] = (Result*)resultList.removeNo(0); }
    }
    for (size_t i = 0; i < 3; i++)
    {
      assert(participantBase_.getSortID(protoParticipant, top[i]->getID())); //pull the participant in the resultlist at top[i] -> dat:Object 
      assert(nationBase_.findSortID(protoParticipant[5].second.c_str())); //@PRIMARY FOR TESTING, make sure the naiton exists.
     
      //create a proto object with the nationcode
      dat::Object protoMedal{ 
        { "Type",                       "Medal" }, 
        { "Code",   protoParticipant[5].second  },
        { "Value",                  "00-00-00" } 
      }; 
      
      if (0 > medalBase_.getWithMatchingField(protoMedal, protoMedal[1])) //look for matching nations and assign if found to protoMedal
      { medalBase_.add(protoMedal); } //if a medalobject with the code was not found however, add the protoobject with the nationcode   



      MedalRank* nationMedals = (MedalRank*)medalBase_.unpack(protoMedal); //obtain a copy of the actual object.
      size_t value = nationMedals->getValue();
      nationMedals->giveMedal(i + 1); //add a medal per the top[i]-position


      // @note cannot bind temp-value (Clang-Xcode)
      tempObject = medalBase_.pack(nationMedals);
      medalBase_.updateWithMatchingField(tempObject, protoMedal[1],value); //update the medalbaseObject
      


      //Add element back into list when done to let list delete all the elements from memory
      resultList.add(top[i]); 
    }
  }
}

void API::updatePoints(const dat::Container& results)
{
  dat::Container points = pointBase_.getContainer();
  List resultList(Sorted);
  dat::Object protoParticipant{ { "Type","Participant" } };
  dat::Object tempObject;

  if (results.size() > 0)
  {
    Result* top[6];
    size_t listSize = results.size();
    if (results[0][0].second == "Point")
    {
      for (size_t i = 0; i < listSize; i++)
      { resultList.add(new Result(dat::packing::unpackPointResult(results[i]))); }
      for (size_t i = listSize; i > listSize - 6; i--)
      { top[listSize - i] = (Result*)resultList.removeNo(i); }
    }
    else
    {
      for (size_t i = 0; i < listSize; i++)
      {resultList.add(new Result(dat::packing::unpackTimeResult(results[i]))); }
      for (size_t i = 0; i < 6; i++)
      { top[i] = (Result*)resultList.removeNo(0); }
    }
    for (size_t i = 0; i < 6; i++)
    {
      assert(participantBase_.getSortID(protoParticipant, top[i]->getID())); //pull the participant in the resultlist at top[i] -> dat:Object 
      assert(nationBase_.findSortID(protoParticipant[5].second.c_str())); //@PRIMARY FOR TESTING, make sure the naiton exists.

      //create a proto object with the nationcode
      dat::Object protoPoint{
        { "Type",                       "Point" },
        { "Code",    protoParticipant[5].second },
        { "Value",                         "0" }
      };

      if (0 > pointBase_.getWithMatchingField(protoPoint, protoPoint[1])) //look for matching nations and assign if found to protoMedal
      { pointBase_.add(protoPoint); } 

      Rank* nationPoints = pointBase_.unpack(protoPoint); //obtain a copy of the actual object.
      size_t value = nationPoints->getValue();
      nationPoints->givePointByPosition(i+1); //add a point per the top[i]-position


            // @note cannot bind temp-value (Clang-Xcode)
      tempObject = pointBase_.pack(nationPoints);
      pointBase_.updateWithMatchingField(tempObject, protoPoint[1], value); //update the medalbaseObject

      //Add element back into list when done to let list delete all the elements from memory
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

