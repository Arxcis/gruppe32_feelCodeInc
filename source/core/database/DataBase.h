#pragma once

#include "../../enum.h"             // Unsure if this include is needed
#include "../../config.h"           // Filepaths
#include "../../tool/typedef.h"
#include "../../tool/stream.h"
#include "../../tool/packer.h"
#include "../../tool/unpacker.h"
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
    virtual dat::Object    pack(const T*     object) = 0;
    virtual T*             unpack(const dat::Object& object) = 0;
    virtual dat::Container readFile(const std::string& filepath) = 0;

    bool findID(const std::string& id)
    { return elements->inList(id.c_str()); }

    bool findID(const int id)
    { return elements->inList(id); }

    bool getID(dat::Object& object, const std::string& id)
    {
      T* e = (T*)elements->remove(id.c_str());
      if (e)
      {
        object = pack(e);     // e should not change here
        elements->add(e);
      }
      return e != nullptr;
    }

    bool getID(dat::Object& object, const int id)
    {
      T* e = (T*)elements->remove(id);
      if (e)
      {
        object = pack(e);     // e should not change here
        elements->add(e);
      }
      return e != nullptr;
    }

    bool updateID(const dat::Object& object)
    {
      T* e = (T*)elements->remove(object[1].second.c_str());
      if (e) //object[1] is PK
      { elements->add(unpack(object)); }
      return e != nullptr;
    }

    //
    // @class function update with string id
    //  @brief updating by removing existing object, and replacing by updated one.
    //
    bool update(const std::string& id, const dat::Object& object)
    {
      if (findID(id))
      { 
        elements->destroy(id.c_str());
        T* e = unpack(object);
        elements->add(e);
        return true;
      }
      else
        { return false; }
    }

    //
    // @class function update with string id
    //  @brief updating by removing existing object, and replacing by updated one.
    //
    bool update(const int id, const dat::Object& object)
    {
      if (findID(id))
      {
        elements->destroy(id);
        T* e = unpack(object);
        elements->add(e);
        return true;
      }
      else
        { return false; }
    }  
      

    //
    // @class function add
    //
    virtual bool add(const dat::Object& object)
    {
      T* unpackedObject = unpack(object);
      if (elements->add(unpackedObject)) //if added
        { return true; }
      else
        { return false; }
    }

    //
    // @class function display
    //
    void display()
    {
      printf("\n\n==============================");
      printf("\n           DATABASE           ");
      printf("\n==============================");
      return elements->displayList();
    }

    //
    // @class funciton db::DataBase::readContainer
    //  @brief returns a container of all points in file
    //
    auto readContainer() -> const dat::Container
    { return readFile(baseFile); }

    //
    // @class funciton db::DataBase::getContainer
    //  @brief returns a container of all points in base
    //
    auto getContainer() -> const dat::Container
    { 
      dat::Container container;
      T* e;
      int i = 0;
      while((e = (T*)elements->removeNo(0)))// Sorry men den nydelige for-loopen her funka ikkje hos meg --> for (int i = 0; elements->noOfElements(); i++)
        { container.push_back(pack(e)); }

      for (auto& obj: container)
        { elements->add(unpack(obj)); }
      return container;
    }

    // 
    // @funciton // Only implemented in base class
    //
    void writeFile(const std::string& filepath, const dat::Container& container)
    {
      std::cout << "Writing to " << filepath << "\n";  // @debug
      std::ofstream outFile(filepath + "_out");

      outFile << container.size() << ";\n";
      assert(outFile);

      for (const auto& object : container)
      {
        for (const auto& field : object)
        {
          outFile << field.second << ";\n";
        }
      }
      outFile.close();
    }
  };
}
