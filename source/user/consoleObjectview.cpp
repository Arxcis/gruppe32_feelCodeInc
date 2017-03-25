#include "consoleObjectview.h"

inline void view::field(const std::string key, const std::string value)
{
  std::cout << key << ": " << value << "\n";
}

void view::nation(const std::vector<std::string>* nation) 
{
  view::field("Nation", *nation[0]);
  view::field("Short", *nation[1]);
  view::field("Name", *nation[2]);
  view::field("Participant count", *nation[3]);
  view::field("Contact", "");
  view::field("Name", *nation[4]);
  view::field("Phone", *nation[5]);
  view::field("Email", *nation[6]);
}

void participant(const std::vector<std::string>* participant)
{
  view::field("Object", *participant[0]);
  view::field("ID", *participant[1]);
  view::field("Name", *participant[2]);
  view::field("Phone", *participant[3]);
  view::field("Email", *participant[4]);
  view::field("Country", *participant[5]);
  view::field("Sex", *participant[6]);
}

void sport(const std::vector<std::string>* sport)
{
  view::field("Object", *sport[0]);
  view::field("Name", *sport[1]);
  view::field("ScoreType", *sport[2]);
  view::field("numofEvents", *sport[3]);
  view::field("e1", *sport[4]);
  view::field("e2", *sport[5]);
  view::field("e3", *sport[6]);
}

void event(const std::vector<std::string>* event)
{

  view::field("Object", *event[0]);
  view::field("Name", *event[1]);
  view::field("Time", *event[2]);
  view::field("Date", *event[3]);
  view::field("e2", *event[4]);
  view::field("e3", *event[5]);
}