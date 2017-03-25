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
            << "1: Nations     \n"
            << "2: Participants\n"
            << "3: Sports      \n"
            << "0: Exit        \n"
            << "-------------------------------\n";

  std::cin >> command; std::cin.ignore(1);
  return (MenuState)command;
}
