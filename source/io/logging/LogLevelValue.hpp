/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#ifndef LOG_LEVEL_VALUE_HPP
#define LOG_LEVEL_VALUE_HPP

namespace ls_std {
  enum LogLevelValue {
    FATAL = 0,
    ERR,
    WARN,
    INFO,
    DEBUG,
    TRACE,
    OFF
  };
}

#endif
