#include "Console.h"

bool Console::instantiated_ = false;


Console::Console()
{ 
  assert(!instantiated_);
  instantiated_ = true;
}


Console::~Console() 
{ 
  instantiated_ = false; 

  for (int i=0; i < maxMenus_; i++)
    { delete allMenus_[i]; }
}

//
// @funciton run()
//  @brief the entry-point function for presenting the menu system
//   to the user.
//
int Console::run()
{ 
  bool running = true;
  int nextMenuIndex = 0;
  int selectedNumber = 0;

  currentMenu_ = allMenus_[0];

  while(running)
  {
    currentMenu_->view();
    selectedNumber = stream::readInt("(0-N)");
    nextMenuIndex  = currentMenu_->getNextIndex(selectedNumber);

    if(nextMenuIndex == -1)
      { std::cout << "Exiting...\n";  running = false; }
    else
      { currentMenu_ = allMenus_[nextMenuIndex]; }
  }

  return 0;
}
