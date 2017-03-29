//
// @file    core/File.h
// @repo    gruppe32
// @created 29.03.17 by Jonas
// @brief   Funksjoner som konstruerer database-objekter fra fil objekter
//          
//

#include <iostream>   // cout
#include <fstream>    // ifstream, ofstream
#include <sstream>    // stringstream
#include <string>

#include "../enum.h"                // For NAITON, PARTICPANT.....
#include "../tool/stream.h"         // stream::readData()-functions
#include "../tool/pms_log.h"        // PMS_ERROR()
#include "database/NationBase.h"
#include "database/ParticipantBase.h"
#include "database/SportBase.h"

//
// @namespace file 
//
namespace file
{
  std::stringstream& getFilestream(const std::string& filepath);
  void readNations      (NationBase&      nationBase,      const std::string& filepath);
  void readParticipants (ParticipantBase& participantBase, const std::string& filepath);
  void readSports       (SportBase&       sportBase,       const std::string& filepath);
}