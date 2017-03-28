#include "array.h"

template<typename T, size_t arr_size>
size_t dat::array<T, arr_size>::Count()
{
	return count_;
}

template<typename T, size_t arr_size>
inline T & dat::array<T, arr_size>::operator[](int x)
{ return values[x]; }
