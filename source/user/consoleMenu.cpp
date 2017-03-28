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
  std::vector<std::string>* ConsoleMenu::selectedContainer = nullptr;
  std::vector<std::vector<std::string>>* ConsoleMenu::selectedContainers = nullptr;

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
    // Resetting selectedContainers here, in case I dont get anything
    // 
    selectedContainers = nullptr;
    selectedContainers = api_.getAll(NATION);

    header("Nation Base");
    std::cout << "   1: New          \n";
      list::nations(selectedContainers);
    std::cout << "   0: Back         \n";
    footer();
  }

  int NationBase::getNextIndex(const int userInput)
  {  
    //
    // Resetting selectedContainer here, in case I dont get anything
    // 
    selectedContainer = nullptr;

    //
    // @ugly - This will select a container, if there exists one
    //          Subtract 2 from userInput to get the actual index of the container in the vector.
    if (userInput >= 2 && userInput <= selectedContainers->size()+1) 
      { selectedContainer = &((*selectedContainers)[userInput-2]); }

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

    selectedContainers = api_.getAll(PARTICIPANT);

    header("Participant Base");
    std::cout << "   1: New              \n";
      list::participants(selectedContainers);
    std::cout << "   0: Back             \n";
    footer();
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
    selectedContainers = api_.getAll(SPORT);

    newPage();
    header("Sport Base");

    std::cout << "   1: New          \n";        
      list::sports(selectedContainers);  
    std::cout << "   0: Back         \n";
    footer();
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
    menu::newPage();
    menu::header("Medal stats");
    std::cout << "   1: Sort          \n"
              << "   0: Back         \n";
    menu::footer();
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
    menu::newPage();
    menu::header("Nation");
    objectView::nation(selectedContainer, 1); 
    std::cout << "   0: Back        \n";
    menu::footer();
  }
}


/*void menu::ListBase::view(){}
*/



/*
void menu::Participant::view(){}
void menu::Sport::view(){}
void menu::Dicipline::view(){}

void menu::NewNation::view(){}
void menu::NewParticipant::view(){}
void menu::NewSport::view(){}
void menu::NewDicipline::view(){}

void menu::EditNation::view(){}
void menu::EditParticipant::view(){}
void menu::EditSport::view(){}
void menu::EditDicipline::view(){}

void menu::DeleteDicipline::view(){}
void menu::DeleteList::view(){}

void menu::AppendList::view(){}
void menu::AppendResult::view(){} */




