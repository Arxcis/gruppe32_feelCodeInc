#include "DataBase.h"

template<typename T>
inline void DataBase<T>::display()
{ return elements.displayList(); }

template<typename T>
inline bool DataBase<T>::add(T * element)
{ return elements.add(element); }


