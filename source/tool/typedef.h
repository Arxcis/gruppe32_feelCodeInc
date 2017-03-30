#pragma once
//
// @file    tool/typedef.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   All typedefs. Contains many of the most important data-transmitting objects in the
//            program - dat::Container, dat::Object, dat::Field
//

#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>

namespace dat
{   
    //
    // @typedef dat::GenericField and dat::GenericContainer - Used to build up more specialized
    //               containers and fields.
    // 
    template<typename T, typename U>
    using GenericField = std::pair<T, U>;      // a key/value-pair of key-type T and value-type U

    template<typename T>
    using GenericContainer = std::vector<T>;   // A variable length array(vector) of types.

    //
    // @typedef(using) dat::Field is used throughout the code as a key-value pair of strings.
    //           All fields in all objects are evntually passed around as a collection of dat::Fields.
    //    
    using Field = GenericField<std::string, std::string>;


    //
    // @typedef(using) dat::Object - Used as a generic way of transmitting data about objects throughout
    //                         the code. For instance, Nation, PArticipant,
    //                         To see the format of how these objects should be built up, see 
    //                         data/testData.h and data/*.format -files.
    //                         Does only hold basic data of std::string type. 
    //    
    using Object = GenericContainer<Field>; 

    //
    // @typedef(using) dat::Container - Used when we want to transmit a collection of object which are of 
    //                            the same type. Does only hold basic data of std::string type.
    //    
    using Container = GenericContainer<Object>; 

    //
    // @typedef dat::transitionMap - A map can be used to store information about different states in a program
    //     
    using TransitionMap = std::unordered_map<int, std::pair<int, std::string>>;
}
