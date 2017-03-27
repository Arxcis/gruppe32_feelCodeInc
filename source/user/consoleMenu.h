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

#include "consoleForm.h"
#include "consoleObjectView.h"
#include "consoleList.h"
#include "consoleMenu_old.h"

namespace menu 
{  

  //
  // @abstract class Menu
  //
  class ConsoleMenu 
  {
  public:
    ConsoleMenu(){};
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
    virtual int getNext(int userInput);

  private:
    //
    // @map   
    // Holds the key-indicies to the next menu
    //  Each menu should have their own unique initialization of this
    //  variable.
    std::unordered_map<int, int> mapNext_;

    //
    // @static 
    //  If the user selects a specific object from a list, the object
    //  in focus gets stored here. This is a way for communication between
    //   the selection menus, and the objectView-menus
    //
    static int selectedObject;  
  };


  class Begin : public ConsoleMenu
  {
  public:
    Begin(){};
    virtual ~Begin(){};
    virtual void view() override;
  };

  /*//---------//---------//---------//---------//---------//---------//
  //
  //  BASE MENU classes
  //
  class NationBase : public ConsoleMenu
  {
  public:
    NationBase(){}
    virtual ~NationBase(){}
    virtual void view() override;
  };


  class ParticipantBase : public ConsoleMenu
  {
  public:
    ParticipantBase(){}
    virtual ~ParticipantBase(){}
    virtual void view() override;
  };


  class SportBase : public ConsoleMenu
  {
  public:
    SportBase(){}
    virtual ~SportBase(){}
    virtual void view() override;
  };


  class ListBase : public ConsoleMenu
  {
  public:
    ListBase(){}
    virtual ~ListBase(){}
    virtual void view() override;
  };
 

  //---------//---------//---------//---------//---------//---------//
  //
  // OBJECT MENU classes
  //

  class Nation : public ConsoleMenu
  {
  public:
    Nation(){}
    virtual ~Nation(){}
    virtual void view() override;
  };


  class Participant : public ConsoleMenu
  {
  public:
    Participant(){}
    virtual ~Participant(){}
    virtual void view() override;
  };

  class Sport : public ConsoleMenu
  {
  public:
    Sport(){}
    virtual ~Sport(){}
    virtual void view() override;
  };

  class Dicipline : public ConsoleMenu
  {
  public:
    Dicipline(){}
    virtual ~Dicipline(){}
    virtual void view() override;
  };

  //---------//---------//---------//---------//---------//---------//
  //
  //  NEW MENU classes
  //



  class NewNation : public ConsoleMenu
  {
  public:
    NewNation(){}
    virtual ~NewNation(){}
    virtual void view() override;
  };


  class NewParticpant : public ConsoleMenu
  {
  public:
    NewParticpant(){}
    virtual ~NewParticpant(){}
    virtual void view() override;
  };

  class NewSport : public ConsoleMenu
  {
  public:
    NewSport(){}
    virtual ~NewSport(){}
    virtual void view() override;
  };

  class NewDicipline : public ConsoleMenu
  {
  public:
    NewDicipline(){}
    virtual ~NewDicipline(){}
    virtual void view() override;
  };



  //---------//---------//---------//---------//---------//---------//
  //
  //  EDIT MENU classes
  //

  class EditNation : public ConsoleMenu
  {
  public:
    EditNation(){}
    virtual ~EditNation(){}
    virtual void view() override;
  };


  class EditParticipant : public ConsoleMenu
  {
  public:
    EditParticipant(){}
    virtual ~EditParticipant(){}
    virtual void view() override;
  };

  class EditSport : public ConsoleMenu
  {
  public:
    EditSport(){}
    virtual ~EditSport(){}
    virtual void view() override;
  };

  class EditDicipline : public ConsoleMenu
  {
  public:
    EditDicipline(){}
    virtual ~EditDicipline(){}
    virtual void view() override;
  };

  //---------//---------//---------//---------//---------//---------//
  //
  //  DELETE MENU classes
  //


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


  //---------//---------//---------//---------//---------//---------//
  //
  //  APPEND TO LIST MENU classes
  //

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


  //---------//---------//---------//---------//---------//---------//
  //
  //  STATS AND DELETE menu classes
  //

  class PointStats : public ConsoleMenu
  {
  public:
    PointStats(){}
    virtual ~PointStats(){}
    virtual void view() override;
  };


  class MedalStats : public ConsoleMenu
  {
  public:
    MedalStats(){}
    virtual ~MedalStats(){}
    virtual void view() override;
  };*/
}