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

  menuState = BASE;

  while(menuState)
  { 
    switch(menuState)
    {
      case EXIT:
        std::cout << "Exiting program......\n";
        break;

      case BASE:
        retval = menu::begin_();
        if (!retval)          {  menuState = EXIT;             }
        else if (retval == 1) {  menuState = NATION_BASE;      } 
        else if (retval == 2) {  menuState = PARTICIPANT_BASE; } 
        else if (retval == 3) {  menuState = SPORT_BASE;       }
        else if (retval == 4) {  menuState = POINT_STATS;      }
        else if (retval == 5) {  menuState = MEDAL_STATS;      }  
        else                  {  menuState = BASE;             }

        break;


      /////////////////////////////////////////////////////////////////////////
      //
      // Nation cases
      //
      case NATION_BASE:
        retval = menu::nationBase_();
        if (!retval)          {  menuState = BASE;           }
        else if (retval >= 2) {  menuState = NATION_SELECT;  } 
        else                  {  menuState = NATION_NEW;      }
        break;

      case NATION_SELECT:
        container = api_.get(NATION, retval);
        view::nation(container);
        retval = menu::nation_();

        if (!retval)          {  menuState = NATION_BASE;  }
        else if (retval >= 2) {  menuState = NATION_EDIT;  } 
        else                  {  menuState = NATION_NEW;   }
        break;

      case NATION_NEW: 
        container = form::nation(); 
        menuState = NATION_SELECT;
        break;

      case NATION_EDIT: 
        form::nationField(container, retval);
        menuState = NATION_SELECT;
        break;


      /////////////////////////////////////////////////////////////////////////
      //
      // Participant cases
      //
      case PARTICIPANT_BASE:
        retval = menu::participantBase_();
        if (!retval)          {  menuState = BASE;                }
        else if (retval >= 2) {  menuState = PARTICIPANT_SELECT;  } 
        else                  {  menuState = PARTICIPANT_NEW;     }
        break;

      case PARTICIPANT_SELECT:
        container = api_.get(PARTICIPANT, retval);
        view::participant(container);

        retval = menu::participant_();
        if (!retval)          {  menuState = PARTICIPANT_BASE;  }
        else if (retval >= 2) {  menuState = PARTICIPANT_EDIT;  } 
        else                  {  menuState = PARTICIPANT_NEW;   }
        break;

      case PARTICIPANT_NEW:  
        container = form::participant(); 
        menuState = PARTICIPANT_SELECT;
        break;

      case PARTICIPANT_EDIT: 
        form::participantField(container, retval);
        menuState = PARTICIPANT_SELECT;
        break;


      ///////////////////////////////////////////////////////////////////////////
      //
      // Sport cases
      //
      case SPORT_BASE:
        retval = menu::sportBase_();
        if (!retval)          {  menuState = BASE;          }
        else if (retval >= 2) {  menuState = SPORT_SELECT;  } 
        else                  {  menuState = SPORT_NEW;     }
        break;

      case SPORT_SELECT:
        container = api_.get(SPORT, retval);
        view::sport( container );

        retval = menu::sport_();
        if (!retval)                        {  menuState = SPORT_BASE;   }
        else if(retval >= 2 && retval <= 3) {  menuState = SPORT_EDIT;        } 
        else if (retval >= 4)               {  menuState = DICIPLINE_SELECT;  } 
        else                                {  menuState = SPORT_NEW;         }
        break;

      case SPORT_NEW:         
        container = form::sport(); 
        menuState = SPORT_SELECT;
        break;
        
      case SPORT_EDIT:
        form::sportField(container, retval);
        menuState = SPORT_SELECT; 
        break;


      /////////////////////////////////////////////////////////////////////////
      //
      // Dicipline cases
      //
      case DICIPLINE_SELECT : 
        container = api_.get(DICIPLINE, retval);
        view::dicipline( container );
        
        retval = menu::dicipline_();
        if (!retval)                         {  menuState = SPORT_SELECT;     }
        else if (retval == 1)                {  menuState = DICIPLINE_NEW;    } 
        else if (retval >= 2 && retval <= 4) {  menuState = DICIPLINE_EDIT;   } 
        else if (retval == 5)                {  menuState = LIST_BASE;        } 
        else                                 {  menuState = DICIPLINE_SELECT; }
        break;

      case DICIPLINE_EDIT: 
        form::diciplineField(container, retval);
        menuState = DICIPLINE_SELECT;
        break;

      case DICIPLINE_NEW:
        container = form::dicipline();
        menuState = DICIPLINE_SELECT;
        break;

      case DICIPLINE_DELETE : 
        retval = menu::deleteDicipline_();
        if(!retval)          {   menuState = DICIPLINE_SELECT;  }
        else if(retval == 1) {   menuState = SPORT_SELECT;      }
        else                 {   menuState = DICIPLINE_SELECT;  }
        break;


      /////////////////////////////////////////////////////////////////////////
      //
      // List cases
      //
      case LIST_BASE  : 
        retval = menu::listBase_();
        if(!retval)          {   menuState = DICIPLINE_SELECT;   }
        else if(retval == 1) {   menuState = LIST_ADD;           }
        else if(retval == 2) {   menuState = LIST_RESULT;        }
        else if(retval == 3) {   menuState = LIST_DELETE;        }
        else                 {   menuState = LIST_BASE;          }
        break;

      case LIST_ADD: 
        form::listAdd();
        menuState = LIST_BASE;
        break;
      case LIST_RESULT:
        form::listResult();
        menuState = LIST_BASE;
        break;

      case LIST_DELETE: 
        retval = menu::deleteList_();
        if(!retval)          {   menuState = LIST_BASE;          }
        else if(retval == 1) {   menuState = DICIPLINE_SELECT;   }
        else if(retval == 2) {   menuState = LIST_BASE;          }
        else                 {   menuState = LIST_BASE;          }
        break;



      /////////////////////////////////////////////////////////////////////////
      //
      // Stats cases
      //
      case POINT_STATS: 
        menu::pointStats_();
        menuState = BASE;
        break;
      case MEDAL_STATS:
        menu::medalStats_();
        menuState = BASE;
        break;

      default:
        std::cout << "Command not supported...\n";
        menuState = BASE;
        break;  
    }
    
  }
  return 0;
}
