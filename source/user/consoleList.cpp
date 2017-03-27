#include "consoleList.h"


void list::nations(const std::vector<std::vector<std::string>>* containers)
{
  //std::cout << "Nation 1-step:\n";
  int count = 2;
  for (const auto& cont: (*containers))
  {
    std::cout << "    " << count 
              << ":    Code: "          << cont[1] 
              << "    Name: "          << cont[2] 
              << "    #participants: " << cont[3] << std::endl;
              count++;
  }
}

void list::participants(const std::vector<std::vector<std::string>>* containers)
{
  //std::cout << "Participant 1-step:\n";
  int count = 2;
  for (const auto& cont: (*containers))
  {
    std::cout << "    " << count 
              << ":    ID: "     << cont[1] 
              << "    Name: "   << cont[2] 
              << "    Nation: " << cont[5] << std::endl;
              count++;
  }
}

void list::sports(const std::vector<std::vector<std::string>>* containers)
{
  //std::cout << "Sport 1-step:\n";
  int count = 2;
  for (const auto& cont: (*containers))
  {
    std::cout << "    " << count 
              << ":    Name: "        << cont[1]
              << "    ScoreType: ";

    (std::stoi(cont[2]) == 0) ? (std::cout << "Points") : (std::cout << "Medals"); // points=0, medals=1  
    
    std::cout << "    #diciplines: " << cont[3] << std::endl;
              count++;
  }
}

void list::diciplines(const std::vector<std::vector<std::string>>* containers)
{
  //std::cout << "Dicipline 1-step:\n";
  int count = 2;
  for (const auto& cont: (*containers))
  {
    std::cout << "    " << count 
              << ":    Name: "     << cont[1] 
              << "    Time: "     << cont[2] 
              << "    Date: "     << cont[3] 
              << "    #participants: " << cont[4] << std::endl;
              count++;
  }
}

void list::diciplineList(const std::vector<std::vector<std::string>>* containers)
{
  //std::cout << "Participant 1-step:\n";
  int count = 2;
  for (const auto& cont: (*containers))
  {
    std::cout << "    " << count 
              << ":    Name: "       << cont[1] 
              << "    #start: "     << cont[2] 
              << "    Result: "    << cont[3] << std::endl;
              count++;
  }
}
