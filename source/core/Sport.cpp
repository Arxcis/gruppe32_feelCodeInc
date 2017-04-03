#include "Sport.h"

auto Sport::getName() const -> std::string
{ return name_; }
auto Sport::getScoreType() const -> std::string
{ return scoreType_; }

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

auto Sport::getDiciplines() const -> std::vector<Dicipline>
{ return diciplines_; }

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

void Sport::display()

{ 
  printf("\n   =====   Sport   =====    "); 
  printf("\nSportName:\t%s\nScoreType:\t%s\n", name_.c_str(), scoreType_.c_str());

  for (auto& dici: diciplines_)
  {
    printf("Dicipline:\t%s   Time:\t%s\n", name_.c_str(), dat::packing::packTime(dici.time).c_str());
  }
}