#include "Console.h"

bool Console::instantiated_ = false;


Console::Console()
{ 
  api_=API();
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
  std::vector<std::string>* container;
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



      //
      // Nation cases
      //
      case NATION_BASE:
        retval = menu::nationBase();
        if (!retval)          {  menuState = BASE;           }
        else if (retval >= 2) {  menuState = NATION_SELECT;  } 
        else                  {  menuState = SPORT_NEW;      }
        break;

      case NATION_SELECT:
        container = api_.get(NATION, retval);
        view::nation(container);
        retval = menu::nation();

        if (!retval)          {  menuState = NATION_BASE;  }
        else if (retval >= 2) {  menuState = NATION_EDIT;  } 
        else                  {  menuState = NATION_NEW; }
        break;

      case NATION_NEW:  menuState = BASE;break;
      case NATION_EDIT: menuState = BASE;break;



      //
      // Participant cases
      //
      case PARTICIPANT_BASE:
        retval = menu::participantBase();
        if (!retval)          {  menuState = BASE;  }
        else if (retval >= 2) {  menuState = PARTICIPANT_SELECT;  } 
        else                  {  menuState = PARTICIPANT_NEW; }
        break;

      case PARTICIPANT_SELECT:
        container = api_.get(PARTICIPANT, retval);
        view::participant(container);

        retval = menu::participant();
        if (!retval)          {  menuState = PARTICIPANT_BASE;  }
        else if (retval >= 2) {  menuState = PARTICIPANT_EDIT;  } 
        else                  {  menuState = PARTICIPANT_NEW; }
        break;

      case PARTICIPANT_NEW:  menuState = BASE;break;
      case PARTICIPANT_EDIT: menuState = BASE;break;



      //
      // Sport cases
      //
      case SPORT_BASE:

        retval = menu::sportBase();
        if (!retval)          {  menuState = BASE;  }
        else if (retval >= 2) {  menuState = SPORT_SELECT;  } 
        else                  {  menuState = SPORT_NEW;     }
        break;

      case SPORT_SELECT:
        container = api_.get(SPORT, retval);
        view::sport( container );

        retval = menu::sport();
        if (!retval)          {  menuState = SPORT_BASE;  }
        else if (retval >= 2) {  menuState = SPORT_SELECT;  } 
        else                  {  menuState = SPORT_NEW; }
        break;

      case SPORT_NEW: menuState = BASE;break;
      case SPORT_EDIT: menuState = BASE;break;


      default:
        std::cout << "Command not supported...\n";
        menuState = BASE;
        break;  
    }
    
  }
  return 0;
}