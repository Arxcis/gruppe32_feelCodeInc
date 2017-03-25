#include "consoleMenu.h"

void menu::newPage()
{
  for(int i=0; i<40; i++)
  {
    std::cout << "\n";
  }
}

MenuState menu::begin()
{
  int command;
  menu::newPage();
  std::cout << "-------------------------------\n" 
            << "            MAIN MENU          \n"
            << "-------------------------------\n"
            << "\n"
            << "\n"
            << "1: Nations     \n"
            << "2: Participants\n"
            << "3: Sports      \n"
            << "0: Exit        \n"
            << "\n"
            << "\n"
            << "-------------------------------\n";

  std::cin >> command; std::cin.ignore(1);
  return (MenuState)command;
}


int menu::nationBase()
{
  int command;
  menu::newPage();
  std::cout << "-------------------------------\n" 
            << "          NATION BASE          \n"
            << "-------------------------------\n"
            << "\n"
            << "\n"
            << "   1: New          \n"
            << "2-10: Pick nation\n"
            << "   0: Back         \n"
            << "\n"
            << "\n"
            << "-------------------------------\n";

  std::cin >> command; std::cin.ignore(1);
  return command;
}

int menu::participantBase()
{
  int command;
  menu::newPage();
  std::cout << "-------------------------------\n" 
            << "        PARTICIPANT BASE       \n"
            << "-------------------------------\n"
            << "\n"
            << "\n"
            << "   1: New              \n"
            << "2-50: Pick Participant \n"
            << "   0: Back             \n"
            << "\n"
            << "\n"
            << "-------------------------------\n";

  std::cin >> command; std::cin.ignore(1);
  return command;
}

int menu::sportBase()
{
  int command;
  menu::newPage();
  std::cout << "-------------------------------\n" 
            << "           SPORT BASE          \n"
            << "-------------------------------\n"
            << "\n"
            << "\n"
            << "   1: New          \n"
            << "2-20: Pick Sport   \n"
            << "   0: Back         \n"
            << "\n"
            << "\n"
            << "-------------------------------\n";

  std::cin >> command; std::cin.ignore(1);
  return command;
}

