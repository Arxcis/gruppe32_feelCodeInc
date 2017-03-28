#include "ConsoleMenu.h"
#include <string>

namespace menu 
{

  //---------//---------//---------//---------//---------//---------//
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


  //---------//---------//---------//---------//---------//---------//
  //
  //  ABSTRACT BASE CLASS ConsoleMenu
  //

  // Define static members
  dat::Object* ConsoleMenu::selectedObject = nullptr;
  dat::Container* ConsoleMenu::selectedContainer = nullptr;

  int ConsoleMenu::getNextIndex(const int userInput)
  {
    const int clampedInput = clamp(userInput, (mapNext_.size()-1));
    auto it = mapNext_.find(clampedInput);

    return it->second;
  }


  //---------//---------//---------//---------//---------//---------//
  //
  //  BEGIN MENU
  //

  Begin::Begin(const std::vector<int> args)
  {
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] },
       { 2, args[2] },
       { 3, args[3] },
       { 4, args[4] },
       { 5, args[5] }};
  }

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


  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::NationBase
  //
  NationBase::NationBase(const std::vector<int> args)
  {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] },
       { 2, args[2] }};
  }

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

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::ParticipantBase
  //
  ParticipantBase::ParticipantBase(const std::vector<int> args)
  {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] },
       { 2, args[2] }};
  }

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

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::SportBase
  //
  SportBase::SportBase(const std::vector<int> args)
  {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] },
       { 2, args[2] }};
  }

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

  //---------//---------//---------//---------//---------//---------//
  //
  //  STATS MENU classes
  //

  PointStats::PointStats(const std::vector<int> args)
  {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] }};
  }

  void PointStats::view()
  {
    menu::newPage();
    menu::header("Point stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    menu::footer();
  }

  MedalStats::MedalStats(const std::vector<int> args)
   {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] }};
  }

  void MedalStats::view()
  {
    newPage();
    header("Medal stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    footer();
  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::Nation
  //
  Nation::Nation(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] }};
  }

  void Nation::view()
  {
    newPage();
    header("Nation");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::Participant
  //

  Participant::Participant(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] }};
  }
  void Participant::view()
  {
    newPage();
    header("Participant");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::Sport
  //
  Sport::Sport(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] }};
  }
  void Sport::view()
  {
    newPage();
    header("Sport");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }


  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::Dicipline
  //
  Dicipline::Dicipline(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] }};
  }

  void Dicipline::view()
  {
    newPage();
    header("Dicipline");
      object::view(selectedObject, 1); 
    std::cout << "   0: Back        \n";
    footer();
  }







  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::NewNation
  //

  NewNation::NewNation(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] },
     { 2, args[2] }};
  }
  void NewNation::view()
  {
    header("New Dicipline");

    selectedObject = form::nation();    
    api_.add(selectedObject); 

    std::cout << "   1: New          \n";
    std::cout << "   2: Show Newest  \n";
    std::cout << "   0: New          \n";
  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::NewParticipant
  //

  NewParticipant::NewParticipant(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] },
     { 2, args[2] }};
  }

  void NewParticipant::view()
  { 
    header("New Participant");

    selectedObject = form::participant();    
    api_.add(selectedObject); 

    std::cout << "   1: New        \n";
    std::cout << "   2: Show new   \n";
    std::cout << "   0: New        \n";
  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::NewSport
  //

  NewSport::NewSport(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] },
     { 2, args[2] }};
  }
  void NewSport::view()
  {
    header("New Sport");

    selectedObject = form::sport();    
    api_.add(selectedObject); 

    std::cout << "   1: New          \n";
    std::cout << "   2: Show new  \n";
    std::cout << "   0: New          \n";

  }

  //---------//---------//---------//---------//---------//---------//
  //
  //  @class menu::NewDicipline
  //

  NewDicipline::NewDicipline(const std::vector<int> args)
  {
    mapNext_ = 
    {{ 0, args[0] },
     { 1, args[1] },
     { 2, args[2] }};
  }

  void NewDicipline::view()
  {
    header("New Dicipline");

    selectedObject = form::dicipline();    
    api_.add(selectedObject); 
    
    std::cout << "   1: New       \n";
    std::cout << "   2: Show new  \n";
    std::cout << "   0: New       \n";
  }
}





/*void menu::ListBase::view(){}
*/


/*
void menu::EditNation::view(){}
void menu::EditParticipant::view(){}
void menu::EditSport::view(){}
void menu::EditDicipline::view(){}

void menu::DeleteDicipline::view(){}
void menu::DeleteList::view(){}

void menu::AppendList::view(){}
void menu::AppendResult::view(){} */




