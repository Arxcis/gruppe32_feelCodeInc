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
      int i = startIndex-1;
      for(auto& field: (*object)) 
      { 
        if(i >= startIndex)
          printField(std::to_string(i), field);
        i++;
      }
    }
    else 
      { printField("", { "Object", " not found...."}); }  
  }
}
