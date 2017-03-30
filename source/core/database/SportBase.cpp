#include "SportBase.h"


db::SportBase::SportBase() : sports(*elements) {}
Sport * db::SportBase::unpack(dat::Object * object)
{
  //UNPACK UR STUFF PLS
  return nullptr;
}

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

  if(innFile)
  {
    std::cout << "Opening "<< filepath << "...\n";  // @debug
  }
  else 
    { std::cout << "File "<< filepath << " not found...\n"; }   // @debug
}