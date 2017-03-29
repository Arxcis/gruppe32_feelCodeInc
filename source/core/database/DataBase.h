#pragma once

#include "../ListTool2B.h"
#include "../../tool/typedef.h"

class DataBase
{
protected:
  List* elements = new List(Sorted);

public:
  DataBase();
  virtual ~DataBase();
  void display(); 
  //bool find(dat::Object ID);

  //bool add(T* obj);
  virtual bool add(dat::Object* object)=0;

  //T* operator[] (dat::Object ID); //instead of get(...)?
  //T* get(dat::Object ID);
  //T* pop(dat::Object ID);
  //bool delete(dat::Object ID);
  //virtual displayMenu() = 0 -> void;
  //virtual readFile(std::string filePath) = 0 -> void;
  //virtual writeFile(std::string filePath) = 0 -> void;

};
