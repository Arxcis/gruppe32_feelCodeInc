//
// @file    core/File.h
// @repo    gruppe32
// @created 29.03.17 by Jonas
// @brief   Funksjoner som konstruerer database-objekter fra fil objekter
//          
//

#include <string>

//
// @namespace file skriver til den respektive database ved dependency injection, istedet for
//              globale inkludes.
//
namespace file
{
  void readNations      (NationBase&      nationBase,      const std::string& filepath);
  void readParticipants (ParticipantBase& participantBase, const std::string& filepath);
  void readSports       (SportBase&       sportBase,       const std::string& filepath);
}