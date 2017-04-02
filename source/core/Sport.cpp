#include "Sport.h"

auto Sport::getName() -> std::string
{
	return name_;
}
Sport::ScoreType Sport::getScoreType()
{
  return scoreType_;
}
/*
ScoreType Sport::getScoreType()
{
	return scoreType_;
}

BetterArray Sport::getDiciplines()
{
	return events_;
}
*/
