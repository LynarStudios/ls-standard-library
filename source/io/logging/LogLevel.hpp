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

#include <unordered_map>
#include "../../base/Class.hpp"
#include "LogLevelValue.hpp"

namespace ls_std {
  class LogLevel : public Class {
    public:

      explicit LogLevel(const ls_std::LogLevelValue& _value);
      LogLevel();
      ~LogLevel() = default;

      operator unsigned char() const;
      LogLevel& operator=(const ls_std::LogLevelValue& _value);
      bool operator<=(const ls_std::LogLevelValue& _value);

      std::string toString() const;

    private:

      std::unordered_map<ls_std::LogLevelValue, std::string> level {};
      ls_std::LogLevelValue value {};

      void _init();
  };
}

#endif
