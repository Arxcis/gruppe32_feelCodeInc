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


  //---------//---------//---------//---------//---------//---------//
  //
  //  ABSTRACT BASE CLASS ConsoleMenu
  //

  int ConsoleMenu::getNextIndex(const int userInput)
  {
    auto it = mapNext_.find(userInput);

    if(it != mapNext_.end())  // If it exists in the map
      { return it->second; }
    else 
      { return -1; }
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
  //  BASES MENU classes
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

    containers = api_.getAll(NATION);

    header("Nation Base");
    std::cout << "   1: New          \n";
      list::nations(containers);
    std::cout << "   0: Back         \n";
    footer();
  }

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

    containers = api_.getAll(PARTICIPANT);

    header("Participant Base");
    std::cout << "   1: New              \n";
      list::participants(containers);
    std::cout << "   0: Back             \n";
    footer();
  }

  SportBase::SportBase(const std::vector<int> args)
  {   
    mapNext_ = 
      {{ 0, args[0] },
       { 1, args[1] },
       { 2, args[2] }};
  }

  void SportBase::view()
  {
    containers = api_.getAll(SPORT);
    

    newPage();
    header("Sport Base");

    std::cout << "   1: New          \n";        
      list::sports(containers);  
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
}


/*void menu::ListBase::view(){}

void menu::Nation::view(){}
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




