#pragma once

#include "../../tool/typedef.h"
#include "../Nation.h"
namespace db
{
  template<class T>
  class DataBase
  {
  protected: 
    List * elements;
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
  };

}
