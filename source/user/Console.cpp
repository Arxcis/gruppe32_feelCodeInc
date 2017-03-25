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
  int retval=1;
  menuState = menu::begin();
  while(menuState) 
  { 
    switch(menuState)
    {
      case EXIT:
        std::cout << "Exiting program......\n";
        break;

      case BASE:
        menuState = menu::begin();
        break;

      case NATION_BASE:
        retval = menu::nationBase();
        if (!retval) 
          {  menuState = BASE;  }
        break;

      case PARTICIPANT_BASE:
        retval = menu::participantBase();
        if (!retval) 
          {  menuState = BASE;  }
        break;

      case SPORT_BASE:
        retval = menu::sportBase();
        if (!retval) 
          {  menuState = BASE;  }
        break;

      default:
        std::cout << "Command not supported...\n";
        menuState = BASE;
        break;  
    }
    
  }
  return 0;
}