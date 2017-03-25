//
// @file    user/Console.h
// @repo    gruppe32
// @created 24.03.17 by Jonas
// @brief   User-interface class. Basic Console/shell 
//

#include <assert.h>

//
// @class Console
//  @brief This class i instancieted once (Singleton-ish)
//
class Console
{
public:
  Console();
  ~Console();

private:
  static bool instantiated_;
};