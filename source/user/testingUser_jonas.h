#pragma once
//
// @file    user/testingUser_jonas.h
// @repo    gruppe32
// @created 23.03.17 by Jonas
// @brief   Main hub of the user-module. Used for testing
//          components of the user-module.
//


// @TODO - This cannot be reliably run anymore. change it to header only file

#include <stdio.h>

// @local files
//#include "Console.h"
void testFormField()
{   
    dat::Field phone_     = {"Phone",""};
    dat::Field sex_       = {"Sex",""};
    dat::Field scoreType_ = {"ScoreType",""};
    dat::Field date_   = {"StartDate",   ""};
    dat::Field time1_  = {"ContactTime", ""};
    dat::Field time2_  = {"TimeFinal",   ""};
    dat::Field email1_ = {"Email",      ""};
    dat::Field email2_ = {"UserEmail",  ""};
    
    form::field(phone_);
    form::field(sex_);
    form::field(scoreType_);
    form::field(date_);
    form::field(time1_);
    form::field(time2_);
    
    form::field(email1_);
    form::field(email2_);

}

void testUser()
{
  testFormField();
  
  // Console console;
  //  console.run();
}



