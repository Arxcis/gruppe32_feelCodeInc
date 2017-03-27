#pragma once
//
// @file    user/MenuState.h
// @repo    gruppe32
// @created 25.03.17 by Jonas
// @brief   All different states the menu system can be in
//
enum MenuState
{
  EXIT = 0,
  BASE = 100,

  NATION_BASE   = 1,
  NATION_SELECT = 2,
  NATION_EDIT   = 3,
  NATION_NEW    = 4,

  PARTICIPANT_BASE   = 5,
  PARTICIPANT_SELECT = 6,
  PARTICIPANT_EDIT   = 7,
  PARTICIPANT_NEW    = 8,

  SPORT_BASE   = 9,
  SPORT_SELECT = 10,
  SPORT_EDIT   = 11,
  SPORT_NEW    = 12,

  DICIPLINE_SELECT = 14,
  DICIPLINE_EDIT   = 15,
  DICIPLINE_NEW    = 16,
  DICIPLINE_DELETE = 17,

  LIST_BASE   = 18,
  LIST_ADD    = 19,
  LIST_RESULT = 20,
  LIST_DELETE = 21, 

  POINT_STATS = 22,
  MEDAL_STATS = 23,
};