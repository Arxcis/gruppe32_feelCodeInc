#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  ////////////////////////////////////////////////////////////////
  //
  //  ABSTRACT BASE CLASS ConsoleMenu
  //
  ConsoleMenu::ConsoleMenu(const std::string type, const std::vector<int> nextState)
  :type_(type)
  ,nextState_(nextState)
  {}
  // 
  // @class functions - helper functions
  //

  inline void ConsoleMenu::footer() const
  {
    std::cout << "\n"
              << "-------------------------------\n";
  }

  void ConsoleMenu::newPage() const
  {
    for(int i=0; i<40; i++)
    {
      std::cout << "\n";
    }
  }

  void ConsoleMenu::header(const std::string name) const
  {   
    newPage();
    std::cout << "\n"
              << "-------------------------------\n" 
              << "| " << name << "               \n"
              << "-------------------------------\n"
              << "\n";
  }

  //
  // @class functions - bind menu option functions
  //
  inline void ConsoleMenu::bindStaticOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& text) const
  {  
    std::cout << "   " << select << "-> " << text << " \n";  // 1. Write option to screen
    map[select] = { menuPointer, "" };             // 2. Bind option to next menu
  }

  inline void ConsoleMenu::bindDynamicOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& id,
    const std::string& text) const
  {
    
    std::cout << "   " << select << "-> " << text << "\n"; // 1. Write option to screen
    map[select] = { menuPointer, id };             // 2. Bind option AND object to next menu
  }

  ////////////////////////////////////////////////////////////////
  //
  //  START MENU
  //
  Start::Start(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {}

  void Start::view(dat::TransitionMap& map)
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
  Base::Base(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {}

  void Base::view(dat::TransitionMap& map, dat::Container& container)
  { 
    newPage();
    header(type_);
    bindStaticOption(map, 1, nextState_[1], "New      ");

    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, nextState_[2], object[1].second, 
                        (object[2].first + ":  " + object[2].second));
      it++;
    }
    bindStaticOption(map, 0, nextState_[0], "Back      ");
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Stats
  //
  Stats::Stats(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void Stats::view(dat::TransitionMap& map, dat::Object& object)
  {
    newPage();
    header(type_ + " stats");
    bindStaticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Object
  //

  Object::Object(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {} 

  void Object::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header(type_);
    int it=1;
    for(const dat::Field& field: object)
    {
      bindDynamicOption(map, it, nextState_[1], field.first, 
                        (field.first + ": " + field.second));
      it++;
    }
    bindStaticOption(map, 0, nextState_[0], "Back     ");
    footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject
  //

  NewObject::NewObject(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {}

  void NewObject::view(dat::TransitionMap& map, dat::Object& newObject)
  {
   std::cout << "Not implemented yet...\n";
   bindStaticOption(map, 0, START, "Back to start");
  }

  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField 
  //

  EditField::EditField(const std::string type, const std::vector<int> nextState)
  :ConsoleMenu(type, nextState)
  {}

  void EditField::view(dat::TransitionMap& map, dat::Field& field)
  {
   std::cout << "Not implemented yet...\n";
   bindStaticOption(map, 0, START, "Back to start");
  }
}





