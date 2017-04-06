#include "SportBase.h"


namespace db 
{
  //
  // @class function pack()
  //
  auto SportBase::pack(const Sport* sport) -> dat::Object
  {
    auto sportProto = dat::Object
    {
      { "Type",         "Sport" },  // Sport
      { "Name",         sport->getName()      },  // PK
      { "ScoreType",    sport->getScoreType() },
      {"#Diciplines",   ""},
    };

    std::vector<Dicipline> diciplines = sport->getDiciplines();
    sportProto[3].second = std::to_string(diciplines.size());   // Setting number of diciplines
    
    for (int i=0; i < diciplines.size(); i++)
    { 
      std::string it = std::to_string(i);
      sportProto.push_back( { "Name" + it, diciplines[i].name } );
      sportProto.push_back( { "Time"      + it, dat::packing::packTime(diciplines[i].time ) });
      sportProto.push_back( { "Date"      + it, dat::packing::packDate(diciplines[i].date ) });
    }

    return sportProto;
  }

  //
  // @class function unpack()
  //
  auto SportBase::unpack(const dat::Object& sport) -> Sport*
  {
    std::string name = sport[1].second;                        // Sport name
    std::string scoreType = sport[2].second;                   // Sport scoreType
    Sport* protoSport = new Sport(name, scoreType);             // new Sport element

    int numberOfDiciplines = std::stoi(sport[3].second);               // number of diciplines

    for (auto j = 4, i = 0; j < (4 + numberOfDiciplines * 3); j += 3, i++ )
    { 
      std::string dname = sport[j].second;                           // { Dicipline+i, id   }
      dat::Time   dtime = dat::packing::unpackTime( (sport[j+1]) );  // { Dicipline+i, time }
      dat::Date   ddate = dat::packing::unpackDate( (sport[j+2]) );  // { Dicipline+i, date }

      // Logic for adding a new dicipline to existing sport sport.
      Dicipline newDicipline{ dname, dtime, ddate }; 
      protoSport->addDicipline( newDicipline );
      createFilesIfNotExist(sport[j].second);
    }

    return protoSport;
  }

  bool SportBase::removeDicipline(const std::string& fullID )
  {
    const std::string sportID = fullID.substr(0, (fullID.find("_")));
 
    bool removed = false;
    if (Sport* sport = (Sport*)sports->remove(sportID.c_str()))
    { removed = sport->removeDicipline(fullID); sports->add(sport); }
    return removed;
  }


  //
  // @class function createFileIfNotExits()
  //
  bool SportBase::createFilesIfNotExist(const std::string& id)
  {
    const std::string staPath = diciplinePath + id + ".sta";
    const std::string resPath = diciplinePath + id + ".res";
    auto insta = std::ifstream{ staPath };

    if (!insta)
    {
      insta.close();
      auto outsta = std::ofstream{ staPath };
      auto outres = std::ofstream{ resPath };
      if (outsta && outres)
      {
        outsta << "0;";
        outres << "0;";
        std::cout << "\n" << staPath << "  created.....";
        std::cout << "\n" << resPath << "  created.....";
        outsta.close();
        outres.close();
      }
      else
      {
        outsta.close();
        outres.close();
        assert(false);
      }
      return true;
    }
    insta.close();
    return false;
  }

  //
  // @class funciton readFile()
  //    Used to fill the database with data;
  //
  auto SportBase::readFile(const std::string& filepath) -> dat::Container
  {
    std::stringstream ss;
    auto tempContainer = dat::Container{}; // @delete @temp @testing

    const auto prototype = dat::Object
    {
      {"Type",         ""},  // Sport
      {"Name",         ""},  // PK
      {"ScoreType",    ""},
      {"#Diciplines",  ""}
    };

    stream::loadFile(ss, filepath);

    // Reading number of objects.
    auto objectCount = std::string{};
    assert(stream::readInt(objectCount, ss, ';'));

    size_t protoSize = prototype.size();
    const size_t diciplineSize = 3;
      // Loop through all objects
    for (auto i=0; i < std::stoi(objectCount); i++)
    {
      auto thisProto = prototype;
      std::cout << "Sport " << i+1 << " of " << objectCount << "\n";

      assert(stream::readName (thisProto[0].second, ss, ';'));
      assert(stream::readName (thisProto[1].second, ss, ';'));
      assert(stream::readEnum   (thisProto[2].second, ss, {"Point", "Time"}, ';'));
      assert(stream::readInt    (thisProto[3].second, ss, ';'));

      int numberOfDiciplines = std::stoi(thisProto[3].second);
      
      for (size_t j = protoSize, i = 0; j < (protoSize + numberOfDiciplines * diciplineSize); j += diciplineSize, i++)
      {   
        std::string it = std::to_string(i);
        thisProto.push_back({ "Name" + it, "" });
        thisProto.push_back({ "Time" + it, "" });
        thisProto.push_back({ "Date" + it, "" });

        assert(stream::readDiciplineID(thisProto[j].second  , ss, ';'));
        assert(stream::readTime       (thisProto[j+1].second, ss, ';'));
        assert(stream::readDate       (thisProto[j+2].second, ss, ';'));
        //std::cout << thisProto[j].second << std::endl;  // @debug
      }

      add(thisProto);                       // Add to internal list
      tempContainer.push_back(thisProto);   // Add to optional return container
    } 
    return tempContainer;
  }

  bool SportBase::readStarts  (dat::Container& starts,  const std::string& diciplineID)
  { 
    std::stringstream ss;
    const auto protoObj = dat::Object
    {
      { "Type",    "Start" },
      { "ID",           "" },
      { "StartNR",      "" },
    };
    std::string path = diciplinePath + diciplineID + ".sta";

    stream::loadFile(ss, path);

    // Reading number of objects.
    auto objectCount = std::string{};
    assert(stream::readInt(objectCount, ss, ';'));
    if (std::stoi(objectCount) < 1) //if no starts are registered
    { return false; }
    for (size_t i = 0; i < std::stoi(objectCount); i++)
    {
      auto tempObj = protoObj;
      for (size_t j = 0; j < protoObj.size(); j++)
      { assert(stream::readName(tempObj[j].second, ss, ';')); }
      starts.push_back(tempObj);
    }
    return true; 
  }

  bool SportBase::readResults (dat::Container& results, const std::string& diciplineID)
  {
    std::stringstream ss;
    // @commenting this out because 
     // Here I have to find out the ScoreType for the selected Sport 
    const std::string sportID = diciplineID.substr(0, (diciplineID.find("_")));
    Sport* selectedSport = (Sport*)sports->remove(sportID.c_str());
    assert(selectedSport);                              // List tool does not have the sport requested!
    const std::string scoreType = selectedSport->getScoreType();
    assert(scoreType == "Time" || scoreType == "Point"); // Has to be an enum of these two values
    sports->add(selectedSport);

    const auto protoObj = dat::Object
    {
      { "Type",    "Result" },
      { "ID",      ""       },
      { scoreType, ""       },
    };
    std::string path = diciplinePath + diciplineID + ".res";

    stream::loadFile(ss, path);

    // Reading number of objects.
    auto objectCount = std::string{};
    assert(stream::readInt(objectCount, ss, ';'));
    if (std::stoi(objectCount) < 1) //if no starts are registered
    {
      return false;
    }
    for (size_t i = 0; i < std::stoi(objectCount); i++)
    {
      auto tempObj = protoObj;
      for (size_t j = 0; j < protoObj.size(); j++)
        { assert(stream::readName(tempObj[j].second, ss, ';')); }
      
      results.push_back(tempObj);
    }
    return true; 
  }

  void SportBase::writeStarts (const std::string& diciplineID, const dat::Container& container)
  { writeFile(diciplinePath + diciplineID + ".sta", container); }

  void SportBase::writeResults(const std::string& diciplineID, const dat::Container& container)
  { writeFile(diciplinePath + diciplineID + ".res", container); }
}

