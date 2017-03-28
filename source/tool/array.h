#pragma once

// @file    core/Participant.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   A collection type with minor improvements,
//			mainly being the inclusion of a count member.

#include <stddef.h>

namespace dat
{
    template<typename T>
    struct array
    {
    private:
        size_t count_;
        T values[];
    public:
        array(size_t arr_sizeLimit);
        const size_t limit;
        size_t Count();
        inline T& operator[] (int x) const;
        bool Add(T item);
    };
}
