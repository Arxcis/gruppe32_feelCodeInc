#pragma once

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
    ~DataBase()
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

    virtual void readFile(const std::string filepath)=0;
  };

}
