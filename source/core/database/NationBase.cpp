#include "NationBase.h"


db::NationBase::NationBase() : nations(*elements) {}

Nation * db::NationBase::unpack(dat::Object * object)
{
  dat::Object obj = *object;
  dat::char3 shortName = obj[1].second.c_str();
  std::string name = obj[2].second;
  int participants = std::stoi(obj[3].second);
  dat::Contact contact = *dat::unpacking::contact(obj[4], obj[5], obj[6]);
  return new Nation(shortName, name, contact, participants);
}

//
// @funciton db::Nationbase::readFile()
//    Used to fill the database with data;
//
void db::NationBase::readFile(const std::string& filepath)
{
  dat::Container tempContainer; // @delete @temp @testing

  dat::Object prototype = 
  {
    {"type",           ""},   // Nation
    {"Code",           ""},   //PK              
    {"Name",           ""},                    
    {"ContactName",    ""},                    
    {"ContactPhone",   ""},             
    {"ContactEmail",   ""},
    {"#Participants",  ""}
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
    std::cout << "Nation " << i << "\n";      // @debug

    stream::readString(ss, prototype[0].second);
    stream::readChar3 (ss, prototype[1].second);
    stream::readString(ss, prototype[2].second);
    stream::readInt   (ss, prototype[3].second);
    stream::readString(ss, prototype[4].second);
    stream::readPhone (ss, prototype[5].second);
    stream::readEmail  (ss, prototype[6].second);

    tempContainer.push_back(prototype);
  } 
  writeFile(filepath, tempContainer);   // @testing @debug @delete me
}



