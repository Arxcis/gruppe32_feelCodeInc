#include "consoleList.h"


void list::nations(const std::vector<std::vector<std::string>>* containers, int step=20)
{
  for (const auto& cont: (*containers))
  {
    std::cout << "Nation 1-" << step << ":\n"
              << "\tCode: "          << cont[1] 
              << "\tName: "          << cont[2] 
              << "\t#participants: " << cont[3] << std::endl;
  }
}

void list::participants(const std::vector<std::vector<std::string>>* containers, int step=20)
{
  for (const auto& cont: (*containers))
  {
    std::cout << "Participant 1-" << step << ":\n"
              << "\tID: "     << cont[1] 
              << "\tName: "   << cont[2] 
              << "\tNation: " << cont[5] << std::endl;
  }
}

void list::sports(const std::vector<std::vector<std::string>>* containers, int step=20)
{
  for (const auto& cont: (*containers))
  {
    std::cout << "Sport 1-" << step << ":\n"
              << "\tName: "        << cont[1]
              << "\tScoreType: ";

    (std::stoi(cont[2]) == 0) ? (std::cout << "Points") : (std::cout << "Medals"); // points=0, medals=1  
    
    std::cout << "\t#diciplines: " << cont[3] << std::endl;
  }
}

void list::diciplines(const std::vector<std::vector<std::string>>* containers, int step=20)
{
  for (const auto& cont: (*containers))
  {
    std::cout << "Dicipline 1-" << step << ":\n"
              << "\tName: "     << cont[1] 
              << "\tTime: "     << cont[2] 
              << "\tDate: "     << cont[3] 
              << "\t#participants: " << cont[4] << std::endl;
  }
}

void list::diciplineList(const std::vector<std::vector<std::string>>* containers, int step=20)
{
  for (const auto& cont: (*containers))
  {
    std::cout << "Participant 1-" << step << ":\n"
              << "\tName: "       << cont[1] 
              << "\t#start: "     << cont[2] 
              << "\tResult: "    << cont[3] << std::endl;
  }
}
