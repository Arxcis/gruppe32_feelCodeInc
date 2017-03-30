#pragma once
//
// @file    enum.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   Contains global enums
//

enum Entity 
{
  NATION,
  PARTICIPANT, 
  SPORT,
  DICIPLINE,
};

//
// @file    user/MenuState.h
// @repo    gruppe32
// @created 29.03.17 by Jonas (original 25.03)
// @brief   Revived this file from the dead(commit  06219ee)
//          Turns out that it also is a usefull thing to tell apart different
//          integer-representations of states in the new object-oriented
//          state system after all.
//

enum MenuState : int
{
  EXIT = -1,
  START =  0,

  NATION_BASE   = 1,
  NATION_SELECT = 2,
  NATION_EDIT   = 3,
  NATION_NEW    = 4,

  PART_BASE   = 5,
  PART_SELECT = 6,
  PART_EDIT   = 7,
  PART_NEW    = 8,

  SPORT_BASE   = 9,
  SPORT_SELECT = 10,
  SPORT_EDIT   = 11,
  SPORT_NEW    = 12,

  POINT_STATS = 13,
  MEDAL_STATS = 14,

  DICI_SELECT = 15,
  DICI_EDIT   = 16,
  DICI_DELETE = 17,
  DICI_NEW    = 18,

  SLIST_SELECT = 19,
  SLIST_DELETE = 20,
  RLIST_SELECT = 21,
  RLIST_DELETE = 22,
};