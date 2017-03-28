#pragma once

#include "../../core/ListTool2B.h"
#include "../../tool/typedef.h"

template<typename T>
class DataBase
{
protected:
  List elements;

public:
  void display(); 
  //bool find(dat::Object ID);

  bool add(T* element);
  bool add(dat::Object element);

  //T* operator[] (dat::Object ID); //instead of get(...)?
  //T* get(dat::Object ID);
  //T* pop(dat::Object ID);
  //bool delete(dat::Object ID);
  //virtual displayMenu() = 0 -> void;
  //virtual readFile(std::string filePath) = 0 -> void;
  //virtual writeFile(std::string filePath) = 0 -> void;

};
