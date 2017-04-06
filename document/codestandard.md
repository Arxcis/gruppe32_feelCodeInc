[TOC]

#### 1. [TBD]File/folder names are lower_case with underscore as separators
```bash
nasjons_base.h
nasjons_base.cpp
main.cpp
build/
...
```

#### 2. [TBD]Variable names
```cpp
// Local Variable - Camelcase
int helloWorld;
Timestamp sixClock = { 06, 00, 00 };
const localConst = 1000;

// Global constants - static variables in a global struct
struct Const
{
    static const nameLength = 100;
    static const numberOfCountries = 196;
}
char name[Const.nameLength];

// Enums all caps
enum Days
{
    MONDAY,
    TUESDAY,
    FRIDAY,
};
```

#### 3. Curcly brackets on new line, always

```cpp
for (int i = 0; i < 20; ++i)
{
    // Do some fancy stuff
}
```

Alternative for one-liners
```cpp
for (int i = 0; i < 20; ++i)
{  /* Do some fancy stuff */ }
```

#### 4. [TBD]Space between control statements and expression
```cpp
for (ever)
{ /* loop */ }

if (2 < 3)
{ /* if and only if */ }

while (true)
{  /* just do it */ }
```

#### 5. [TBD]File headings follows this format
```cpp
//
//  @file    main.cpp
//  @brief   : entry point of the program
//  @creator : Jonas
//  @team    : gruppe32
//  @date    : 11.03.17
//
```
[Doxygen @reference](http://www.stack.nl/~dimitri/doxygen/)

#### 6. [TBD]Function headings follows this format
```cpp
//
//  @function square
//  @brief  : Squares an int and returns it as float
//  @param  : int num - integer to be squared
//  @return : float   - result of squaring
//
float square(int num)
{ return (num*num); }
```
