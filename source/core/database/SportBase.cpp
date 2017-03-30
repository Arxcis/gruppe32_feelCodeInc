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
}