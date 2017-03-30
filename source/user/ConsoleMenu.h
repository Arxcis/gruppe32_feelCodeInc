#pragma once
//
// @file    user/ConsoleMenu.h
// @repo    gruppe32
// @created 27.03.17 by Jonas
// @brief   A new take on the menu system. This new approach
//          is heavily inpired by the object-oriented way of implementing
//          the state-pattern described here --> 
//            http://gameprogrammingpatterns.com/state.html - 27.03.17 by Robert Nystrom
//   Basically, each menu-state is a class, inheriting from the abstract
//          class menu. They all have to implement their own version of 
//          view(); Also they have to point to the next menu the user 
//          should be sent to, according the what input parameter the 
//          user gives.
//          
//

#include <string>
#include <unordered_map>
#include <utility>

#include "../API.h"   // @global dependency
#include "../enum.h"
#include "consoleForm.h"
#include "consoleObjectView.h"
#include "consoleList.h"

namespace menu 
{  

  //
  // Helper functions
  //
  inline void header(std::string);
  inline void footer();
  inline void newPage();

  inline int clamp(const int input, const int max);

  //
  // @abstract class Menu
  //
  class ConsoleMenu 
  {
  public:
    ConsoleMenu(const std::vector<int> args);
    virtual ~ConsoleMenu(){};
    //
    // @function view()
    //  Views all static and dynamic content of the current menu
    //
    virtual void view()=0;

    //
    // @function getNext()
    //  The input-handler catches a relative index from the user.
    //  Usually a number mapped to the current menu. The menu maps this
    //  relative index, to an absoulute inedex to the next Menu.
    //
    virtual int getNextIndex(const int userInput);

  protected:
    //
    // @map   
    // Holds the key-indicies to the next menu
    //  Each menu should have their own unique initialization of this
    //  variable.
    std::unordered_map<int, int> mapNext_;

    static dat::Field*     selectedField;
    static dat::Object*    selectedObject;
    static dat::Object*    selectedObjectSecond;
    static dat::Container* selectedContainer;

    //
    // @static 
    //  If the user selects a specific object from a list, the object
    //  in focus gets stored here. This is a way for communication between
    //   the selection menus, and the objectView-menus
    //
    API api_;
    static int selectedObject_;  
  };


  class Begin : public ConsoleMenu
  {
  public:
    Begin(const std::vector<int> args);
    virtual ~Begin(){};
    virtual void view() override;
  };

  //////////////////////////////////////////////////////////////////
  //
  //  BASE MENU classes
  //
  class NationBase : public ConsoleMenu
  {
  public:
    NationBase(const std::vector<int> args);
    virtual ~NationBase(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };


  class ParticipantBase : public ConsoleMenu
  {
  public:
    ParticipantBase(const std::vector<int> args);
    virtual ~ParticipantBase(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };


  class SportBase : public ConsoleMenu
  {
  public:
    SportBase(const std::vector<int> args);
    virtual ~SportBase(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };

  //////////////////////////////////////////////////////////////////
  //
  //  STATS 
  //
  class PointStats : public ConsoleMenu
  {
  public:
    PointStats(const std::vector<int> args);
    virtual ~PointStats(){}
    virtual void view() override;
  };


  class MedalStats : public ConsoleMenu
  {
  public:
    MedalStats(const std::vector<int> args);
    virtual ~MedalStats(){}
    virtual void view() override;
  };

 

  //////////////////////////////////////////////////////////////////
  //
  // OBJECT MENU classes
  //
  class Nation : public ConsoleMenu
  {
  public:
    Nation(const std::vector<int> args);
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };

  class Participant : public ConsoleMenu
  {
  public:
    Participant(const std::vector<int> args);
    virtual ~Participant(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };

  class Sport : public ConsoleMenu
  {
  public:
    Sport(const std::vector<int> args);
    virtual ~Sport(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };

  class Dicipline : public ConsoleMenu
  {
  public:
    Dicipline(const std::vector<int> args);
    virtual ~Dicipline(){}
    virtual void view() override;
    virtual int getNextIndex(const int userInput) override;
  };



  //////////////////////////////////////////////////////////////////
  //
  //  NEW MENU classes
  //

  class NewObject : public ConsoleMenu
  {
  public:
    NewObject(const std::vector<int> args, const std::string type);
    virtual ~NewObject(){}
    virtual void view() override;
  private:
    const std::string type_;
  };



  //////////////////////////////////////////////////////////////////
  //
  //  EDIT MENU classes
  //

  class EditField : public ConsoleMenu
  {
  public:
    EditField(const std::vector<int> args);
    virtual ~EditField(){}
    virtual void view() override;
  };


  //////////////////////////////////////////////////////////////////
  //
  //  DELETE MENU classes
  //

/*
  class DeleteDicipline : public ConsoleMenu
  {
  public:
    DeleteDicipline(){}
    virtual ~DeleteDicipline(){}
    virtual void view() override;
  };


  class DeleteList : public ConsoleMenu
  {
  public:
    DeleteList(){}
    virtual ~DeleteList(){}
    virtual void view() override;
  };



  //////////////////////////////////////////////////////////////////
  //
  //  LIST MENU classes
  //

  class ListBase : public ConsoleMenu
  {
  public:
    ListBase(){}
    virtual ~ListBase(){}
    virtual void view() override;
  };


  class AppendList : public ConsoleMenu
  {
  public:
    AppendList(){}
    virtual ~AppendList(){}
    virtual void view() override;
  };

  class AppendResult : public ConsoleMenu
  {
  public:
    AppendResult(){}
    virtual ~AppendResult(){}
    virtual void view() override;
  };

*/

}
