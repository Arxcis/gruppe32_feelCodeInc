#pragma once

// @file    core/Nation.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Nation is stored within, shortName is PK
//

#include <string>
#include "../tool/char3.h"
#include "ListTool2B.h"


class Nation : TextElement
{
private:
	char3 shortName_;			//Primary key
	std::string name_;			//the full name
	//Contact contact_ @TODO	//the contact guy for this nation
	int participantCount_;		//how many are registered for this nation

public:
	//	GETTERS

	char3 getShortName();
	auto getName();
	//Contact getContact();
	int getParticipantCount();
};