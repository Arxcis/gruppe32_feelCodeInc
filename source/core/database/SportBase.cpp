#include "SportBase.h"


db::SportBase::SportBase() : sports(*elements) {}
Sport * db::SportBase::unpack(dat::Object * object)
{
  dat::Object obj = *object;
  dat::
  return nullptr;
}

//
// @funciton db::SportBase::readFile()
//    Used to fill the database with data;
//
auto db::SportBase::readFile(const std::string& filepath) -> dat::Container
{
  auto tempContainer = dat::Container{}; // @delete @temp @testing

  auto prototype = dat::Object
  {
    {"Type",         ""},  // Sport
    {"Name",         ""},  // PK
    {"ScoreType",    ""},
    {"#Diciplines",  ""}
  };

  auto fileToStream  = [filepath, this]()
  { 
    auto innFile = std::ifstream { filepath };
    assert(innFile);
    std::cout << "Opening "<< filepath << "...\n";  // @debug
          
    ss << innFile.rdbuf();    // Swapping buffers
    innFile.close();
  };
  
  fileToStream();

  // Reading number of objects.
  auto objectCount = std::string{};
  stream::readInt(ss,objectCount);

    // Loop through all objects
  for (auto i=0; i < std::stoi(objectCount); i++)
  {
    auto thisProto = prototype;
    std::cout << "Sport " << i << "\n";

    stream::readString (ss, thisProto[0].second);
    stream::readString (ss, thisProto[1].second);
    stream::readEnum   (ss, thisProto[2].second, {"Point", "Medal"});
    stream::readInt    (ss, thisProto[3].second);

    for (auto j=4; j < (4+std::stoi(thisProto[3].second)); j++)
    { 
      thisProto.push_back(
        { std::to_string(j-4), "" });

      stream::readString(ss, thisProto[j].second); 
      //std::cout << thisProto[j].second << std::endl;  // @debug
    }
    tempContainer.push_back(thisProto);
  } 
  writeFile(filepath, tempContainer);  // @testing @debug @delete me
  return tempContainer;
}
