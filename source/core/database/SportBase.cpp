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
      sportProto.push_back( { "Dicipline" + it, diciplines[i].name } );
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
      std::string dname = object[j].second;                               // Dicipline+i name
      dat::Time   dtime = dat::packing::unpackTime( object[j+1] );  // Dicipline+i time
      dat::Date   ddate = dat::packing::unpackDate( object[j+2] );  // Dicipline+i date

      Dicipline newDicipline{ dname, dtime, ddate }; 
      protoSport->addDicipline( newDicipline );
    }

    return protoSport;
  }


  //
  // @class funciton readFile()
  //    Used to fill the database with data;
  //
  auto SportBase::readFile(const std::string& filepath) -> dat::Container
  {
    auto tempContainer = dat::Container{}; // @delete @temp @testing

    auto prototype = dat::Object
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
    stream::readInt(ss,objectCount);

      // Loop through all objects
    for (auto i=0; i < std::stoi(objectCount); i++)
    {
      auto thisProto = prototype;
      std::cout << "Sport " << i << "\n";

      stream::readString (ss, thisProto[0].second);
      stream::readString (ss, thisProto[1].second);
      stream::readEnum   (ss, thisProto[2].second, {"Point", "Medal"});
      stream::readInt    (ss, thisProto[3].second);

      int numberOfDiciplines = std::stoi(thisProto[3].second);
      for (auto j = 4, i = 0; j < (4 + numberOfDiciplines * 3); j += 3, i++ )
      {   
        std::string it = std::to_string(i);
        thisProto.push_back({ "Dicipline " + it, "" });
        thisProto.push_back({ "Time "      + it, "" });
        thisProto.push_back({ "Date "      + it, "" });

        stream::readString(ss, thisProto[j].second);
        stream::readTime  (ss, thisProto[j+1].second); 
        stream::readDate  (ss, thisProto[j+2].second); 
        //std::cout << thisProto[j].second << std::endl;  // @debug
      }
      tempContainer.push_back(thisProto);
    } 
    return tempContainer;
  }
}

