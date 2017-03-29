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

  ConsoleMenu::ConsoleMenu(const std::vector<int> args)
  {
    for(int i=0; i < args.size(); i++)
      mapNext_[i] = args[i];
  }

  // Define static members
  dat::Field*     ConsoleMenu::selectedField        = nullptr;
  dat::Object*    ConsoleMenu::selectedObject       = nullptr;
  dat::Object*    ConsoleMenu::selectedObjectSecond = nullptr;
  dat::Container* ConsoleMenu::selectedContainer    = nullptr;

  int ConsoleMenu::getNextIndex(const int userInput)
  {
    const int clampedInput = clamp(userInput, (mapNext_.size()-1));
    auto it = mapNext_.find(clampedInput);

    return it->second;
  }


  ////////////////////////////////////////////////////////////////
  //
  //  BEGIN MENU
  //

  Begin::Begin(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

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
  NationBase::NationBase(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void NationBase::view()
  { 
    newPage();

    //
    // Resetting selectedContainer here, in case I dont get anything
    // 
    selectedContainer = nullptr;
    selectedContainer = api_.getAll(NATION);

    header("Nation Base");
    std::cout << "   1: New          \n";
      list::nations(selectedContainer);
    std::cout << "   0: Back         \n";
    footer();
  }

  int NationBase::getNextIndex(const int userInput)
  {  
    //
    // Resetting selectedContainer here, in case I dont get anything
    // 
    selectedObject = nullptr;
    //
    // @ugly - This will select a container, if there exists one
    //          Subtract 2 from userInput to get the actual index of the container in the vector.
    if (userInput >= 2 && userInput <= selectedContainer->size()+1) 
      { selectedObject = &((*selectedContainer)[userInput-2]); }

    return ConsoleMenu::getNextIndex(userInput);
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::ParticipantBase
  //
  ParticipantBase::ParticipantBase(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void ParticipantBase::view()
  {
    newPage();

    selectedContainer = api_.getAll(PARTICIPANT);

    header("Participant Base");
    std::cout << "   1: New              \n";
      list::participants(selectedContainer);
    std::cout << "   0: Back             \n";
    footer();
  }

  int ParticipantBase::getNextIndex(const int userInput)
  {  
    selectedObject = nullptr;

    if (userInput >= 2 && userInput <= selectedContainer->size()+1) 
      { selectedObject = &((*selectedContainer)[userInput-2]); }

    return ConsoleMenu::getNextIndex(userInput);
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::SportBase
  //
  SportBase::SportBase(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void SportBase::view()
  {
    selectedContainer = api_.getAll(SPORT);

    newPage();
    header("Sport Base");

    std::cout << "   1: New          \n";        
      list::sports(selectedContainer);  
    std::cout << "   0: Back         \n";
    footer();
  }

  int SportBase::getNextIndex(const int userInput)
  {  
    selectedObject = nullptr;

    if (userInput >= 2 && userInput <= selectedContainer->size()+1) 
      { selectedObject = &((*selectedContainer)[userInput-2]); }

    return ConsoleMenu::getNextIndex(userInput);
  }

  ////////////////////////////////////////////////////////////////
  //
  //  STATS MENU classes
  //

  PointStats::PointStats(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void PointStats::view()
  {
    menu::newPage();
    menu::header("Point stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    menu::footer();
  }

  MedalStats::MedalStats(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void MedalStats::view()
  {
    newPage();
    header("Medal stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    footer();
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Nation
  //
  Nation::Nation(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void Nation::view()
  {
    newPage();
    header("Nation");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  int Nation::getNextIndex(const int userInput)
  {  
    selectedField = nullptr;

    if (userInput >= 2 && userInput <= 6) 
      { selectedField = &((*selectedObject)[userInput]); }

    return ConsoleMenu::getNextIndex(userInput);
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Participant
  //

  Participant::Participant(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void Participant::view()
  {
    newPage();
    header("Participant");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  int Participant::getNextIndex(const int userInput)
  {  
    selectedField = nullptr;

    if (userInput >= 2 && userInput <= 6) 
      { selectedField = &((*selectedObject)[userInput]); }

    return ConsoleMenu::getNextIndex(userInput);
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Sport
  //
  Sport::Sport(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void Sport::view()
  {
    newPage();
    header("Sport");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  int Sport::getNextIndex(const int userInput)
  {  
    selectedField = nullptr;

    if (userInput >= 2 && userInput <= 2) 
    { 
      selectedField = &((*selectedObject)[userInput]); 
      return ConsoleMenu::getNextIndex(1);
    }

    else if (userInput >= 4 && userInput < selectedObject->size()) 
    { 
      selectedObjectSecond = api_.get(DICIPLINE, ((*selectedObject)[userInput]));
      return ConsoleMenu::getNextIndex(2);
    }
    else
      { return ConsoleMenu::getNextIndex(0); }
  }

  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::Dicipline
  //
  Dicipline::Dicipline(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void Dicipline::view()
  {
    newPage();
    header("Dicipline");
      object::view(selectedObjectSecond, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  int Dicipline::getNextIndex(const int userInput)
  {  
    selectedField = nullptr;

    if (userInput >= 2 && userInput <= 3) 
      { selectedField = &((*selectedObject)[userInput]); }

    return ConsoleMenu::getNextIndex(userInput);
  }


  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::NewObject (Nation,Participant,Sport, Dicipline)
  //

  NewObject::NewObject(const std::vector<int> args, const std::string type)
  :ConsoleMenu(args),
  type_(type)
  {}

  void NewObject::view()
  {
    header(("New " + type_));

    selectedObject = form::object(type_);    
    api_.add(selectedObject); 

    std::cout << "   1: New          \n";
    std::cout << ("   2: Show " + type_ + "  \n");
    std::cout << "   0: Back         \n";
    footer();
  }

  
  ////////////////////////////////////////////////////////////////
  //
  //  @class menu::EditField (Nation,Participant,Sport, Dicipline)
  //

  EditField::EditField(const std::vector<int> args)
  :ConsoleMenu(args)
  {}

  void EditField::view()
  {
    if (selectedField)
    {
      footer();
      form::field(*selectedField);
      api_.add(selectedObject);
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




