#pragma once

// @file    core/Participant.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All data relevant to a Participant is stored within.

#include "ListTool2B.h"
#include "../tool/Contact.h"
#include "../tool/char3.h"

class Participant : NumElement
{
private:
	int ID_;
	Contact contact_;
	char3 nation_;
	//Gender gender;
public:
	int getID();
	Contact getContact();
	char3 getNation();
	//Gender getGender();
};