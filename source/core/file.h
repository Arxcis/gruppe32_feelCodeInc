//
// @file    core/File.h
// @repo    gruppe32
// @created 29.03.17 by Jonas
// @brief   Funksjoner som konstruerer database-objekter fra fil objekter
//          
//

#include <string>
#include "../enum.h"      // For NAITON, PARTICPANT.....
#include "database/NationBase.h"
#include "database/ParticipantBase.h"
#include "database/SportBase.h"

//
// @namespace file skriver til
//
namespace file
{
  void readNations      (NationBase&      nationBase,      const std::string& filepath);
  void readParticipants (ParticipantBase& participantBase, const std::string& filepath);
  void readSports       (SportBase&       sportBase,       const std::string& filepath);
}