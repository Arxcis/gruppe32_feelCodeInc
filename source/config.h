#pragma once
//
// @file    config.h
// @repo    gruppe32
// @created 04.04.17 by Jonas
// @brief   We will try to keep constants here which have a big impact on the 
//          CONFIGURATION of the system.
//

#include <string>

const std::string nationsFile      = "data/oblig/nations.dta";
const std::string participantsFile = "data/oblig/participants.dta";
const std::string sportsFile       = "data/oblig/sports.dta";

const std::string medalsFile       = "data/oblig/medals.dta";
const std::string pointsFile       = "data/oblig/points.dta";
const std::string diciplinePath    = "data/oblig/dici_";

const int maxDiciplines = 20;         // Max diciplines per sport
const int maxNations = 200;           // Max Nations registered in the system

// Graphics
const size_t colsizeMini   = 5;
const size_t colsize       = 12;
const size_t colsizeMid    = 30;

const size_t divsizeBig    = 80;
const size_t divsizeMid    = 72;
const size_t newpageLines  = 40;
