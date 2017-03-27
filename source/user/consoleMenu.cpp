#include "consoleMenu.h"


inline void menu::header(std::string name)
{ 
  std::cout << "\n"
            << "-------------------------------\n" 
            << "| " << name << "               \n"
            << "-------------------------------\n"
            << "\n";
}

inline void menu::footer()
{
  std::cout << "\n"
            << "-------------------------------\n";
}


inline void menu::newPage()
{
  for(int i=0; i<40; i++)
  {
    std::cout << "\n";
  }
}

int menu::begin_()
{
  int command;
  menu::newPage();
  menu::header("Main Menu");
  std::cout << "1: Nations     \n"
            << "2: Participants\n"
            << "3: Sports      \n"
            << "4: Points      \n"
            << "5: Medals      \n"
            << "0: Exit        \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}


int menu::nationBase_()
{
  int command;
  menu::newPage();
  menu::header("Nation Base");
  std::cout << "   1: New          \n"
            << "2-10: Pick nation  \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::participantBase_()
{
  int command;
  menu::newPage();
  menu::header("Participant Base");
  std::cout << "   1: New              \n"
            << "2-50: Pick Participant \n"
            << "   0: Back             \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::sportBase_()
{
  int command;
  menu::newPage();
  menu::header("Sport Base");
  std::cout << "   1: New          \n"
            << "2-20: Pick Sport   \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::listBase_()
{
  int command;
  menu::newPage();
  menu::header("List base");
  std::cout << "   1: Add participant \n"
            << "   2: Add results     \n"
            << "   3: Delete list     \n"
            << "   0: Back            \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::pointStats_()
{
  int command;
  menu::newPage();
  menu::header("Point stats");
  std::cout << "   1: Sort          \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::medalStats_()
{
  int command;
  menu::newPage();
  menu::header("Medal stats");
  std::cout << "   1: Sort          \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::sport_()
{
  int command;
  menu::footer();
  std::cout << "    1: New            \n"
            << "  2-3: Edit field     \n"
            << "  4-6: Edit dicipline \n"
            << "    0: Back           \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::nation_()
{
  int command;
  menu::footer();
  std::cout << "   1: New          \n"
            << " 2-7: Edit field   \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::participant_()
{
  int command;
  menu::footer();
  std::cout << "   1: New          \n"
            << " 2-7: Edit field   \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}


int menu::dicipline_()
{
  int command;
  menu::footer();
  std::cout << "   1: New          \n"
            << " 2-4: Edit field   \n"
            << "   5: Lists        \n"
            << "   6: Delete       \n"
            << "   0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::deleteDicipline_()
{
  int command;
  menu::footer();
  std::cout << "Are you sure??\n"
            << " 0: No \n"
            << " 1: Yes \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::deleteList_()
{
  int command;
  menu::footer();
  std::cout << "Are you sure??\n"
            << " 0: No \n"
            << " 1: Delete participant-list..\n"
            << " 2: Delete result-list..\n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

