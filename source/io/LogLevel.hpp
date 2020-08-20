/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2020-08-20
 *
 * */

#ifndef LOG_LEVEL_HPP
#define LOG_LEVEL_HPP

namespace ls_std {
  enum LogLevel {
    FATAL = 0,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE,
    OFF
  };
}

#endif
