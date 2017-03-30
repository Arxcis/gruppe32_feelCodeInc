#pragma once

// @file    core/Nation.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Nation are stored within, shortName is PK
//

#include <string>
#include "../tool/char3.h"
#include "../tool/Contact.h"
#include "ListTool2B.h"



class Nation : public TextElement
{
private:
	dat::char3 shortName_;	  //Primary key
	std::string name_;	      //the full name
  dat::Contact contact_;    //the contact guy for this nation
	int participantCount_;		//how many are registered for this nation

public:

  Nation(dat::char3 shortName, std::string name, dat::Contact contact, int participantCount);
  ~Nation();

	//	GETTERS
	auto getShortName() -> dat::char3;
	auto getName() -> std::string;
	auto getContact() -> dat::Contact;
	int getParticipantCount();
};