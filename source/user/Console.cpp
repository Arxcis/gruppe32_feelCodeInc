#include "Console.h"

bool Console::instantiated_ = false;


Console::Console()
{ 
  assert(!instantiated_);
  instantiated_ = true;


  //
  // Registring basic menus
  //
  allMenus_[START]         = new menu::Start     ("Start",            { EXIT,  NATION_BASE, PART_BASE, SPORT_BASE, POINT_STATS, MEDAL_STATS}), 
  allMenus_[NATION_BASE]   = new menu::Base      ("Nation Base",      { START, NATION_NEW, NATION_SELECT});     
  allMenus_[PART_BASE]     = new menu::Base      ("Participant Base", { START, PART_NEW,   PART_SELECT});     
  allMenus_[SPORT_BASE]    = new menu::Base      ("Sport Base" ,      { START, SPORT_NEW,  SPORT_SELECT});     
  allMenus_[POINT_STATS]   = new menu::Stats     ("Points"     ,      { START} ); 
  allMenus_[MEDAL_STATS]   = new menu::Stats     ("Medals"     ,      { START} ); 
  allMenus_[NATION_SELECT] = new menu::Object    ("Nation"     ,      { NATION_BASE, NATION_EDIT});
  allMenus_[PART_SELECT]   = new menu::Object    ("Participant",      { PART_BASE,   PART_EDIT});
  allMenus_[SPORT_SELECT]  = new menu::Object    ("Sport"      ,      { SPORT_BASE,  SPORT_EDIT});
  allMenus_[NATION_NEW]    = new menu::NewObject ("Nation"     ,      { NATION_BASE , NATION_NEW });
  allMenus_[PART_NEW]      = new menu::NewObject ("Participant",      { PART_BASE   , PART_NEW   });
  allMenus_[SPORT_NEW]     = new menu::NewObject ("Sport"      ,      { SPORT_BASE  , SPORT_NEW  });
  allMenus_[NATION_EDIT]   = new menu::EditField ("Nation"     ,      { NATION_SELECT});
  allMenus_[PART_EDIT]     = new menu::EditField ("Participant",      { PART_SELECT});
  allMenus_[SPORT_EDIT]    = new menu::EditField ("Sport"      ,      { SPORT_SELECT});

  //
  // Registring Advanced menus
  //
}


Console::~Console() 
{ 
  instantiated_ = false; 

  for (int i=0; i < maxMenus_; i++)
    { delete allMenus_[i]; }
}

//
// @function clamp - makes sure that input is kept within range.
//
int Console::clamp(const int input, const int max) const
{ 
  const int min = 0;

  if(input > max)
    { return max; }
  else if (input < min)
    { return min; }
  else 
    { return input; }
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

  allMenus_[START]->view(currentMap);

  while (running) 
  {
    std::cout << "Number of options: " << currentMap.size() << "\n"; // @debug
    input = stream::readInt("0-N");

    input = clamp(input, currentMap.size());
    selectedMenu = currentMap[input].first;

    currentMap = {};
    displayMenu();
  }

  return 0;
}

void Console::displayMenu()
{ 

  switch(selectedMenu)
  {
    case EXIT: exit(0); 
      break;

    case START:       
      allMenus_[START]->view(currentMap); 
      break;

    case NATION_BASE: 
      selectedContainer = api_.getAll(NATION);
      allMenus_[NATION_BASE]->view(currentMap, selectedContainer);
      break;

    case PART_BASE:  
      selectedContainer = api_.getAll(PARTICIPANT); 
      allMenus_[PART_BASE]->view(currentMap, selectedContainer); 
      break;

    case SPORT_BASE:   
      selectedContainer = api_.getAll(SPORT); 
      allMenus_[SPORT_BASE]->view(currentMap, selectedContainer);
      break;

    case POINT_STATS: 
      selectedObject = api_.getPoints();
      allMenus_[POINT_STATS]->view(currentMap, selectedObject);
      break;

    case MEDAL_STATS:  
      selectedObject = api_.getMedals();
      allMenus_[MEDAL_STATS]->view(currentMap, selectedObject);
      break;

    default:
      std::cout << "Not supported...\n";
  }
}
