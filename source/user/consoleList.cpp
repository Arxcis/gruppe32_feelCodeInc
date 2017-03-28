#include "consoleList.h"

namespace list 
{
  inline void printField(const dat::Field& field)
  {
    std::cout << "  "<<std::get<0>(field) << ": " << std::get<1>(field) << "    ";
  }

  void nations(const dat::Container* container)
  {
    //std::cout << "Nation 1-step:\n";
    int count = 2;
     for (const auto& object: (*container))
    { 
      std::cout <<  "\t" << count << ": ";
      printField(object[1]);
      printField(object[2]);
      printField(object[3]);
      std::cout << std::endl;
      count++;
    }
  }

  void participants(const dat::Container* container)
  {
    //std::cout << "Participant 1-step:\n";
    int count = 2;
   for (const auto& object: (*container))
    {
      std::cout << "\t" << count << ": ";
      printField(object[1]);
      printField(object[2]);
      printField(object[5]);
      std::cout << std::endl;
      count++;
    }
  }

  void sports(const dat::Container* container)
  {
    //std::cout << "Sport 1-step:\n";
    int count = 2;
    for (const auto& object: (*container))
    {
      std::cout << "\t" << count << ": ";
      printField(object[1]);
      printField(object[2]);
      printField(object[3]);
      std::cout << std::endl;
      count++;
    }
  }

  void diciplines(const dat::Container* container)
  {
    //std::cout << "Dicipline 1-step:\n";
    int count = 2;
  for (const auto& object: (*container))
    {
      std::cout << "\t" << count << ": ";
      printField(object[1]);
      printField(object[2]);
      printField(object[3]);
      printField(object[4]);
      std::cout << std::endl;
      count++;
    }
  }

  void diciplineList(const dat::Container* container)
  {
    //std::cout << "Participant 1-step:\n";
    int count = 2;
    for (const auto& object: (*container))
    {
      std::cout << "\t" << count << ": ";
      printField(object[1]);
      printField(object[2]);
      printField(object[3]);
      printField(object[4]);
      std::cout << std::endl;
      count++;
    }
  }
}
