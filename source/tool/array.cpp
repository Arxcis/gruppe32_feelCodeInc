#include "array.h"

template<typename T, size_t arr_size>
size_t dat::array<T, arr_size>::Count()
{
	return count_;
}
