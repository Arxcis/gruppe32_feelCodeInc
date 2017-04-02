#include "packer.h"

dat::Object * dat::packing::packContact( const std::string & name_, 
                                          const std::string & phone_, 
                                          const std::string & mailAddress_)
{
  return new dat::Object
  { 
    { "Name", name_},
    { "Phone", phone_ }, 
    { "EMail", mailAddress_ }
  };
}

dat::Object * dat::packing::packTime(const Field & time_)
{
  return nullptr;
}

dat::Object * dat::packing::packDate(const Field & date_)
{
  return nullptr;
}

dat::Object * dat::packing::packMedals(const int & medals)
{
  return nullptr;
}
