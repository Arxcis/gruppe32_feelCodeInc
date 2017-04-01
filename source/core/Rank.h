#pragma once

#include "ListTool2B.h"
#include "../tool/char3.h"

class Rank : public NumElement
{
private:
    dat::char3 nation_;
    int value;
};