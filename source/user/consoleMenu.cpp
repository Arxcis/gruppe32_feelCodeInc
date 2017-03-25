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

int menu::begin()
{
  int command;
  menu::newPage();
  menu::header("Main Menu");
  std::cout << "1: Nations     \n"
            << "2: Participants\n"
            << "3: Sports      \n"
            << "4: Medals      \n"
            << "5: Points      \n"
            << "0: Exit        \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}


int menu::nationBase()
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

int menu::participantBase()
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

int menu::sportBase()
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

int menu::sport()
{
  int command;
  menu::footer();
  std::cout << "    1: New          \n"
            << " 2-11: Edit field   \n"
            << "    0: Back         \n";
  menu::footer();

  std::cin >> command; 
  std::cin.ignore(1);
  return command;
}

int menu::nation()
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

int menu::participant()
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

