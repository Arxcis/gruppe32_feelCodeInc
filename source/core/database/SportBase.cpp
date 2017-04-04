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
  auto SportBase::unpack(dat::Object& object) -> Sport*
  {
    std::string name = object[1].second;                        // Sport name
    std::string scoreType = object[2].second;                   // Sport scoreType
    Sport* protoSport = new Sport(name, scoreType);             // new Sport element

    int numberOfDiciplines = std::stoi(object[3].second);               // number of diciplines

    for (auto j = 4, i = 0; j < (4 + numberOfDiciplines * 3); j += 3, i++ )
    { 

      std::string dname = object[j].second;                         // { Dicipline+i, id   }
      dat::Time   dtime = dat::packing::unpackTime( object[j+1] );  // { Dicipline+i, time }
      dat::Date   ddate = dat::packing::unpackDate( object[j+2] );  // { Dicipline+i, date }

      Dicipline newDicipline{ dname, dtime, ddate }; 
      protoSport->addDicipline( newDicipline );

      createFilesIfNotExist(object[j].second);
    }

    return protoSport;
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
    auto tempContainer = dat::Container{}; // @delete @temp @testing

    const auto prototype = dat::Object
    {
      {"Type",         ""},  // Sport
      {"Name",         ""},  // PK
      {"ScoreType",    ""},
      {"#Diciplines",  ""}
    };

    auto fileToStream  = [filepath, this]()
    { 
      auto innFile = std::ifstream { filepath };
      assert(innFile);
      std::cout << "Opening "<< filepath << "...\n";  // @debug
            
      ss << innFile.rdbuf();    // Swapping buffers
      innFile.close();
    };
    
    fileToStream();

    // Reading number of objects.
    auto objectCount = std::string{};
    stream::readInt(ss, objectCount);

    size_t protoSize = prototype.size();
    size_t diciplineSize = 3;
      // Loop through all objects
    for (auto i=0; i < std::stoi(objectCount); i++)
    {
      auto thisProto = prototype;
      std::cout << "Sport " << i+1 << " of " << objectCount << "\n";

      stream::readString (ss, thisProto[0].second);
      stream::readString (ss, thisProto[1].second);
      stream::readEnum   (ss, thisProto[2].second, {"Point", "Time"});
      stream::readInt    (ss, thisProto[3].second);

      int numberOfDiciplines = std::stoi(thisProto[3].second);
      
      for (size_t j = protoSize, i = 0; j < (protoSize + numberOfDiciplines * diciplineSize); j += diciplineSize, i++ )
      {   
        std::string it = std::to_string(i);
        thisProto.push_back({ "Name" + it, "" });
        thisProto.push_back({ "Time" + it, "" });
        thisProto.push_back({ "Date" + it, "" });

        stream::readString(ss, thisProto[j].second);
        stream::readTime  (ss, thisProto[j+1].second); 
        stream::readDate  (ss, thisProto[j+2].second); 
        //std::cout << thisProto[j].second << std::endl;  // @debug
      }

      add(thisProto);                       // Add to internal list
      tempContainer.push_back(thisProto);   // Add to optional return container
    } 
    return tempContainer;
  }

  bool SportBase::readStarts  (dat::Container& starts,  const std::string& diciplineID)
  { 
    const auto protoObj = dat::Object
    {
      { "Type",         "" },  // Start
      { "ID",           "" },
      { "StartNR",      "" },
    };
    std::string path = diciplinePath + diciplineID + ".sta";

    auto fileToStream = [path, this]()
    {
      auto innFile = std::ifstream{ path };
      assert(innFile);
      std::cout << "Opening " << path << "...\n";  // @debug
      ss.clear();
      ss << innFile.rdbuf();    // Swapping buffers
      innFile.close();
    };

    fileToStream();

    // Reading number of objects.
    auto objectCount = std::string{};
    stream::readInt(ss, objectCount);
    if (std::stoi(objectCount) < 1) //if no starts are registered
    { return false; }
    for (size_t i = 0; i < std::stoi(objectCount); i++)
    {
      auto tempObj = protoObj;
      for (size_t j = 0; j < protoObj.size(); j++)
      { stream::readString(ss, tempObj[j].second); }
      starts.push_back(tempObj);
    }
    return true; 
  }

  bool SportBase::readResults (dat::Container& results, const std::string& diciplineID)
  { 
     // Here I have to find out the ScoreType for the selected Sport 
    const std::string sportID = diciplineID.substr(0, (diciplineID.find("_")));
    Sport* selectedSport = (Sport*)elements->remove(sportID.c_str());
    assert(selectedSport);                              // List tool does not have the sport requested!
    const std::string scoreType = selectedSport->getScoreType();
    assert(scoreType == "Time" || scoreType == "Point"); // Has to be an enum of these two values
    elements->add(selectedSport);

    const auto protoObj = dat::Object
    {
      { "Type",       ""  },  // Result
      { "ID",         ""  },
      { scoreType ,   ""  },
    };
    std::string path = diciplinePath + diciplineID + ".res";

    auto fileToStream = [path, this]()
    {
      auto innFile = std::ifstream{ path };
      assert(innFile);
      std::cout << "Opening " << path << "...\n";  // @debug
      ss.clear();
      ss << innFile.rdbuf();    // Swapping buffers
      innFile.close();
    };

    fileToStream();

    // Reading number of objects.
    auto objectCount = std::string{};
    stream::readInt(ss, objectCount);
    if (std::stoi(objectCount) < 1) //if no starts are registered
    {
      return false;
    }
    for (size_t i = 0; i < std::stoi(objectCount); i++)
    {
      auto tempObj = protoObj;
      for (size_t j = 0; j < protoObj.size(); j++)
      {
        stream::readString(ss, tempObj[j].second);
      }
      results.push_back(tempObj);
    }
    return true; 
  }

  void SportBase::writeStarts (const std::string& diciplineID, const dat::Container& container)
  { writeFile(diciplinePath + diciplineID + ".sta", container); }

  void SportBase::writeResults(const std::string& diciplineID, const dat::Container& container)
  { writeFile(diciplinePath + diciplineID + ".res", container); }
}

