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
    std::cout << "\n"
              << "--------------------------------------------------------------\n";
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
    std::cout << "\n"
              << "--------------------------------------------------------------\n" 
              << "|    " << name << "               \n"
              << "--------------------------------------------------------------\n"
              << "\n";
  }

  //
  // @class functions - bind menu option functions
  //

  inline void ConsoleMenu::illegalOption(
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
    header("Main Menu");
    bindStaticOption(map, 1, nextState_[1], "Nations     ");
    bindStaticOption(map, 2, nextState_[2], "Participants");
    bindStaticOption(map, 3, nextState_[3], "Sports      ");
    bindStaticOption(map, 4, nextState_[4],  "Points      ");
    bindStaticOption(map, 5, nextState_[5], "Medals      ");
    bindStaticOption(map, 0, nextState_[0],  "Exit        ");
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

    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, nextState_[2], object[1].second, 
                        (object[1].first + ":  " + object[1].second) + "\t " + (object[2].first + ":  " + object[2].second));
      it++;
    }
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
      { illegalOption(object[1].first + ": " + object[1].second + "\t" + object[2].first + ": "+  object[2].second + "\t" + object[3].first + ": " +  object[3].second + "\t"); }

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

    illegalOption(object[1].first + ": " + object[1].second);
    bindDynamicOption(map, 1, nextState_[1], object[2].first, (object[2].first + ": " + object[2].second));
    illegalOption(object[3].first + ": " + object[3].second);
    bindDynamicOption(map, 2, nextState_[1], object[4].first, (object[4].first + ": " + object[4].second));
    bindDynamicOption(map, 3, nextState_[1], object[5].first, (object[5].first + ": " + object[5].second));
    bindDynamicOption(map, 4, nextState_[1], object[6].first, (object[6].first + ": " + object[6].second));
    
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

    illegalOption(object[1].first + ": " + object[1].second);
    bindDynamicOption(map, 1, nextState_[1], object[2].first, (object[2].first + ": " + object[2].second));
    bindDynamicOption(map, 2, nextState_[1], object[3].first, (object[3].first + ": " + object[3].second));
    bindDynamicOption(map, 3, nextState_[1], object[4].first, (object[4].first + ": " + object[4].second));
    bindDynamicOption(map, 4, nextState_[1], object[5].first, (object[5].first + ": " + object[5].second)); // @robustness check if country exists

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

    illegalOption(object[1].first + ": " + object[1].second);

    // 1. Binding options which edit the sport
    bindDynamicOption(map, 1, nextState_[1], object[2].first, 
                                              (object[2].first + ": " + object[2].second));

    illegalOption(object[3].first + ": " + object[3].second);
      
    // 2. Binding opitons which selects a dicipline
    for (auto i = 4; i < (4 + (std::stoi(object[3].second)*3)); i+=3 )
    { 
      bindDynamicOption(map, (i/3)+1, nextState_[2], object[i].second, 
                                                      object[i].second); 
    }

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

    illegalOption(object[it].second);
    bindDynamicOption(map, 1, nextState_[1], object[it+1].first, object[it+1].first + ": " + object[it+1].second);
    bindDynamicOption(map, 2, nextState_[1], object[it+2].first, object[it+2].first + ": " + object[it+2].second);
    bindDynamicOption(map, 3, nextState_[2], object[it].second, "Start list");
    bindDynamicOption(map, 4, nextState_[3], object[it].second, "Result List");

    std::string sportKey = key.substr(0, (key.find("_")));  // @hack
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
   newObject = form::object(type_);
   bindStaticOption(map, 1, nextState_[1], "New  " + type_);
   bindStaticOption(map, 0, nextState_[0], "Back");
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
    std::cout << key << ": " << std::endl; 
    for(auto& field: object)
    { 
      if (field.first == key)
      {
        stream::readString(std::cin, field.second);
        break;
      }
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
    if (starts.empty())
    {

    }

    for (const auto& entry: starts)
    {
      //illegalOption()
    }

    bindDynamicOption(map, 1, nextState_[0], key, "Delete    ");
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

  void ResultList::view(dat::TransitionMap& map, dat::Container& starts, dat::Container& results, const std::string& key)
  {
    newPage();
    header(type_);

    bindDynamicOption(map, 1, nextState_[0], key, "Delete    ");
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






