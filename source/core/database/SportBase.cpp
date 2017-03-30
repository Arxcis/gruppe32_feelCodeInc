#include "SportBase.h"


db::SportBase::SportBase() : sports(*elements) {}
Sport * db::SportBase::unpack(dat::Object * object)
{
  //UNPACK UR STUFF PLS
  return nullptr;
}

//
// @funciton db::SportBase::readFile()
//    Used to fill the database with data;
//
dat::Container db::SportBase::readFile(const std::string& filepath)
{
  dat::Container tempContainer; // @delete @temp @testing

  dat::Object prototype =
  {
    {"Type",         ""},  // Sport
    {"Name",         ""},  // PK
    {"ScoreType",    ""},
    {"#Diciplines",  ""}
  };

  std::ifstream innFile(filepath);

  // Crashing the program if file not found.
  assert(innFile);
  std::cout << "Opening "<< filepath << "...\n";  // @debug
      
  // Flushing filebuffer into a stringstream and closing the file
  ss << innFile.rdbuf();
  innFile.close();

  // Reading number of objects.
  std::string objectCount;
  stream::readInt(ss,objectCount);

    // Loop through all objects
  for(int i=0; i < std::stoi(objectCount); i++)
  {
    dat::Object thisProto = prototype;
    std::cout << "Sport " << i << "\n";

    stream::readString (ss, thisProto[0].second);
    stream::readString (ss, thisProto[1].second);
    stream::readEnum   (ss, thisProto[2].second, {"Point", "Medal"});
    stream::readInt    (ss, thisProto[3].second);

    for(int j=4; j < (4+std::stoi(thisProto[3].second)); j++)
    { 
      thisProto.push_back(
        {std::to_string(j-4), ""});

      stream::readString(ss, thisProto[j].second); 
      //std::cout << thisProto[j].second << std::endl;  // @debug
    }
    tempContainer.push_back(thisProto);
  } 
  writeFile(filepath, tempContainer);  // @testing @debug @delete me
  return tempContainer;
}
