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
void db::SportBase::readFile(const std::string filepath)
{

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
    std::cout << "Sport " << i << "\n";

    stream::readString (ss, prototype[0].second);
    stream::readString (ss, prototype[1].second);
    stream::readEnum   (ss, prototype[2].second, {"Point", "Medal"});
    stream::readInt    (ss, prototype[3].second);

    for(int j=4; j < (4+std::stoi(prototype[3].second)); j++)
      { stream::readString (ss, prototype[i].second); }

  } 
}
