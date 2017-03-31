#pragma once

#include "../../enum.h"
#include "../../tool/typedef.h"
#include "../../tool/stream.h"
#include "../Nation.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include <iostream>

namespace db
{
  template<class T>
  class DataBase
  {
  protected: 
    List * elements;
    std::stringstream ss;
    
  public:
    DataBase()
    { elements = new List(Sorted); }
    virtual ~DataBase()
    { delete elements; }

    void display()
    { return elements->displayList(); }

    bool add(dat::Object * object)
    {
      T* unpackedObject = unpack(object);
      if (elements->add(unpackedObject))//if added
      { return true; }
      else
      { delete object; return false; }
    }
    virtual T * unpack(dat::Object * object) = 0;
    virtual dat::Container readFile(const std::string& filepath)=0;


    // 
    // @funciton // Only implemented in base class
    //
    void writeFile(const std::string& filepath, const dat::Container& container)
    {
      std::cout << "Writing to " << filepath << "\n";  // @debug
      std::ofstream outFile(filepath+"_out");

      outFile << container.size() << ";\n";
      assert(outFile);

      for(const auto& object: container)
      { for(const auto& field: object)
          { outFile << field.second << ";\n"; } 
      }

      outFile.close();
    }
  };

}
