#include "Console.h"

bool Console::instantiated_ = false;


Console::Console()
{ 
  assert(!instantiated_);
  instantiated_ = true;

  //
  // Registring basic menus
  //
  allMenus_[START]         = new menu::Begin           ({ EXIT, NATION_BASE, PART_BASE, SPORT_BASE, POINT_STATS, MEDAL_STATS }), 
  allMenus_[NATION_BASE]   = new menu::NationBase      ({ START, NATION_NEW, NATION_SELECT });     
  allMenus_[PART_BASE]     = new menu::ParticipantBase ({ START, PART_NEW,   PART_SELECT   });     
  allMenus_[SPORT_BASE]    = new menu::SportBase       ({ START, SPORT_NEW,  SPORT_SELECT  });     
  allMenus_[POINT_STATS]   = new menu::PointStats      ({ START, POINT_STATS          }); 
  allMenus_[MEDAL_STATS]   = new menu::MedalStats      ({ START, MEDAL_STATS          }); 
  allMenus_[NATION_SELECT] = new menu::Nation          ({ NATION_BASE, NATION_EDIT    });
  allMenus_[PART_SELECT]   = new menu::Participant     ({ PART_BASE,   PART_EDIT      });
  allMenus_[SPORT_SELECT]  = new menu::Sport           ({ SPORT_BASE,  SPORT_EDIT, DICI_SELECT     });
  allMenus_[NATION_NEW]    = new menu::NewObject       ({ NATION_BASE, NATION_NEW, NATION_SELECT   }, "Nation");
  allMenus_[PART_NEW]      = new menu::NewObject       ({ PART_BASE,   PART_NEW,   PART_SELECT     }, "Participant");
  allMenus_[SPORT_NEW]     = new menu::NewObject       ({ SPORT_BASE,  SPORT_NEW,  SPORT_SELECT    }, "Sport");
  allMenus_[NATION_EDIT]   = new menu::EditField       ({ NATION_SELECT  });
  allMenus_[PART_EDIT]     = new menu::EditField       ({ PART_SELECT    });
  allMenus_[SPORT_EDIT]    = new menu::EditField       ({ SPORT_SELECT   });

  //
  // Registring Advanced menus
  //
  allMenus_[DICI_SELECT]   = new menu::Dicipline       ({ SPORT_SELECT, DICI_DELETE, SLIST_SELECT, RLIST_SELECT, DICI_EDIT});
}


Console::~Console() 
{ 
  instantiated_ = false; 

  for (int i=0; i < maxMenus_; i++)
    { delete allMenus_[i]; }
}

//
// @funciton run()
//  @brief the entry-point function for presenting the menu system
//   to the user.
//
int Console::run()
{ 
  bool running = true;
  int nextMenuIndex = 0;
  int selectedNumber = 0;

  currentMenu_ = allMenus_[0];

  while(running)
  {
    currentMenu_->view();
    selectedNumber = stream::readInt("(0-N)");
    nextMenuIndex  = currentMenu_->getNextIndex(selectedNumber);

    if(nextMenuIndex == -1)
      { std::cout << "Exiting...\n";  running = false; }
    else
      { currentMenu_ = allMenus_[nextMenuIndex]; }
  }

  return 0;
}
