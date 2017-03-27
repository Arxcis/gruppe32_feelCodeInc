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

namespace menu 
{ 
  //
  // @abstract class Menu
  //
  class ConsoleMenu 
  {
  public:
    virtual ~Menu(){}
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
    virtual int getNext(int userInput)=0;
  };


  class Begin : public ConsoleMenu
  {
  public:
    Begin(){}
    virtual ~Begin(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  //---------//---------//---------//---------//---------//---------//
  //
  //  BASE MENU classes
  //
  class NationBase : public ConsoleMenu
  {
  public:
    NationBase(){}
    virtual ~NationBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class ParticipantBase : public ConsoleMenu
  {
  public:
    ParticipantBase(){}
    virtual ~ParticipantBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class SportBase : public ConsoleMenu
  {
  public:
    SportBase(){}
    virtual ~SportBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class ListBase : public ConsoleMenu
  {
  public:
    ListBase(){}
    virtual ~ListBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };


  class Participant : public ConsoleMenu
  {
  public:
    Participant(){}
    virtual ~Participant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class Sport : public ConsoleMenu
  {
  public:
    Sport(){}
    virtual ~Sport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class Dicipline : public ConsoleMenu
  {
  public:
    Dicipline(){}
    virtual ~Dicipline(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };


  class NewParticpant : public ConsoleMenu
  {
  public:
    NewParticpant(){}
    virtual ~NewParticpant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class NewSport : public ConsoleMenu
  {
  public:
    NewSport(){}
    virtual ~NewSport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class NewDicipline : public ConsoleMenu
  {
  public:
    NewDicipline(){}
    virtual ~NewDicipline(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };


  class EditParticipant : public ConsoleMenu
  {
  public:
    EditParticipant(){}
    virtual ~EditParticipant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class EditSport : public ConsoleMenu
  {
  public:
    EditSport(){}
    virtual ~EditSport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class EditDicipline : public ConsoleMenu
  {
  public:
    EditDicipline(){}
    virtual ~EditDicipline(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };


  class DeleteList : public ConsoleMenu
  {
  public:
    DeleteList(){}
    virtual ~DeleteList(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };

  class AppendResult : public ConsoleMenu
  {
  public:
    AppendResult(){}
    virtual ~AppendResult(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
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
    virtual int getNext(int userInput) override;
  };


  class MedalStats : public ConsoleMenu
  {
  public:
    MedalStats(){}
    virtual ~MedalStats(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };
}