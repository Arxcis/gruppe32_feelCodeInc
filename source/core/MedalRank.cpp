#include "MedalRank.h"


MedalRank::MedalRank(dat::Medals medals, dat::char3 nation)
:Rank(medals.castToInt(), nation)
,medals_(medals)
{}

auto MedalRank::getMedals() -> dat::Medals
{ return medals_; }
