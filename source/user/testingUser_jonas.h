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
    
    form::thisField(phone_);
    form::thisField(sex_);
    form::thisField(scoreType_);
    form::thisField(date_);
    form::thisField(time1_);
    form::thisField(time2_);
    
    form::thisField(email1_);
    form::thisField(email2_);

}

void testUser()
{
  testFormField();
  
  // Console console;
  //  console.run();
}



