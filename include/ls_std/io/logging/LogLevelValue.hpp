/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-07-01
 *
 * */

#ifndef LS_STD_LOG_LEVEL_VALUE_HPP
#define LS_STD_LOG_LEVEL_VALUE_HPP

#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace io
    {
      enum DYNAMIC_GOAL LogLevelValue
      {
        FATAL = 0, ERR, WARN, INFO, DEBUG, TRACE
      };
    }
  }
}

#endif
