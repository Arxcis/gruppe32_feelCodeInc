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
    List* elements;                     // Container for the databases core data
    std::stringstream ss;                // Buffer for reading from files
    const std::string baseFile;
   
  public:
    DataBase(const std::string file)
    :baseFile(file)
    { elements = new List(Sorted); }

    virtual ~DataBase()
    { delete elements; }

    //
    // Virtual abstract (not-implemented) functions
    //
    virtual dat::Object pack  (T*           object)             = 0;
    virtual T*          unpack(dat::Object& object)             = 0;
    virtual dat::Container readFile(const std::string& filepath) = 0;
    

    void display()
    { return elements->displayList(); }


    bool add(dat::Object * object)
    {
      T* unpackedObject = unpack(object);
      if (elements->add(unpackedObject)) //if added
      { return true; }
      else
      { delete object; return false; }
    }

    //
    // @class funciton db::DataBase::getContainer
    //  @brief returns a container of all points in base
    //
    auto getContainer() -> const dat::Container
      { return readFile(baseFile); }


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
      { 
        for(const auto& field: object)
          { outFile << field.second << ";\n"; } 
      }

      outFile.close();
    }
  };

}
