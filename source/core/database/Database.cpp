#include "DataBase.h"

template<typename T>
void DataBase<T>::display()
{ return elements.displayList(); }

template<typename T>
bool DataBase<T>::add(dat::Object * object)
{
  T unpackedObject = *unpack(object);
  if (elements.add(unpackedObject))//if added
  { return true; }
  else
  { delete object; return false; }
}


