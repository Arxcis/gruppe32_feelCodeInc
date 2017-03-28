#include "array.h"

template<typename T>
dat::array<T>::array(size_t arr_sizeLimit)
{ limit = arr_sizeLimit; }

template<typename T>
size_t dat::array<T>::Count()
{ return count_; }

template<typename T>
inline T const & dat::array<T>::operator[](int x) const
{ return const values[x]; }

template<typename T>
bool dat::array<T>::Add(T item)
{
    bool added = (values[count_] = item);
    if (added) { count_++; }
    return added;
}