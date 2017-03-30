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

  inline void ConsoleMenu::footer()
  {
    std::cout << "\n"
              << "-------------------------------\n";
  }

  inline void ConsoleMenu::newPage()
  {
    for(int i=0; i<40; i++)
    {
      std::cout << "\n";
    }
  }

  inline void ConsoleMenu::header(std::string name)
  {   
    newPage();
    std::cout << "\n"
              << "-------------------------------\n" 
              << "| " << name << "               \n"
              << "-------------------------------\n"
              << "\n";
  }

  inline int ConsoleMenu::clamp(const int input, const int max)
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
  // @class functions - register menu option functions
  //
  constexpr inline void ConsoleMenu::bindStaticOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& text);
  {  
    std::cout << select << ": " << text << " \n";  // 1. Write option to screen
    map[select] = { menuPointer, "" }              // 2. Bind option to next menu
  }

  inline void ConsoleMenu::bindDynamicOption(
    dat::TransitionMap& map,
    const int select, 
    const int menuPointer,
    const std::string& text,
    const std::string& id)
  {
    
    std::cout << select << ": " << text << " \n"; // 1. Write option to screen
    map[select] = { menuPointer, id }             // 2. Bind option AND object to next menu
  }

  ////////////////////////////////////////////////////////////////
  //
  //  BEGIN MENU
  //

  void Begin::view(dat::TransitionMap& map)
  {
    newPage();
    header("Main Menu");
    std::cout << "1: Nations     \n"
              << "2: Participants\n"
              << "3: Sports      \n"
              << "4: Points      \n"
              << "5: Medals      \n"
              << "0: Exit        \n";
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NationBase
  //


  void NationBase::view(dat::TransitionMap& map, dat::Container& container)
  { 
    newPage();

    //
    // Resetting selectedContainer here, in case I dont get anything
    // 
    selectedContainer = nullptr;
    *selectedContainer = *(api_->getAll(NATION));

    header("Nation Base");
    std::cout << "   1: New          \n";
      list::nations(selectedContainer);
    std::cout << "   0: Back         \n";
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ParticipantBase
  //

  void ParticipantBase::view(dat::TransitionMap& map, dat::Container& container)
  {
    newPage();

    *selectedContainer = *(api_->getAll(PARTICIPANT));

    header("Participant Base");
    std::cout << "   1: New              \n";
      list::participants(selectedContainer);
    std::cout << "   0: Back             \n";
    footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::SportBase
  //

  void SportBase::view(dat::TransitionMap& map, dat::Container& container)
  {
    *selectedContainer = *(api_->getAll(SPORT));

    newPage();
    header("Sport Base");

    std::cout << "   1: New          \n";        
      list::sports(selectedContainer);  
    std::cout << "   0: Back         \n";
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  STATS MENU classes
  //



  void PointStats::view(dat::TransitionMap& map, dat::Container& container)
  {
    menu::newPage();
    menu::header("Point stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    menu::footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Nation
  //
 
  void Nation::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Nation");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
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
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Sport
  //
 

  void Sport::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Sport");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Dicipline
  //


  void Dicipline::view(dat::TransitionMap& map, dat::Object& object) 
  {
    newPage();
    header("Dicipline");
      object::view(selectedObjectSecond, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }



  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject (Nation,Participant,Sport, Dicipline)
  //

  NewObject::NewObject(const std::string& type)
  type_(type)
  {}

  void NewObject::view(dat::TransitionMap& map)
  {
    header(("New " + type_));

    selectedObject = form::object(type_);    
    (api_->add(selectedObject));

    std::cout << "   1: New          \n";
    std::cout << ("   2: Show " + type_ + "  \n");
    std::cout << "   0: Back         \n";
    footer();
  }

  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField (Nation,Participant,Sport, Dicipline)
  //

  void EditField::view(dat::TransitionMap& map)
  {
    if (selectedField)
    {
      footer();
      form::field(*selectedField);
      (api_->add(selectedObject));
    }
    else
      { std::cout << "     Field not allowed..\n"; } 

    std::cout << "   0: Any number to go back...  \n";
    footer();
  }
}

/*void menu::ListBase::view(dat::TransitionMap& map){}
*/


/*

void menu::DeleteDicipline::view(dat::TransitionMap& map){}
void menu::DeleteList::view(dat::TransitionMap& map){}

void menu::AppendList::view(dat::TransitionMap& map){}
void menu::AppendResult::view(dat::TransitionMap& map){} */




