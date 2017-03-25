#include "Console.h"

bool FileSystem::instantiated_ = false;

Console::Console()
{
  assert(!instantiated_);
  instantiated_ = true;
}

Console::~Console() 
{
  instantiated_ = false; 
}