#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  ////////////////////////////////////////////////////////////////
  //
  //  ABSTRACT BASE CLASS ConsoleMenu
  //


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
  //  BEGIN MENU
  //

  void Start::view(dat::TransitionMap& map)
  {
    newPage();
    header("Main Menu");
    bindStaticOption(map, 1, NATION_BASE, "Nations     ");
    bindStaticOption(map, 2, PART_BASE,   "Participants");
    bindStaticOption(map, 3, SPORT_BASE,  "Sports      ");
    bindStaticOption(map, 4, POINT_STATS,  "Points      ");
    bindStaticOption(map, 5, MEDAL_STATS, "Medals      ");
    bindStaticOption(map, 0, EXIT,         "Exit        ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NationBase
  //


  void NationBase::view(dat::TransitionMap& map, dat::Container& container)
  { 
    newPage();
    header("Nation Base");
    bindStaticOption(map, 1, NATION_NEW, "New      ");

    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, NATION_SELECT, object[1].second, 
                        (object[2].first + ":  " + object[2].second));
      it++;
    }
    bindStaticOption(map, 0, START, "Back      ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ParticipantBase
  //

  void ParticipantBase::view(dat::TransitionMap& map, dat::Container& container)
  {
    newPage();
    header("Participant Base");
    bindStaticOption(map, 1, PART_NEW, "New      ");

    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, PART_SELECT, object[1].second, 
                        (object[2].first + ":  " + object[2].second));
      it++;
    }
    bindStaticOption(map, 0, START, "Back      ");
    footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::SportBase
  //

  void SportBase::view(dat::TransitionMap& map, dat::Container& container)
  {
    newPage();
    header("Sport Base");
    bindStaticOption(map, 1, SPORT_NEW, "New      ");

    int it = 2;
    for(const auto& object: container)
    {
      bindDynamicOption(map, it, SPORT_SELECT, object[1].second, 
                        (object[2].first + ":  " + object[2].second));
      it++;
    }
    bindStaticOption(map, 0, START, "Back      ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  STATS MENU classes
  //

  void PointStats::view(dat::TransitionMap& map, dat::Object& object)
  {
    newPage();
    header("Point stats");
    bindStaticOption(map, 0, START, "Back     ");
    footer();
  }

  void MedalStats::view(dat::TransitionMap& map, dat::Object& object)
  {
    newPage();
    header("Medal stats");
    bindStaticOption(map, 0, START, "Back     ");
    footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Nation
  //
  void Nation::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Nation");
    int it=1;
    for(const dat::Field& field: object)
    {
      bindDynamicOption(map, it, NATION_EDIT, field.first, 
                        (field.first + ": " + field.second));
      it++;
    }
    bindStaticOption(map, 0, NATION_BASE, "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Participant
  //
  void Participant::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Participant");
    int it=1;
    for(const dat::Field& field: object)
    {
      bindDynamicOption(map, it, PART_EDIT, field.first, 
                        (field.first + ": " + field.second));
      it++;
    }
    bindStaticOption(map, 0, PART_BASE, "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Sport
  //
 

  void Sport::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Participant");
    int it=1;
    for(const dat::Field& field: object)
    {
      bindDynamicOption(map, it, SPORT_EDIT, field.first, 
                        (field.first + ": " + field.second));
      it++;
    }
    bindStaticOption(map, 0, SPORT_BASE, "Back     ");
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Dicipline
  //


  void Dicipline::view(dat::TransitionMap& map, dat::Object& object) 
  {
/*    newPage();
    header("Dicipline");
      object::view(selectedObjectSecond, 1); 
    std::cout << "   0: Back        \n";
    footer();*/
   std::cout << "Not implemented yet...";
   bindStaticOption(map, 0, START, "Back to start");
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject (Nation,Participant,Sport, Dicipline)
  //

  NewObject::NewObject(const std::string& type)
  :type_(type)
  {}

  void NewObject::view(dat::TransitionMap& map, dat::Object& newObject)
  {
   std::cout << "Not implemented yet...\n";
   bindStaticOption(map, 0, START, "Back to start");
  }

  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField (Nation,Participant,Sport, Dicipline)
  //

  void EditField::view(dat::TransitionMap& map, dat::Field& field)
  {
   std::cout << "Not implemented yet...\n";
   bindStaticOption(map, 0, START, "Back to start");
  }
}





