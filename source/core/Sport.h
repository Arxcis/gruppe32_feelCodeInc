#pragma once

// @file    core/Sport.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Sport is stored within.
//

#include <string>
#include "ListTool2B.h"
#include "Dicipline.h"
#include "../tool/packer.h"
#include <vector>

class Sport : public TextElement
{
public:
  static const int maxDiciplines = 20;

private:
  std::string name_;
  std::string scoreType_;                     // Can be 
  std::vector<Dicipline> diciplines_;    // A sport can have maximum 20 diciplines each.

public:
  Sport(std::string name, std::string type)
  :TextElement(name.c_str())
  ,name_(name)
  ,scoreType_(type)
  {}

  bool addDicipline(Dicipline dici);
  auto getDiciplines() -> const std::vector<Dicipline>;
  bool removeDicipline(const std::string& id);

  auto getName() -> std::string;
  auto getScoreType() -> std::string;

  virtual void display() override;
};
