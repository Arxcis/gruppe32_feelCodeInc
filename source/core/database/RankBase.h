//
// @file    core/database/StatBase.h
// @repo    gruppe32
// @created 31.03.17 by Jonas
// @brief   A database for point and medal ranks
//

class RankBase : public DataBase<Rank>
{
public:
  RankBase(){}
  virtual ~RankBase(){}
  virtual T * unpack(dat::Object * object) override;
  virtual dat::Container readFile(const std::string& filepath) override;
};