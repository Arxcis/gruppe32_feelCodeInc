#pragma once
//
// @file    tool/Measure.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   Measure Virtual struct or inteface struct, 
//           for children Medals, Time, Date
//

namespace dat 
{
  struct Measure 
  { 
    Measure();
    virtual ~Measure();
    virtual void display()=0;
    virtual int castToInt()=0;
  
    bool operator <  (Measure* other);
    bool operator >  (Measure* other);
    bool operator <= (Measure* other);
    bool operator >= (Measure* other);
    bool operator == (Measure* other);
  };
}