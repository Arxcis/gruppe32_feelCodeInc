#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  ////////////////////////////////////////////////////////////////
  //
  //  HELPER FUNCTIONS
  //

  inline void header(std::string name)
  {   
    newPage();
    std::cout << "\n"
              << "-------------------------------\n" 
              << "| " << name << "               \n"
              << "-------------------------------\n"
              << "\n";
  }

  inline void footer()
  {
    std::cout << "\n"
              << "-------------------------------\n";
  }

  inline void newPage()
  {
    for(int i=0; i<40; i++)
    {
      std::cout << "\n";
    }
  }

  inline int clamp(const int input, const int max)
  { 
    const int min = 0;

    if(input > max)
      { return max; }
    else if (input < min)
      { return min; }
    else 
      { return input; }
  }


  ////////////////////////////////////////////////////////////////
  //
  //  ABSTRACT BASE CLASS ConsoleMenu
  //




  ////////////////////////////////////////////////////////////////
  //
  //  BEGIN MENU
  //

  void Begin::view()
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


  void NationBase::view()
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

  void ParticipantBase::view()
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

  void SportBase::view()
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



  void PointStats::view()
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
 
  void Nation::view()
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



  void Participant::view()
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
 

  void Sport::view()
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


  void Dicipline::view()
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

  NewObject::NewObject(const std::string type)
  type_(type)
  {}

  void NewObject::view()
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

  void EditField::view()
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

/*void menu::ListBase::view(){}
*/


/*

void menu::DeleteDicipline::view(){}
void menu::DeleteList::view(){}

void menu::AppendList::view(){}
void menu::AppendResult::view(){} */




