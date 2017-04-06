#pragma once

#include "DataBase.h"
#include "../Sport.h"

namespace db
{
  class SportBase : public DataBase<Sport>
  {
  public:
    SportBase()
    :DataBase(sportsFile)
    ,sports(elements)
      { readContainer(); }

    virtual ~SportBase(){}
    virtual auto pack  (const Sport*      object) -> dat::Object override;
    virtual auto unpack(const dat::Object& object) -> Sport*      override;

    bool removeDicipline(const std::string & fullID);

    bool readStarts  (dat::Container& starts,  const std::string& diciplineID);
    bool readResults (dat::Container& results, const std::string& diciplineID);

    void writeStarts (const std::string& diciplineID, const dat::Container& starts);
    void writeResults(const std::string& diciplineID, const dat::Container& results );

    bool createFilesIfNotExist(const std::string& id);

  private:
    virtual auto readFile(const std::string& filepath) -> dat::Container override;
    List* sports;
  };
}

