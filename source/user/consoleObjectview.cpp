#include "consoleObjectview.h"

char ch;

inline void view::field(const std::string key, const std::string value)
{
  std::cout << key << ": " << value << "\n";
}

void view::nation(const std::vector<std::string>* nation) 
{
  menu::newPage();
  menu::header((*nation)[0]);
  view::field("Short", (*nation)[1]);
  view::field("Name", (*nation)[2]);
  view::field("Participant count", (*nation)[3]);
  std::cout << "Contact\n";
  view::field("Name", (*nation)[4]);
  view::field("Phone", (*nation)[5]);
  view::field("Email", (*nation)[6]);
  
}

void view::participant(const std::vector<std::string>* participant)
{
  menu::newPage();
  menu::header((*participant)[0]);
  view::field("ID", (*participant)[1]);
  view::field("Name", (*participant)[2]);
  view::field("Phone", (*participant)[3]);
  view::field("Email", (*participant)[4]);
  view::field("Country", (*participant)[5]);
  view::field("Sex", (*participant)[6]);

}

void view::sport(const std::vector<std::string>* sport)
{ 
  menu::newPage();
  menu::header((*sport)[0]);
  view::field("Name", (*sport)[1]);
  view::field("ScoreType", (*sport)[2]);
  view::field("numofEvents", (*sport)[3]);
  view::field("e1", (*sport)[4]);
  view::field("e2", (*sport)[5]);
  view::field("e3", (*sport)[6]);

}

void view::event(const std::vector<std::string>* event)
{
  menu::newPage();
  menu::header((*event)[0]);
  view::field("Name", (*event)[1]);
  view::field("Time", (*event)[2]);
  view::field("Date", (*event)[3]);
  view::field("e2", (*event)[4]);
  view::field("e3", (*event)[5]);

}