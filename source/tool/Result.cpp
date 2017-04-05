#include "Result.h"

int Result::getID()
  { return ID_; }

int Result::getValue()
{ return value_; }


void Result::display()
  { printf("ID: %d    Points: %d\n",ID_, value_); }
