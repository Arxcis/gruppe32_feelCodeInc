#include "Console.h"

bool Console::instantiated_ = false;    // @static

Console::Console()
{ 
  assert(!instantiated_);
  instantiated_ = true;


  //
  // Registring basic menus
  //
  allMenus_[ERROR]         = new menu::Error           ("Wrong input...\n", {});
  allMenus_[START]         = new menu::StartMenu       ("Start",            { EXIT,  NATION_BASE, PART_BASE, SPORT_BASE, POINT_STATS, MEDAL_STATS}), 
  allMenus_[NATION_BASE]   = new menu::BaseMenu        ("Nation Base",      { START, NATION_NEW, NATION_SELECT});     
  allMenus_[PART_BASE]     = new menu::BaseMenu        ("Participant Base", { START, PART_NEW,   PART_SELECT});     
  allMenus_[SPORT_BASE]    = new menu::BaseMenu        ("Sport Base" ,      { START, SPORT_NEW,  SPORT_SELECT});     
  allMenus_[POINT_STATS]   = new menu::RankMenu        ("Points"     ,      { START} ); 
  allMenus_[MEDAL_STATS]   = new menu::RankMenu        ("Medals"     ,      { START} ); 
  allMenus_[NATION_SELECT] = new menu::NationMenu      ("Nation"     ,    { NATION_BASE , NATION_EDIT });
  allMenus_[PART_SELECT]   = new menu::ParticipantMenu ("Participant",    { PART_BASE   , PART_EDIT   });
  allMenus_[SPORT_SELECT]  = new menu::SportMenu       ("Sport"      ,    { SPORT_BASE  , SPORT_EDIT, DICI_SELECT });
  allMenus_[NATION_NEW]    = new menu::NewObject       ("Nation"     ,    { NATION_BASE , NATION_NEW });
  allMenus_[PART_NEW]      = new menu::NewObject       ("Participant",    { PART_BASE   , PART_NEW   });
  allMenus_[SPORT_NEW]     = new menu::NewObject       ("Sport"      ,    { SPORT_BASE  , SPORT_NEW  });
  allMenus_[NATION_EDIT]   = new menu::EditField       ("Nation"     ,    { NATION_SELECT});
  allMenus_[PART_EDIT]     = new menu::EditField       ("Participant",    { PART_SELECT});
  allMenus_[SPORT_EDIT]    = new menu::EditField       ("Sport"      ,    { SPORT_SELECT});

  //
  // Registring Advanced menus
  //
  allMenus_[DICI_SELECT] = new menu::EditField       ("Sport"      ,    { SPORT_SELECT});
}

Console::~Console() 
{ 
  instantiated_ = false; 

  for (auto i=0; i < maxMenus_; i++)
    { delete allMenus_[i]; }
}

//
// @function clamp - makes sure that input is kept within range.
//    @note - Right now input is set to 0 if it is out of range.
//
int Console::clamp(const int input, const int max) const
{ 
  const auto min = 0;

  if(input > max)
    { return min; }
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
  auto running      = true;
  auto clampedInput = 0;

  allMenus_[START]->view(currentMap);

  while (running) 
  {
    // 1. Read input
    input = stream::readInt("0-" + std::to_string(currentMap.size()-1));

    // 2. Make sure input is within bounds.
    clampedInput = clamp(input, (int)currentMap.size()-1);

    // 3. Use input to find next menu
    selectedMenu = currentMap[clampedInput].first;
    selectedID   = currentMap[clampedInput].second;
    // 4. Reset current map
    currentMap = {};

    // 5. Display next menu
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

//  ----------- BASES  -----------------

    //
    // @case *_BASE
    //  1. Fetching a container containing objects of a specific kind from the API
    //  2. Feed the objects into the selected menu, so they can be listed, and key-bound.
    //  
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

//  ----------- STATS  -----------------

    //
    // @case *_STATS
    //  1. Fetch a container of stat-objects, Medal or Point, from the API
    //  2. Feed container to the menu, for dynamic display
    //  
    case POINT_STATS: 
      selectedContainer = api_.getPoints();
      allMenus_[POINT_STATS]->view(currentMap, selectedContainer);
      break;

    case MEDAL_STATS:  
      selectedContainer = api_.getMedals();
      allMenus_[MEDAL_STATS]->view(currentMap, selectedContainer);
      break;

//  ----------- SELECT  -----------------

    //
    // @case *_SELECT
    //  1. Get a specific Object from the API, using the primary key(ID) as a parameter.
    //  2. We get the primary key by feeding the user-input to the transition-map.
    //  3. Feeding the object to the menu, where keys are mapped to edit-able fields.
    // 
    case NATION_SELECT:
      selectedObject = api_.get(NATION, currentMap[input].second);
      allMenus_[NATION_SELECT]->view(currentMap, selectedObject);
      break;

    case PART_SELECT:
      selectedObject = api_.get(PARTICIPANT, currentMap[input].second);
      allMenus_[PART_SELECT]->view(currentMap, selectedObject);
      break;

    case SPORT_SELECT:
      selectedObject = api_.get(SPORT, currentMap[input].second);
      allMenus_[SPORT_SELECT]->view(currentMap, selectedObject);
      break;

//  ----------- NEW  -----------------
    //
    // @case *_NEW
    //  1. Create an empty object.
    //  2. Pass the empty object to the menu, so that the user can fill it up with data.
    //  3. Pass the object to the API.
    //
    case NATION_NEW:
      selectedObject = {};
      allMenus_[NATION_NEW]->view(currentMap, selectedObject);
      api_.add(selectedObject);
      break;

    case PART_NEW:
      selectedObject = {};
      allMenus_[PART_NEW]->view(currentMap, selectedObject);
      api_.add(selectedObject);
      break;

    case SPORT_NEW:
      selectedObject = {};
      allMenus_[SPORT_NEW]->view(currentMap, selectedObject);
      api_.add(selectedObject);
      break;

//  ----------- EDIT  -----------------
    //
    // @case *_EDIT
    //  1. Match the user-selected key(ID) with a field in the selected object.
    //  2. Give the user access to edit that specific field.
    //  3. Tell the API to update the database, with the added information.
    // 
    case NATION_EDIT:
      for(auto& field: selectedObject)
      {
        if (field.first == selectedID) 
          { allMenus_[NATION_EDIT]->view(currentMap, field); }
      }
      selectedObject = api_.update(NATION, selectedObject);  //@error - undefined symbol API::update(blablabla)
      break;


    case PART_EDIT:
      for(auto& field: selectedObject)
      {
        if (field.first == selectedID) 
          { allMenus_[PART_EDIT]->view(currentMap, field); }
      }
      selectedObject = api_.update(PARTICIPANT, selectedObject);  //@error - undefined symbol API::update(blablabla)
      break;


    case SPORT_EDIT:
      for(auto& field: selectedObject)
      {
        if (field.first == selectedID) 
          { allMenus_[SPORT_EDIT]->view(currentMap, field); }
      }
      selectedObject = api_.update(SPORT, selectedObject);  //@error - undefined symbol API::update(blablabla)
      break;


    default:
      std::cout << "Not implemented yet....\n";
  }
}
