#include "consoleObjectview.h"

char ch;

namespace objectView 
{
  inline void field(const std::string key, const std::string value)
  {
    std::cout << key << ": " << value << "\n";
  }

  void nation(const std::vector<std::string>* nation, int startIndex) 
  {
    if(nation)
    {
        field("Short", (*nation)[1]);
        field("Name", (*nation)[2]);
        field("Participant count", (*nation)[3]);
        field("ContactName", (*nation)[4]);
        field("ContactPhone", (*nation)[5]);
        field("ContactEmail", (*nation)[6]);
    }
    else 
      { field("", " not found...."); }
    
  }

  void participant(const std::vector<std::string>* participant, int startIndex)
  {
    field("ID", (*participant)[1]);
    field("Name", (*participant)[2]);
    field("Phone", (*participant)[3]);
    field("Email", (*participant)[4]);
    field("Country", (*participant)[5]);
    field("Sex", (*participant)[6]);

  }

  void sport(const std::vector<std::string>* sport, int startIndex)
  { 
    field("Name", (*sport)[1]);
    field("ScoreType", (*sport)[2]);
    field("numofdiciplines", (*sport)[3]);
    field("e1", (*sport)[4]);
    field("e2", (*sport)[5]);
    field("e3", (*sport)[6]);

  }

  void dicipline(const std::vector<std::string>* dicipline, int startIndex)
  {
    field("Name", (*dicipline)[1]);
    field("Time", (*dicipline)[2]);
    field("Date", (*dicipline)[3]);
    field("Participant list", " - >");
    field("Result list", " - >");

  }
}