#include "Dicipline.h"

auto Dicipline::GetName() -> std::string
{ return name_; }

auto Dicipline::GetTime() -> dat::Time
{ return time_; }

auto Dicipline::GetDate() -> dat::Date
{ return date_; }
