#include "Sport.h"

auto Sport::getName() -> std::string
{
  return name_;
}
auto Sport::getScoreType() -> Sport::ScoreType
{
  return scoreType_;
}

bool Sport::addDicipline(Dicipline dici)
{
  if (lastDicipline < maxDiciplines)
  {
    diciplines_[++lastDicipline] = dici;
    return true;
  }
  else 
    { return false; }
}

auto Sport::getDiciplines() -> Dicipline*
{
  return diciplines_;
}

/*
ScoreType Sport::getScoreType()
{
	return scoreType_;
}*/
