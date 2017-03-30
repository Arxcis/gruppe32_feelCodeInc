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
#include "../enum.h"
#include "consoleForm.h"

namespace menu 
{  

  ////////////////////////////////////////////////////////////////
  //
  //  @base class menu::ConsoleMenu
  //
  class ConsoleMenu 
  {
  public:
    ConsoleMenu(const std::string type, const std::vector<int> nextState);
    virtual ~ConsoleMenu(){};
    //
    // @function view() 
    //  Different virtual functions which children might implement.
    //   Not implemented in the base class
    //
    virtual void view(){};
    virtual void view(dat::TransitionMap& map){}
    virtual void view(dat::TransitionMap& map, dat::Container& container){}
    virtual void view(dat::TransitionMap& map, dat::Object& object){}
    virtual void view(dat::TransitionMap& map, dat::Field&  field){}

    //
    // @class funciton - small helper functions
    //
           void newPage() const;
    inline void footer()  const;
    inline void header(const std::string) const;
    

    //
    // @class funciton bindStaticOption() menu-option
    //    1. Prints an option. Registeres
    // 
    inline void bindStaticOption(
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
      const std::string& id, 
      const std::string& text) const;

    //
    // @class function immutableOption
    //
    inline void illegalOption(
      const std::string& text) const;

    protected:
      const std::string type_;
      const std::vector<int> nextState_;
  };


  //////////////////////////////////////////////////////////////////
  //
  //  @class menu::Start
  //
  class Start : public ConsoleMenu
  {
  public:
    Start(const std::string type, const std::vector<int> nextState);
    virtual ~Start(){};
    virtual void view(dat::TransitionMap& map) override;
  };


  //////////////////////////////////////////////////////////////////
  //
  //  @class menu::Base
  //
  class Base : public ConsoleMenu
  {
  public:
    Base(const std::string type, const std::vector<int> nextState);
    virtual ~Base(){}
    virtual void view(dat::TransitionMap& map, dat::Container& container) override;

  };


  //////////////////////////////////////////////////////////////////
  //
  //  @class menu::Stats
  //
  class Stats : public ConsoleMenu
  {
  public:
    Stats(const std::string type, const std::vector<int> nextState);
    virtual ~Stats(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };
 

  //////////////////////////////////////////////////////////////////
  //
  // @class menu::Object
  //
  class NationMenu : public ConsoleMenu
  {
  public:
    NationMenu(const std::string type, const std::vector<int> nextState);
    virtual ~NationMenu(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };

  //////////////////////////////////////////////////////////////////
  //
  // @class menu::Object
  //
  class ParticipantMenu: public ConsoleMenu
  {
  public:
    ParticipantMenu(const std::string type, const std::vector<int> nextState);
    virtual ~ParticipantMenu(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };

  //////////////////////////////////////////////////////////////////
  //
  // @class menu::Object
  //
  class SportMenu : public ConsoleMenu
  {
  public:
    SportMenu(const std::string type, const std::vector<int> nextState);
    virtual ~SportMenu(){}
    virtual void view(dat::TransitionMap& map, dat::Object& object) override;
  };


  //////////////////////////////////////////////////////////////////
  //
  //  NEW MENU classes
  //
  class NewObject : public ConsoleMenu
  {
  public:
    NewObject(const std::string type, const std::vector<int> nextState);
    virtual ~NewObject(){}
    virtual void view(dat::TransitionMap& map, dat::Object& newObject) override;
  };


  //////////////////////////////////////////////////////////////////
  //
  //  EDIT MENU classes
  //
  class EditField : public ConsoleMenu
  {
  public:
    EditField(const std::string type, const std::vector<int> nextState);
    virtual ~EditField(){}
    virtual void view(dat::TransitionMap& map, dat::Field& field) override;
  };

  /////////////////////////////////////////////////////////////////
  //
  //  @class menu::Error
  //
  class Error : public ConsoleMenu
  {
  public:
    Error(const std::string type, const std::vector<int> nextState);
    virtual ~Error(){}
    virtual void view() override;
  };
}
