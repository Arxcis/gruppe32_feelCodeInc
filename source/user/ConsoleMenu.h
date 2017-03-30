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

#include "../tool/typedef.h"
#include "MenuState.h"
#include "consoleForm.h"
#include "consoleObjectView.h"
#include "consoleList.h"

namespace menu 
{  
  //
  // @abstract class ConsoleMenu
  //
  class ConsoleMenu 
  {
  public:
    ConsoleMenu(){};
    virtual ~ConsoleMenu(){};
    //
    // @function view() 
    //  Different virtual functions which children might implement.
    //   Not implemented in the base class
    //
    virtual void view(dat::TransitionMap& map){}
    virtual void view(dat::TransitionMap& map, dat::Container& container){}
    virtual void view(dat::TransitionMap& map, dat::Container& container){}
    virtual void view(dat::TransitionMap& map, dat::Object& object){}
    virtual void view(dat::TransitionMap& map, dat::Field&  field){}

    //
    // @class funciton - small helper functions
    //
    constexpr inline void footer()  const;
    constexpr        void newPage() const;
    constexpr inline void header(const std::string) const;
    constexpr inline int  clamp(const int input, const int max) const;

    //
    // @class funciton bindStaticOption() menu-option
    //    1. Prints an option. Registeres
    // 
    constexpr inline void bindStaticOption(
      dat::TransitionMap& map,
      const int select, 
      const int menuPointer,
      const std::string& text) const;

    //
    // @class function bindDynamicOption()
    //    Should map user input to a dynamic object-id
    //    Dynamic - meaning that the same option might lead to different results
    //              each time the menu is shown.
    //
    inline void bindDynamicOption(
      dat::TransitionMap& map,
      const int select, 
      const int menuPointer,
      const std::string& text,
      const std::string& id) const;
  };


  class Begin : public ConsoleMenu
  {
  public:
    Begin(){};
    virtual ~Begin(){};
    virtual void view(dat::TransitionMap& map) override;
  };

  //////////////////////////////////////////////////////////////////
  //
  //  BASE MENU classes
  //
  class NationBase : public ConsoleMenu
  {
  public:
    NationBase(){};
    virtual ~NationBase(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;
  };


  class ParticipantBase : public ConsoleMenu
  {
  public:
    ParticipantBase(){};
    virtual ~ParticipantBase(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;
  };


  class SportBase : public ConsoleMenu
  {
  public:
    SportBase(){};
    virtual ~SportBase(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;
  };

  //////////////////////////////////////////////////////////////////
  //
  //  STATS 
  //
  class PointStats : public ConsoleMenu
  {
  public:
    PointStats(){};
    virtual ~PointStats(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;
  };


  class MedalStats : public ConsoleMenu
  {
  public:
    MedalStats(){};
    virtual ~MedalStats(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;
  };

 

  //////////////////////////////////////////////////////////////////
  //
  // OBJECT MENU classes
  //
  class Nation : public ConsoleMenu
  {
  public:
    Nation(){};
    virtual ~Nation(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };

  class Participant : public ConsoleMenu
  {
  public:
    Participant(){};
    virtual ~Participant(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };

  class Sport : public ConsoleMenu
  {
  public:
    Sport(){};
    virtual ~Sport(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };

  class Dicipline : public ConsoleMenu
  {
  public:
    Dicipline(){};
    virtual ~Dicipline(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };



  //////////////////////////////////////////////////////////////////
  //
  //  NEW MENU classes
  //

  class NewObject : public ConsoleMenu
  {
  public:
    NewObject(const std::string& type);
    virtual ~NewObject(){}
    virtual void view(dat::TransitionMap& map) override;
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
    EditField(){};
    virtual ~EditField(){}
    virtual void view(dat::TransitionMap& map, dat::Field& object) override;
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
