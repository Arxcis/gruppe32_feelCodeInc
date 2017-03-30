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
  int nextMenuIndex = 0;
  int selectedNumber = 0;

  currentMenu_ = allMenus_[0];


  return 0;
}
