#include "file.h"

namespace file
{ 
  //
  // @brief prototype objects
  //
  dat::Container protos = 
  {
    {
      {"type",           ""},   // Nation
      {"Code",           ""},   //PK              
      {"Name",           ""},                    
      {"ContactName",    ""},                    
      {"ContactPhone",   ""},             
      {"ContactEmail",   ""},
      {"#Participants",  ""},  
    },

    {
      {"Type",        ""},  // Participant
      {"Name",        ""},  // PK
      {"Phone",       ""},
      {"Email",       ""},
      {"CountryCode", ""},  // FK
      {"Gender",      ""},
    },

    {
      {"Type",         ""},  // Sport
      {"Name",         ""},  // PK
      {"ScoreType",    ""},
      {"#Diciplines",  ""},
    },

    {
      {"Type",         ""},   // Dicipline
      {"#Starts",      ""},
      {"#Results",     ""},
      {"Name",         ""},  // PK
      {"Time",         ""}, 
      {"Date",         ""},
    },
  };

  // 
  // @functino file::getFilestream
  //
  static std::stringstream currentStream;  // file::ss  - @global object which contains the current stream.

  std::stringstream& getFilestream(const std::string& filepath)
  {
    
    std::ifstream inFile(filepath);
    currentStream.str(std::string());     // Clear stream contents.

    if (inFile)
    {
      currentStream << inFile.rdbuf();     // Flushing filestream contents into stringstream buffer
      inFile.close();
    }
    else 
      { std::cout << "Not finding file.. "<< filepath << "\n"; }//PMS_ERROR("File not found at %s", filepath.c_str()); }

    return currentStream;
  }

  //
  // @function file::readNations
  //
  void readNations (NationBase&  nationBase, const std::string& filepath)
  {  
    std::stringstream& ss = getFilestream(filepath);

    if (ss)
    {
      std::string numberOfObjects;
      stream::readInt(ss, numberOfObjects);
      //PMS_DEBUG("Found %s nationobjects...", numberOfObjects.c_str());
      for (int i = 0; i < std::stoi(numberOfObjects); i++){}
    }
  }
/*
  //
  // @function file::readParticipants
  //
  void readParticipants (ParticipantBase& participantBase, const std::string& filepath)
  {
    std::stringstream& ss = getFilestream(filepath);

    if (ss)
    {
      std::string numberOfObjects;
      stream::readInt(ss, numberOfObjects);
      //PMS_DEBUG("Found %s nationobjects...", numberOfObjects.c_str());
      for (int i = 0; i < std::stoi(numberOfObjects); i++){}
    }
  }

  //
  // @function file::readSports
  //
  void readSports       (SportBase&       sportBase,       const std::string& filepath)
  {
    std::stringstream& ss = getFilestream(filepath);

    if (ss) 
    {
      std::string numberOfObjects;
      stream::readInt(ss, numberOfObjects);
      //PMS_DEBUG("Found %s nationobjects...", numberOfObjects.c_str());
      for (int i = 0; i < std::stoi(numberOfObjects); i++){}
    }
  }*/

}