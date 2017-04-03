#include "Sport.h"

auto Sport::getName() -> std::string
{
  return name_;
}
auto Sport::getScoreType() -> std::string
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

bool Sport::removeDicipline(const std::string& id)
{
  int i = 0;
  for (auto it = diciplines_.begin(); it < diciplines_.end(); i++, it++)
  {
    if (diciplines_[i].name == id) 
    { 
      diciplines_.erase(it); 
      return true;
    }
  }
  return false;
}

