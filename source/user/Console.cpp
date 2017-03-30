#include "Console.h"

bool Console::instantiated_ = false;


Console::Console()
{ 
  assert(!instantiated_);
  instantiated_ = true;


  //
  // Registring basic menus
  //
  allMenus_[START]         = new menu::Start           ( ), 
  allMenus_[NATION_BASE]   = new menu::NationBase      ( );     
  allMenus_[PART_BASE]     = new menu::ParticipantBase ( );     
  allMenus_[SPORT_BASE]    = new menu::SportBase       ( );     
  allMenus_[POINT_STATS]   = new menu::PointStats      ( ); 
  allMenus_[MEDAL_STATS]   = new menu::MedalStats      ( ); 
  allMenus_[NATION_SELECT] = new menu::Nation          ( );
  allMenus_[PART_SELECT]   = new menu::Participant     ( );
  allMenus_[SPORT_SELECT]  = new menu::Sport           ( );
  allMenus_[NATION_NEW]    = new menu::NewObject       ( "Nation");
  allMenus_[PART_NEW]      = new menu::NewObject       ( "Participant");
  allMenus_[SPORT_NEW]     = new menu::NewObject       ( "Sport");
  allMenus_[NATION_EDIT]   = new menu::EditField       ( );
  allMenus_[PART_EDIT]     = new menu::EditField       ( );
  allMenus_[SPORT_EDIT]    = new menu::EditField       ( );

  //
  // Registring Advanced menus
  //
  allMenus_[DICI_SELECT]   = new menu::Dicipline       ();
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
  int input = 0;
  currentMenu_ = START;

  while (running) 
  {
    switchMenu();

    input = stream::readInt("0-N");
  }

  return 0;
}

void Console::switchMenu()
{ 

  switch(currentMenu_)
  {
    case EXIT: exit(0); 
      break;

    case START:       
      allMenus_[START]->view(map_); 
      break;

    case NATION_BASE: 
      containerRef = api_.getAll(NATION);
      allMenus_[NATION_BASE]->view(map_);
      break;

    case PART_BASE:  
      containerRef = api_.getAll(PARTICIPANT); 
      allMenus_[PART_BASE]->view(map_); 
      break;

    case SPORT_BASE:   
      containerRef = api_.getAll(SPORT); 
      allMenus_[SPORT_BASE]->view(map_);
      break;

    case POINT_STATS: 
      objectRef = api_.getPoints();
      allMenus_[POINT_STATS]->view(map_);
      break;

    case MEDAL_STATS:  
      objectRef = api_.getMedals();
      allMenus_[MEDAL_STATS]->view(map_);
      break;
  }
}