#include "stream.h"


void stream::readString(const std::string& message, std::string& value)
{
  std::cout << message << " :  "; 
  getline(std::cin, value, '\n');
}

void stream::readPhone(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isPhone(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

void stream::readEmail(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isEmail(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

void stream::readInt(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isInt(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

int stream::readInt(const std::string& message)
{ 
  std::string tempString;
  std::cout << message << " :  ";  getline(std::cin, tempString, '\n');
  while(!valid::isInt(tempString)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, tempString, '\n');
  }
  return std::stoi(tempString);
}

void stream::readDouble(const std::string& message, std::string&value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isDouble(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

void stream::readTime(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isTime(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

void stream::readDate(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isDate(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}

void stream::readMedals(const std::string& message, std::string& value)
{
  std::cout << message << " :  ";  getline(std::cin, value, '\n');
  while(!valid::isMedals(value)) 
  {  
    std::cout << "Wrong input...\n";
    std::cout << message << " :  ";  getline(std::cin, value, '\n');
  }
}
