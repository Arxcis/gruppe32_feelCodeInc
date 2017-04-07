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
    const std::string baseFile;
    bool  dirty_ = false;                // flag that indicates to others that something has been changed
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

    bool isDirty() 
    { return dirty_; }

    void setDirty(bool d) 
    { dirty_ = d; }

    bool findSortID(const std::string& id)
    { return elements->inList(id.c_str()); }

    bool findSortID(const int id)
    { return elements->inList(id); }

    bool getSortID(dat::Object& object, const std::string& id)
    {
      T* e = (T*)elements->remove(id.c_str());
      if (e)
      {
        object = pack(e);     // e should not change here
        elements->add(e);
      }
      return e != nullptr;
    }

    bool getSortID(dat::Object& object, const int id)
    {
      T* e = (T*)elements->remove(id);
      if (e)
      {
        object = pack(e);     // e should not change here
        elements->add(e);
      }
      return e != nullptr;
    }

    size_t countMatchingFields(const dat::Field id)
    {
      size_t count = 0;
      int fieldIndex = -1;
      dat::Container objects = getContainer();
      if (objects.size() > 0)
      {
        for (size_t i = 0; i < objects[0].size() && fieldIndex < 0; i++)
        {
          if (objects[0][i].first == id.first) //if it's the field type we're looking for
          { fieldIndex = i; }
        }
        for (size_t i = 0; i < objects.size(); i++)
        {
          if(objects[i][fieldIndex].second == id.second)
          { count++; }
        }
      }
      return count;
    }

    //Very expensive compared to the getSortID
    int getWithMatchingField(dat::Object& object, const dat::Field id)
    {
      dat::Container objects = getContainer();
      if (objects.size() > 0)
      {
        assert(objects[0][0].second == object[0].second); //no typematch
        size_t fieldIndex = -1;
        for (size_t i = 0; i < object.size() && fieldIndex != i; i++)
        {
          if (object[i].first == id.first) //if it's the field type we're looking for
          { fieldIndex = i; }
        }
        assert(fieldIndex > 0); // if the objects are the same type the field should exist -> its index should too!
        for (size_t i = 0; i < objects.size(); i++)
        {
          if (objects[i][fieldIndex].second == id.second)
          { object = objects[i]; return fieldIndex; }
        }
      }
      return -1;
    }
    //send in object, and search for field an object with the matching field will 
    bool updateWithMatchingField(dat::Object& object, const dat::Field field, const int i=-1)
    {
      List removedItems(FIFO);
      size_t fieldIndex = 0;
      while (object[fieldIndex].first != field.first && fieldIndex < object.size()) //if the type does not match
      { fieldIndex++; }                                                          // try the next one
      if (i < 0)
      {
        while (T* e = (T*)elements->remove(object[1].second.c_str()))
        {
          if (pack(e)[fieldIndex].second != field.second) //Then find the actual wanted object with the matching foreign field
          {  //this is not the one we're looking for, add it in a tempList,
             //as we don't want it to stay in our current search
            removedItems.add(e);
          }
          else
          { //The matching element was found!
            //discard the one that matches and add the object instead
            dirty_ = elements->add(unpack(object));
          }
        }
      }
      else //numerical list
      {
        //since I've got to remove from list with the SORTON-value I have to filter through them all
        while (T* e = (T*)elements->remove(i))
        {
          if (pack(e)[fieldIndex].second != field.second) //Then find the actual wanted object with the matching foreign field
          {  //this is not the one we're looking for, add it in a tempList,
             //as we don't want it to stay in our current search
            removedItems.add(e);
          }
          else
          { //The matching element was found!
            //discard the one that matches and add the object instead
            dirty_ = elements->add(unpack(object));
          }
        }
      }
      while (removedItems.noOfElements() > 0)
      { elements->add(removedItems.removeNo(0)); } //dequeue everything back into elements
      return dirty_;
    }


    //
    // @class function update with string id
    //  @brief updating by removing existing object, and replacing by updated one.
    //
    bool update(const dat::Object& object)
    {
      T* e = (T*)elements->remove(object[1].second.c_str());
      if (e) //object[1] is PK
      { dirty_ = elements->add(unpack(object)); }
      return dirty_;
    }

    //
    // @class function update with string id
    //  @brief updating by removing existing object, and replacing by updated one.
    //
    bool update(const int id, const dat::Object& object)
    {
       T* e = (T*)elements->remove(id);
      if (e) //object[1] is PK
      { dirty_ = elements->add(unpack(object)); }
      return dirty_;
    }  

    //
    // @class function add
    //
    virtual bool add(const dat::Object& object)
    {
      T* unpackedObject = unpack(object);
      dirty_ = elements->add(unpackedObject);
      return dirty_; //if added
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
      while((e = (T*)elements->removeNo(0)))
        { container.push_back(pack(e)); }

      for (auto& obj: container)
        { elements->add(unpack(obj)); }
      return container;
    }


    // 
    // @funciton flush() // Only implemented in base class
    //
    void flush()
    { 
      const dat::Container flushContainer = getContainer();
      writeFile(baseFile, flushContainer); 
    }

protected:
    // 
    // @funciton            // Only implemented in base class
    //
    void writeFile(const std::string& filepath, const dat::Container& container)
    {
      std::cout << "Writing to " << filepath << "\n";  // @debug
      std::ofstream outFile(filepath);

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
