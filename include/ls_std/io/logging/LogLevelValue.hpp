/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-07-02
 *
 * */

#ifndef LS_STD_LOG_LEVEL_VALUE_HPP
#define LS_STD_LOG_LEVEL_VALUE_HPP

namespace ls::std::io
{
  enum LogLevelValue
  {
    FATAL = 0, ERR, WARN, INFO, DEBUG, TRACE
  };
}

#endif
