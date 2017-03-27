#pragma once
//
// @file    user/consoleMenu.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   Has namespace menu, which produces the graphical
//          representation of all the menus in the console
//          application.
//

#include <iostream>   // stringstream
#include <string>

#include "MenuState.h"
#include "consoleMenu.h"
//
// @namespace menu
// @brief One important thing to note about these functions is that
//        , every function returns a choice/command, from the user.
//        This command chould be processed by the Console object.
//
namespace menu
{  

  // Menu functions
  int begin_();
  
  int nationBase_();
  int participantBase_();
  int sportBase_();
  int listBase_();

  int pointStats_();
  int medalStats_();

  int sport_();
  int nation_();
  int participant_();
  int dicipline_();

  int deleteDicipline_();
  int deleteList_();
}

namespace menu 
{ 
  //
  // Helper functions
  //
  inline void header(std::string);
  inline void footer();
  inline void newPage();

  //
  // @abstract class Menu
  //
  class Menu 
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


  class Begin : public Menu
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
  class NationBase : public Menu
  {
  public:
    NationBase(){}
    virtual ~NationBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class ParticipantBase : public Menu
  {
  public:
    ParticipantBase(){}
    virtual ~ParticipantBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class SportBase : public Menu
  {
  public:
    SportBase(){}
    virtual ~SportBase(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class ListBase : public Menu
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



  class Nation : public Menu
  {
  public:
    Nation(){}
    virtual ~Nation(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class Participant : public Menu
  {
  public:
    Participant(){}
    virtual ~Participant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class Sport : public Menu
  {
  public:
    Sport(){}
    virtual ~Sport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class Dicipline : public Menu
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



  class NewNation : public Menu
  {
  public:
    NewNation(){}
    virtual ~NewNation(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class NewParticpant : public Menu
  {
  public:
    NewParticpant(){}
    virtual ~NewParticpant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class NewSport : public Menu
  {
  public:
    NewSport(){}
    virtual ~NewSport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class NewDicipline : public Menu
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

  class EditNation : public Menu
  {
  public:
    EditNation(){}
    virtual ~EditNation(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class EditParticipant : public Menu
  {
  public:
    EditParticipant(){}
    virtual ~EditParticipant(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class EditSport : public Menu
  {
  public:
    EditSport(){}
    virtual ~EditSport(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class EditDicipline : public Menu
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


  class DeleteDicipline : public Menu
  {
  public:
    DeleteDicipline(){}
    virtual ~DeleteDicipline(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class DeleteList : public Menu
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

  class AppendList : public Menu
  {
  public:
    AppendList(){}
    virtual ~AppendList(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };

  class AppendResult : public Menu
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

  class PointStats : public Menu
  {
  public:
    PointStats(){}
    virtual ~PointStats(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };


  class MedalStats : public Menu
  {
  public:
    MedalStats(){}
    virtual ~MedalStats(){}
    virtual void view() override;
    virtual int getNext(int userInput) override;
  };
}