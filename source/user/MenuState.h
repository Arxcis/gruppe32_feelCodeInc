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
  NATION_SELECT = 4,
  NATION_EDIT   = 5,
  NATION_NEW    = 6,

  PARTICIPANT_BASE   = 2,
  PARTICIPANT_SELECT = 7,
  PARTICIPANT_EDIT   = 8,
  PARTICIPANT_NEW    = 9,

  SPORT_BASE   = 3,
  SPORT_SELECT = 10,
  SPORT_EDIT   = 11,
  SPORT_NEW    = 12,

  EVENT_SELECT = 13,
  EVENT_EDIT   = 14,
  EVENT_NEW    = 15,
  EVENT_DELETE = 16,

  LIST_BASE   = 17,
  LIST_ADD    = 18,
  LIST_RESULT = 19,
  LIST_DELETE = 20, 

  };