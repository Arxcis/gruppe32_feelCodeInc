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
  if (diciplines_.size() < maxDiciplines)
  { 
    diciplines_.push_back(dici);
    return true;
  }
  else 
    { return false; }
}

auto Sport::getDiciplines() -> const std::vector<Dicipline>
{
  return diciplines_;
}

bool removeDicipline(std::string id)
{
  
}

