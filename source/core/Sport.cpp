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
  if (diciplines_.size() < diciplines_.max_size())
  {
    diciplines_[diciplines_.size()] = dici;
    return true;
  }
  else 
    { return false; }
}

auto Sport::getDiciplines() -> const std::array<Dicipline, 20>
{
  return diciplines_;
}

/*
ScoreType Sport::getScoreType()
{
	return scoreType_;
}*/
