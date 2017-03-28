#pragma once

// @file    core/Participant.h
// @repo    gruppe32
// @created 24.03.17 by Halvor
// @brief   A collection type with minor improvements,
//			mainly being the inclusion of a length member.

#include <stddef.h>

namespace dat
{
	template<typename T, size_t arr_size>
	struct array
	{
	private:
		size_t count_;
    T values[arr_size];
	public:
		const size_t length = arr_size;
		size_t Count();
		inline T& operator[] (int x);
	};
}
