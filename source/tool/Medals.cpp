

#include "Medals.h"
using namespace dat;

Medals::Medals(int gold_, int silver_, int bronze_)
:Measure(),
gold(gold_),
silver(silver_),
bronze(bronze_)
{}

Medals::~Medals(){}

void Medals::display(){}
int  Medals::castToInt()
{
  return ((gold*1001*1001) + (silver*1001) + bronze);
}
