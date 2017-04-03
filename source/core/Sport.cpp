#include "Sport.h"

auto Sport::getName() -> std::string
{
	return name_;
}
Sport::ScoreType Sport::getScoreType()
{
  return scoreType_;
}

bool Sport::addDicipline(Dicipline dici)
{
  if (diciplines_.size() < diciplines_.max_size())
  {
    diciplines_[diciplines_.size()] = dici;
    return true;
  }
  else 
    { return false; }
}
/*
ScoreType Sport::getScoreType()
{
	return scoreType_;
}*/
