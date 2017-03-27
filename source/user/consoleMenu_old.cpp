#include "consoleMenu_old.h"



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

