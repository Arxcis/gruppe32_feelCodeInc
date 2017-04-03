#pragma once

// @file    core/Sport.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Sport is stored within.
//

#include <string>
#include "ListTool2B.h"
#include "Dicipline.h"
#include <vector>

class Sport : TextElement
{
public:
  enum ScoreType { POINT, MEDAL };
  static const int maxDiciplines = 20;

private:
  std::string name_;
  ScoreType scoreType_;                     // Can be 
  std::vector<Dicipline> diciplines_;    // A sport can have maximum 20 diciplines each.

public:
  Sport(std::string name, ScoreType type)
  :name_(name),
  scoreType_(type)
  {}

  bool addDicipline(Dicipline dici);
  auto getDiciplines() -> const std::vector<Dicipline>;
  bool removeDicipline(std::string id);

  auto getName() -> std::string;
  auto getScoreType() -> ScoreType;
};
