#include "consoleObjectview.h"



namespace object 
{
  inline void printField(const std::string index, const dat::Field& field)
  {
    std::cout << "\t" << index << ": " << std::get<0>(field) << ": " << std::get<1>(field) << "\n";
  }

  void view(const dat::Object* object, int startIndex) 
  {
    if(object) 
    {
      for(auto& field: (*object)) 
      {
        printField(std::to_string(startIndex), field);
        startIndex++;
      }
    }
    else 
      { printField("", { "Object", " not found...."}); }  
  }
}
