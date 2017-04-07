#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  ////////////////////////////////////////////////////////////////
  //
  //  @base class menu::ConsoleMenu
  //

  //
  // @Constructor
  //
  ConsoleMenu::ConsoleMenu(const std::string& type, const std::vector<int>& nextState)
  :type_(type)
  ,nextState_(nextState)
  {}

  // 
  // @class functions - Visual helper functions
  //

  inline void 
  ConsoleMenu::footer() const
  {
    std::cout << "\n";
    divider(divsizeBig, true);
  }

  inline void 
  ConsoleMenu::divider(const int length, bool tight) const
  {
    if (!tight)
      { std::cout << "  "; }

    for (int i = 0; i < length; i++)
      { std::cout << "-"; }

    std::cout << "\n";
  }

  void 
  ConsoleMenu::newPage() const
  {
    for(int i=0; i < newpageLines; i++)
    {
      std::cout << "\n";
    }
  }

  void 
  ConsoleMenu::header(const std::string name) const
  {   
    std::cout << "\n";
    divider(divsizeBig, true); 
    std::cout << "|    " << name << "               \n";
    divider(divsizeBig, true); 
    std::cout << "\n";
  }

  void 
  ConsoleMenu::newLine()
    { std::cout << "\n"; }

  //
  // @class functions - Menu options functions
  //  @brief functions which lists a single option in the menu.
  //    Can be of type:
  //      - Illegal - Not available to use by the user
  //      - Static  - Points to the same next menu always
  //      - Dynamic - Can point to different menus each time program is run
  //                    depending on what dta is in the system
  //

  inline void 
  ConsoleMenu::illegalOption(
    const std::string& text) const
  {  
    std::cout << std::setw(colsize) << " --- " << text << " \n";  // 1. Write option to screen
    
  }

  inline void 
  ConsoleMenu::staticOption(
    dat::TransitionMap& map,
    const int select, 
    const int nextMenu,
    const std::string& text) const
  {
    std::cout << std::setw(colsize) 
              << (std::to_string(select) + "-> ") 
              << std::left
              << std::setw(colsizeMid)
              << text  << "\n"
              << std::right;

    map[select] = { nextMenu, "" };                       // 2. Bind option to next menu
  }

  inline void 
  ConsoleMenu::dynamicOption(
    dat::TransitionMap& map,
    const int select, 
    const int nextMenu,
    const std::string& id,
    const std::string& text) const
  {
    std::cout << std::setw(colsize) 
              << (std::to_string(select) + "-> ") 
              << std::left
              << std::setw(colsizeMid) 
              << text << " \n" 
              << std::right;  

    map[select] = { nextMenu, id };                     // 2. Bind option AND object to next menu
  }

  inline void 
  ConsoleMenu::dynamicOption(
    dat::TransitionMap& map,
    const int select,
    const int nextMenu,
    const dat::Field& field) const
  {
    std::cout  << std::setw(colsize) 
               << (std::to_string(select) + "-> ")
               << std::left
               << std::setw(colsize) 
               << (field.first + ": ")  
               << std::setw(colsizeMid) 
               << field.second << "\n"
               << std::right << "";

    map[select] = { nextMenu, field.first };
  }

  inline void 
  ConsoleMenu::dynamicOption(
    dat::TransitionMap& map,
    const int select,
    const int nextMenu,
    const std::vector<dat::Field> fields) const
  {
    std::cout  << std::setw(colsize) 
               << (std::to_string(select) + "-> ")
               << std::left
               << std::setw(colsizeMini); 

    for (int i=1; i < fields.size(); i++)
    { 
      std::cout << (fields[i].first + ": ")  
                << std::setw(colsize) 
                << fields[i].second;
    }
    std::cout << std::right << "\n";
    map[select] = { nextMenu, fields[0].second };
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Start
  //
  StartMenu::StartMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void StartMenu::view(dat::TransitionMap& map)
  {
    newPage();

    // 1. Header of start menu
    header(type_);

    // 2. Start menu options - all are static.
    staticOption(map, 1, nextState_[1], "Nasjoner    ");
    staticOption(map, 2, nextState_[2], "Deltaker    ");
    staticOption(map, 3, nextState_[3], "Grener      ");
    staticOption(map, 4, nextState_[4], "Poeng       ");
    staticOption(map, 5, nextState_[5], "Medaljer    ");

    // 3. Exit program
    divider(divsizeMid);
    staticOption(map, 0, nextState_[0], "Avslutt     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Base
  //
  BaseMenu::BaseMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void BaseMenu::view(dat::TransitionMap& map, dat::Container& container)
  { 
    newPage();

    // 1. Header of base menu - Nation, Dicipline or sport
    header(type_);

    // 2. List of all objects in the given Database
    size_t it = 1;
    for (const auto& object: container)
    { 
      dynamicOption(map, it++, nextState_[2], 
          {  
            object[1], 
            { "", object[1].second }, 
            object[2], 
            object[3],
          }); 
    }

    // 3. Utility options
    newLine();
    divider(divsizeMid);
    staticOption(map, it, nextState_[1], "Ny " + type_.substr(0, type_.find(" ")));
    staticOption(map, 0, nextState_[0], "Back      ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Stats
  //
  RankMenu::RankMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void RankMenu::view(dat::TransitionMap& map, dat::Container& ranks)
  {
    newPage();

    // 1. Header of RankMenu - Stats or Points
    header(type_ + " stats");

    // 2. List of all ranks, should be sorted highest first.
    for(const auto& rank: ranks)
    { illegalOption(rank[1].first + ": " + rank[1].second + "\t" + rank[2].first + ": "+  rank[2].second + "\t" + rank[3].first + ": " +  rank[3].second + "\t"); }
    
    // 3. Utility options
    divider(divsizeMid);
    staticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NationMenu
  //
  NationMenu::NationMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void NationMenu::view(dat::TransitionMap& map, dat::Object& nation) 
  {
    newPage();

    // 1. Header of nation menu
    header(type_);
    illegalOption(nation[1].first + ": " + nation[1].second);


    // 2. All fields of the nation
    dynamicOption(map, 1, nextState_[1], nation[2]);
    //illegalOption(nation[3].first + ": " + nation[3].second);
    staticOption(map, 2, nextState_[2], nation[3].first + ": " + nation[3].second);
    dynamicOption(map, 3, nextState_[1], nation[4]);
    dynamicOption(map, 4, nextState_[1], nation[5]);
    dynamicOption(map, 5, nextState_[1], nation[6]);
    
    // 3. Utility options
    divider(divsizeMid);
    staticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ParticipantMenu
  //
  ParticipantMenu::ParticipantMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void ParticipantMenu::view(dat::TransitionMap& map, dat::Object& participant) 
  {
    newPage();

    // 1. Dicipline header + participant ID
    header(type_);
    illegalOption(participant[1].first + ": " + participant[1].second);
    newLine();

    // 2. Fields to edit in participant
    dynamicOption(map, 1, nextState_[1], participant[2]);
    dynamicOption(map, 2, nextState_[1], participant[3]);
    dynamicOption(map, 3, nextState_[1], participant[4]);
    dynamicOption(map, 4, nextState_[1], participant[5]); // @robustness check if country exists

    // 3. Utility options
    newLine();
    divider(divsizeMid);
    staticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::SportMenu
  //
  SportMenu::SportMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void SportMenu::view(dat::TransitionMap& map, dat::Object& sport) 
  {
    newPage();

    // 1. Sport menu header
    header(type_);

    // 2. Binding options editing sport fields.
    dynamicOption(map, 1, nextState_[1], sport[1]);
    illegalOption(sport[2].first + ": " + sport[2].second);

    // 3. Binding opitons which selects a dicipline
    newLine();
    illegalOption("Øvelser" + (": " + sport[3].second));

    size_t optionIt = 2;
    for (size_t i = 4; i < (4 + (std::stoi(sport[3].second)*3)); i+=3 )
    { dynamicOption(map, optionIt++, nextState_[3], sport[i].second, sport[i].second); }

    // 4. Utility options
    newLine();
    divider(divsizeMid);
    newLine();
    dynamicOption(map, optionIt, nextState_[2], sport[1].second, "Ny Øvelse");
    staticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::DiciplineMenu
  //
  DiciplineMenu::DiciplineMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  //
  // @funciton menu::DiciplineMenu::view
  //  @param object - The selected sport, which also contains meta-information about selected dicipline
  //
  void DiciplineMenu::view(dat::TransitionMap& map, dat::Object& sport, const std::string& diciplineID) 
  {
    newPage();

    // 1. Header of dicipline menu
    header(type_);

    // @logic + advances @iterator in the sport sport until we get to the desired dicipline.
    int it = 0;
    while (sport[it].second != diciplineID)
    { it++; }

    // 2. Dicipline menu options - { name, time, date, start, results }
    illegalOption(sport[it].second);
    divider(divsizeMid);
    dynamicOption(map, 1, nextState_[1], sport[(it+1)]);
    dynamicOption(map, 2, nextState_[1], sport[(it+2)]);
    dynamicOption(map, 3, nextState_[2], sport[it].second, "Start list");
    dynamicOption(map, 4, nextState_[3], sport[it].second, "Result List");

    std::string sportID = diciplineID.substr(0, (diciplineID.find("_")));  // @hack

    // 3. Utility options - { delete, back }
    divider(divsizeMid);
    dynamicOption(map, 5, nextState_[4], diciplineID, "Delete");
    dynamicOption(map, 0, nextState_[0], sportID,     "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject
  //
  NewObject::NewObject(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void NewObject::view(dat::TransitionMap& map)
  {
   newPage();

   // 1. Header new object menu + cancel option
   header(type_ + " ny");
   newLine();
   illegalOption("Avbryt == 0");
   newLine();

   // 2. Form a new object
   form::object(type_);

   // 3. Silent return to TYPE_BASE
   map[0] = { nextState_[0], "" };
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewDicipline
  //
  NewDicipline::NewDicipline(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void NewDicipline::view(dat::TransitionMap& map, dat::Object& sport, const std::string& sportID)
  { 
    newPage();

    // 1. New dicipline header
    header(type_ + " append");

    // 2. Form a new dicipline and append to existing sport object.
    form::appendDicipline(sport);

    // 3. Silent return to SPORT_SELECT
    map[0] = { nextState_[0], sportID };
  }
  
  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField 
  //
  EditField::EditField(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void EditField::view(dat::TransitionMap& map, dat::Object& object, const std::string& fieldKey) 
  { 
    const std::string& objectID = object[1].second;
    newPage();

    // 1. Edit field header
    header(type_ + " edit");

    // 2. Form selected field
    form::singleField(object, fieldKey);

    // 3. Silent return
    map[0] = { nextState_[0], objectID };
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::StartLIst
  //
  StartList::StartList(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void StartList::view(
    dat::TransitionMap&   map, 
    const dat::Object&    sport, 
    const dat::Container& starts, 
    const std::string&    diciplineID)
  {
    newPage();
    
    // 1. Start list header
    header(type_);

    // 2. Form a new start list if start list is empty
    if (starts.empty())
    { form::startList(diciplineID, sport); } 

    // 3. List entire start list - Start list is immutable once made
    for (const auto& entry: starts)
    { illegalOption(entry[1].second + ": " + entry[2].second); }

    // 4. Utility options - { delete, back }
    dynamicOption(map, 1, nextState_[1], diciplineID, "Slett ");
    dynamicOption(map, 0, nextState_[0], diciplineID, "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ResultList
  //
  ResultList::ResultList(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void ResultList::view(
    dat::TransitionMap&   map,
    const dat::Object&    sport, 
    const dat::Container& starts, 
    const dat::Container& results, 
    const std::string&    diciplineID)
  {
    newPage();

    // 1. Header of result menu
    header(type_);

    if (!(starts.empty()))  
    {  
      std::cout << "SCORETYPE : " <<  sport[2].second << std::endl; // @debug
      divider(divsizeMid);

      // 2. If start menu is not empty, and result menu is empty, then fill result-list
      if(results.empty()) 
      { form::resultList(diciplineID, sport, starts); }

      // 3. List result-list - once results have been made, they are un-changeable
      for (int it=0; it < starts.size(); it++)
      { illegalOption( starts[it][1].second + " - " +  starts[it][2].second + " - " + results[it][2].second); }

      dynamicOption(map, 1, nextState_[1], diciplineID, "Delete results");
    }
    else
      { std::cout << "ERROR: You have to create a start-list first\n"; }

    // 4. Utility options
    dynamicOption(map, 0, nextState_[0], diciplineID, "Back      ");
    footer();
  }
}
