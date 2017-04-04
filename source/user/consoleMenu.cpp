#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  ////////////////////////////////////////////////////////////////
  //
  //  @base class menu::ConsoleMenu
  //
  ConsoleMenu::ConsoleMenu(const std::string& type, const std::vector<int>& nextState)
  :type_(type)
  ,nextState_(nextState)
  {}
  // 
  // @class functions - helper functions
  //

  inline void ConsoleMenu::footer() const
  {
    std::cout << "\n";
    divider(62, true);
  }

  inline void ConsoleMenu::divider(const int length, bool tight) const
  {
    if (!tight)
      { std::cout << "  "; }

    for (int i = 0; i < length; i++)
      { std::cout << "-"; }

    std::cout << "\n";
  }

  void ConsoleMenu::newPage() const
  {
    for(int i=0; i < 40; i++)
    {
      std::cout << "\n";
    }
  }

  void ConsoleMenu::header(const std::string name) const
  {   
    std::cout << "\n";
    divider(62, true); 
    std::cout << "|    " << name << "               \n";
    divider(62, true); 
    std::cout << "\n";
  }

  //
  // @class functions - bind menu option functions
  //

  inline void ConsoleMenu::printIllegalOption(
    const std::string& text) const
  {  
    std::cout << "  " << " --- " << text << " \n";  // 1. Write option to screen
    
  }


  inline void ConsoleMenu::bindStaticOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& text) const
  {  
    std::cout << "   " << select << "-> " << text << " \n";  // 1. Write option to screen
    map[select] = { menuPointer, "" };                       // 2. Bind option to next menu
  }

  inline void ConsoleMenu::bindDynamicOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& id,
    const std::string& text) const
  {
    
    std::cout << "   " << select << "-> " << text << "\n"; // 1. Write option to screen
    map[select] = { menuPointer, id };                     // 2. Bind option AND object to next menu
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
    header(type_);
    bindStaticOption(map, 1, nextState_[1], "Nasjoner     ");
    bindStaticOption(map, 2, nextState_[2], "Deltaker");
    bindStaticOption(map, 3, nextState_[3], "Grener      ");
    bindStaticOption(map, 4, nextState_[4], "Poeng      ");
    bindStaticOption(map, 5, nextState_[5], "Medaljer      ");
    divider(15);
    bindStaticOption(map, 0, nextState_[0], "Exit        ");
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
    header(type_);
    bindStaticOption(map, 1, nextState_[1], "New      ");
    divider(50);
    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, nextState_[2], object[1].second, 
                        (object[1].first + ":  " + object[1].second) + "\t " + (object[2].first + ":  " + object[2].second));
      it++;
    }
    divider(50);
    bindStaticOption(map, 0, nextState_[0], "Back      ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Stats
  //
  RankMenu::RankMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void RankMenu::view(dat::TransitionMap& map, dat::Container& container)
  {
    newPage();
    header(type_ + " stats");

    for(const auto& object: container)
      { printIllegalOption(object[1].first + ": " + object[1].second + "\t" + object[2].first + ": "+  object[2].second + "\t" + object[3].first + ": " +  object[3].second + "\t"); }
    divider(30);
    bindStaticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NationMenu
  //
  NationMenu::NationMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void NationMenu::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header(type_);

    printIllegalOption(object[1].first + ": " + object[1].second);
    divider(45);
    bindDynamicOption(map, 1, nextState_[1], object[2].first, (object[2].first + ": " + object[2].second));
    printIllegalOption(object[3].first + ": " + object[3].second);
    bindDynamicOption(map, 2, nextState_[1], object[4].first, (object[4].first + ": " + object[4].second));
    bindDynamicOption(map, 3, nextState_[1], object[5].first, (object[5].first + ": " + object[5].second));
    bindDynamicOption(map, 4, nextState_[1], object[6].first, (object[6].first + ": " + object[6].second));
    
    divider(45);
    bindStaticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ParticipantMenu
  //
  ParticipantMenu::ParticipantMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void ParticipantMenu::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header(type_);

    printIllegalOption(object[1].first + ": " + object[1].second);
    divider(40);
    bindDynamicOption(map, 1, nextState_[1], object[2].first, (object[2].first + ": " + object[2].second));
    bindDynamicOption(map, 2, nextState_[1], object[3].first, (object[3].first + ": " + object[3].second));
    bindDynamicOption(map, 3, nextState_[1], object[4].first, (object[4].first + ": " + object[4].second));
    bindDynamicOption(map, 4, nextState_[1], object[5].first, (object[5].first + ": " + object[5].second)); // @robustness check if country exists

    divider(40);
    bindStaticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::SportMenu
  //
  SportMenu::SportMenu(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void SportMenu::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header(type_);

    //
    // 1. Binding options which edit the sport
    //
    printIllegalOption(object[1].first + ": " + object[1].second);
    divider(40);
    bindDynamicOption(map, 1, nextState_[1], object[2].first, 
                                              (object[2].first + ": " + object[2].second));

    //
    // 2. Binding opitons which selects a dicipline
    //
    std::cout << "\n";
    printIllegalOption(object[3].first + ": " + object[3].second);
    bindDynamicOption(map, 2, nextState_[2], object[1].second,"New dicipline");
      
    for (auto i = 4; i < (4 + (std::stoi(object[3].second)*3)); i+=3 )
      { bindDynamicOption(map, (i/3)+2, nextState_[3], object[i].second, object[i].second); }

    divider(40);
    bindStaticOption(map, 0, nextState_[0], "Back     ");
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
  void DiciplineMenu::view(dat::TransitionMap& map, dat::Object& object, const std::string& key) 
  {
    newPage();
    header(type_);

    // @for @brief advance iterator, until we get to the content about the selected dicipline
    int it = 0;
    while (object[it].second != key)
      { it++; }

    printIllegalOption(object[it].second);
    divider(40);
    bindDynamicOption(map, 1, nextState_[1], object[it+1].first, object[it+1].first + ": " + object[it+1].second);
    bindDynamicOption(map, 2, nextState_[1], object[it+2].first, object[it+2].first + ": " + object[it+2].second);
    bindDynamicOption(map, 3, nextState_[2], object[it].second, "Start list");
    bindDynamicOption(map, 4, nextState_[3], object[it].second, "Result List");

    std::string sportKey = key.substr(0, (key.find("_")));  // @hack

    divider(40);
    bindDynamicOption(map, 5, nextState_[4], key, "Delete");
    bindDynamicOption(map, 0, nextState_[0], sportKey, "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject
  //
  NewObject::NewObject(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void NewObject::view(dat::TransitionMap& map, dat::Object& newObject)
  {
   newPage();
   header(type_ + " new");
   newObject = form::object(type_);
   bindStaticOption(map, 1, nextState_[1], "New  " + type_);
   bindStaticOption(map, 0, nextState_[0], "Back");
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewDicipline
  //
  NewDicipline::NewDicipline(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void NewDicipline::view(dat::TransitionMap& map, dat::Object& sport, const std::string& key)
  { 
    newPage();
    header(type_ + " append");
    form::appendDicipline(sport);
    footer();
    bindDynamicOption(map, 0, nextState_[0], key, "Back");
    footer();
  }
  
  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField 
  //
  EditField::EditField(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void EditField::view(dat::TransitionMap& map, dat::Object& object, const std::string& key) 
  { 
    newPage();
    header(type_ + " edit");

    // Finding the chosen field to edit
    for(auto& field: object)
    { 
      if (field.first == key)
        { form::field(field); break; }
    }
    bindDynamicOption(map, 0, nextState_[0], key, "Back");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::StartLIst
  //
  StartList::StartList(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void StartList::view(dat::TransitionMap& map, dat::Container& starts, const std::string& key)
  {
    newPage();
    header(type_);
    starts.clear();   //@debug
    if (starts.empty())
    {
      form::startList(starts);
    } 

    // entry[1] == name
    // entry[2] == ID
    for (const auto& entry: starts)
    {
      printIllegalOption(entry[1].second + ": " + entry[2].second);
    }

    bindDynamicOption(map, 1, nextState_[1], key, "Delete start-list");
    bindDynamicOption(map, 0, nextState_[0], key, "Back     ");
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
    dat::TransitionMap& map,
    dat::Container& starts, 
    dat::Container& results, 
    const std::string& key)
  {
    newPage();
    header(type_);
    // starts.clear(); //@debug
    if (!(starts.empty()))
    { 
      if(results.empty()) 
        { form::resultList(results, starts.size()); }
      
      for (int it=0; it < starts.size(); it++)
      {
        printIllegalOption( starts[it][1].second + " - " +  starts[it][2].second + " - " + results[it][2].second);
      }
      bindDynamicOption(map, 1, nextState_[1], key, "Delete results");
    }
    else
      { std::cout << "ERROR: You have to create a start-list first\n"; }

    bindDynamicOption(map, 0, nextState_[0], key, "Back      ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Error 
  //
  Error::Error(const std::string& type, const std::vector<int>& nextState)
  :ConsoleMenu(type, nextState)
  {}

  void Error::view()
  {
   header("Error");
   std::cout << type_;
   footer();
  }
}






