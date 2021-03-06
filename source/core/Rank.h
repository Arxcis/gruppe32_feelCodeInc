#pragma once

#include "ListTool2B.h"
#include <string>
#include "../tool/char3.h"
#include <cassert>

class Rank : public NumElement
{
protected:
  int value_;         //poeng/medaljer
  dat::char3 nation_;

public:
  Rank(int value, dat::char3 nation)
  :NumElement(value)
  ,value_(value)
  ,nation_(nation)
  {}
  
  int  getValue() const ;
  auto getNation() const -> dat::char3;

  virtual void display() override;

  void givePoint(size_t point);
  void givePointByPosition(size_t position);
  void takePoint(size_t point);
};
