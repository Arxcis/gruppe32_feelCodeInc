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
  allMenus_[START_MENU]    = new menu::StartMenu       ("Start",            { EXIT,  NATION_BASE, PART_BASE, SPORT_BASE, POINT_STATS, MEDAL_STATS}), 
  allMenus_[NATION_BASE]   = new menu::BaseMenu        ("Nasjon Base",      { START_MENU, NATION_NEW, NATION_SELECT});     
  allMenus_[PART_BASE]     = new menu::BaseMenu        ("Deltaker Base", { START_MENU, PART_NEW,   PART_SELECT});     
  allMenus_[SPORT_BASE]    = new menu::BaseMenu        ("Gren Base" ,      { START_MENU, SPORT_NEW,  SPORT_SELECT});    

  allMenus_[POINT_STATS]   = new menu::RankMenu        ("Points"     ,      { START_MENU} ); 
  allMenus_[MEDAL_STATS]   = new menu::RankMenu        ("Medals"     ,      { START_MENU} ); 

  allMenus_[NATION_SELECT] = new menu::NationMenu      ("Nasjon"     ,      { NATION_BASE , NATION_EDIT });
  allMenus_[PART_SELECT]   = new menu::ParticipantMenu ("Deltaker",      { PART_BASE   , PART_EDIT   });
  allMenus_[SPORT_SELECT]  = new menu::SportMenu       ("Gren"      ,      { SPORT_BASE  , SPORT_EDIT, DICI_NEW, DICI_SELECT });

  allMenus_[NATION_NEW]    = new menu::NewObject       ("Nasjon"     ,      { NATION_BASE , NATION_NEW });
  allMenus_[PART_NEW]      = new menu::NewObject       ("Deltaker",      { PART_BASE   , PART_NEW   });
  allMenus_[SPORT_NEW]     = new menu::NewObject       ("Gren"      ,      { SPORT_BASE  , SPORT_NEW  });

  allMenus_[NATION_EDIT]   = new menu::EditField       ("Nasjon"     ,      { NATION_SELECT});
  allMenus_[PART_EDIT]     = new menu::EditField       ("Deltaker",      { PART_SELECT});
  allMenus_[SPORT_EDIT]    = new menu::EditField       ("Gren"      ,      { SPORT_SELECT});

  //
  // Registring Advanced menus
  //
  allMenus_[DICI_SELECT]  = new menu::DiciplineMenu   ("Øvelse"  ,  { SPORT_SELECT, DICI_EDIT, SLIST_SELECT, RLIST_SELECT, DICI_DELETE});
  allMenus_[DICI_EDIT]    = new menu::EditField       ("Øvelse"  ,  { DICI_SELECT });
  allMenus_[DICI_NEW]     = new menu::NewDicipline    ("Øvelse"  ,  { SPORT_SELECT});

  allMenus_[SLIST_SELECT] = new menu::StartList       ("Starts"     ,  { DICI_SELECT, SLIST_DELETE });
  allMenus_[RLIST_SELECT] = new menu::ResultList      ("Results"    ,  { DICI_SELECT, RLIST_DELETE });
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

  allMenus_[START_MENU]->view(currentMap);

  while (running) 
  {
    if (!silentCommand) 
    {
      // 1. Read input
      input = stream::readInt("0-" + std::to_string(currentMap.size()-1) + "\n");

      // 2. Make sure input is within bounds.
      clampedInput = clamp(input, (int)currentMap.size()-1);

      // 3. Use input to find next menu
      selectedMenu = currentMap[clampedInput].first;
      selectedID   = currentMap[clampedInput].second;

      if (selectedID.find("_") != std::string::npos) // @hack
        { selectedDiciplineID = selectedID; }
                                                            std::cout << "Selected ID: " << selectedID << std::endl; // @debug
                                                            std::cout << "Dicipline ID: " << selectedDiciplineID << std::endl; // @debug
      // 4. Reset current map
      currentMap = {};

    }
    else 
      { silentCommand = false; }
    // 5. Display next menu
    displayMenu();
  }
  return 0;
}

void Console::displayMenu()
{ 
  bool shouldUpdate = false;

  switch(selectedMenu)
  {
    case EXIT: exit(0); 
      break;

    case START_MENU:       
      allMenus_[START_MENU]->view(currentMap); 
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
      selectedContainer = api_.getAll(POINT);
      allMenus_[POINT_STATS]->view(currentMap, selectedContainer);
      break;

    case MEDAL_STATS:  
      selectedContainer = api_.getAll(MEDAL);
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
      selectedObject = api_.get(NATION, selectedID);
      allMenus_[NATION_SELECT]->view(currentMap, selectedObject);
      break;

    case PART_SELECT:
      selectedObject = api_.get(PARTICIPANT, selectedID);
      allMenus_[PART_SELECT]->view(currentMap, selectedObject);
      break;

    case SPORT_SELECT:
      selectedObject = api_.get(SPORT, selectedID);
      allMenus_[SPORT_SELECT]->view(currentMap, selectedObject);
      break;

    case DICI_SELECT:
      allMenus_[DICI_SELECT]->view(currentMap, selectedObject, selectedDiciplineID);  // @hack
      break;

//  ----------- NEW  -----------------
    //
    // @case *_NEW
    //  1. Create an empty object.
    //  2. Pass the empty object to the menu, so that the user can fill it up with data.
    //  3. Pass the object to the API.
    //
    case NATION_NEW:
      selectedObject = {{"Type", "Nation"}};
      allMenus_[NATION_NEW]->view(currentMap, selectedObject);
      break;

    case PART_NEW:
      selectedObject = {{"Type", "Participant"}};
      allMenus_[PART_NEW]->view(currentMap, selectedObject);
      break;

    case SPORT_NEW:
      selectedObject = {{"Type", "Sport"}};
      allMenus_[SPORT_NEW]->view(currentMap, selectedObject);
      break;

    case DICI_NEW:
      allMenus_[DICI_NEW]->view(currentMap, selectedObject, selectedID);
      api_.add(selectedObject);
      break;


//  ----------- EDIT  -----------------
    //
    // @case *_EDIT
    //  1. Give user the object which is beiing edited, an the key to the field to edit
    //  2. Tell the API to update the database, with the added information.
    // 
    case NATION_EDIT:
      allMenus_[NATION_EDIT]->view(currentMap, selectedObject, selectedID);
      api_.update(selectedObject); 
      break;

    case PART_EDIT:
      allMenus_[PART_EDIT]->view(currentMap, selectedObject, selectedID); 
      api_.update(selectedObject); 
      break;

    case SPORT_EDIT:
      allMenus_[SPORT_EDIT]->view(currentMap, selectedObject, selectedID);
      api_.update(selectedObject); 
      break;

    case DICI_EDIT:
      allMenus_[DICI_EDIT]->view(currentMap, selectedObject, selectedID);
      api_.update(selectedObject); 
      break;


//  ----------- DICIPLINE LIST  -----------------
    //
    // 1. Ask API for a specific list from a specific dicipline
    // 2. Check if list is empty. if so, menu should fill the list, and the API should update
    //    the list.
    // 3. Fill menu with list, or 
    // 4. Update API if user has made a list.
    //
    case SLIST_SELECT:
      selectedStarts = api_.getAll(STARTS, selectedID);
      
      allMenus_[SLIST_SELECT]->view(currentMap, selectedStarts, selectedID);
      api_.updateAll(STARTS, selectedStarts, selectedID);
      break;

    case RLIST_SELECT:
      selectedStarts  = api_.getAll(STARTS,  selectedID);
      selectedResults = api_.getAll(RESULTS, selectedID);

      allMenus_[RLIST_SELECT]->view(
        currentMap, 
        selectedObject,
        selectedStarts, 
        selectedResults, 
        selectedID);

      api_.updateAll(RESULTS, selectedResults, selectedID);
      break;

//  ----------- SILENT delete commands  -----------------

    // COMMANDS that happend without asking the user
    // 1. Set the silentCommand flag to true, such that command is executed without asking for user input.
    // 2. ASK API to perform a delete.
    // 3. Print debug info
    case SLIST_DELETE:
      silentCommand = true;
      api_.remove(STARTS, selectedID);
      std::cout << "Starts " + selectedID + " deleted...\n";  // @debug
      selectedMenu = DICI_SELECT;
      break;

    case RLIST_DELETE:
      silentCommand = true;
      api_.remove(RESULTS, selectedID);
      std::cout << "Reults " + selectedID + " deleted...\n";  // @debug
      selectedMenu = DICI_SELECT;
      break;

    case DICI_DELETE:
      silentCommand = true;
      api_.remove(DICIPLINE, selectedID);
      std::cout << "Dicipline " + selectedID + " deleted...\n";  // @debug
      selectedMenu = SPORT_SELECT;
      selectedID = selectedID.substr(0, (selectedID.find("_")));   // picking out the ID of the sport from the sport_dicipline ID
      break;


    default:
      std::cout << "Not implemented yet....\n";
  }
}
