#include "Console.h"

bool Console::instantiated_ = false;

Console::Console()
{
  assert(!instantiated_);
  instantiated_ = true;
}

Console::~Console() 
{
  instantiated_ = false; 
}

//
// @funciton run()
//  @brief the entry-point function for presenting the menu system
//   to the user.
//
int Console::run()
{
  MenuState newCommand = BASE;     // The most recent command from the user

  while(newCommand) 
  { 
    newCommand = menu::begin();
    switch(newCommand)
    {
      case EXIT:
        std::cout << "Exiting program......\n";
        break;
      default:
        std::cout << "Command not supported...\n";

        break;
    }
  }

  std::cout << "Exiting program......\n";

  return 0;
}