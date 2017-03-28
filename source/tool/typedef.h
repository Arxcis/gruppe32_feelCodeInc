#pragma once
//
// @file    tool/char3.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All typedefs
//

#include <string>
#include <tuple>
#include <vector>

namespace dat
{
    //a defined char-array with space for 3 elements
    typedef struct char3 { char x[4]; } char3; 

    template<typename T, typename U>
    using GenericField = std::pair<T, U>;                 // a key/value-pair      
    using Field = GenericField<std::string, std::string>; // pair of strings

    template<typename T>
    using GenericContainer = std::vector<T>; //lists all fields
    using Object = GenericContainer<Field>;  //lists all fields as strings

    using Container = GenericContainer<Object>; //holds a list of all objects

}
