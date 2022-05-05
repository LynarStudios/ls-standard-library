/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_LOG_LEVEL_HPP
#define LS_STD_LOG_LEVEL_HPP

#include <unordered_map>
#include <ls_std/core/Class.hpp>
#include "LogLevelValue.hpp"

namespace ls
{
  class LogLevel : public ls::Class
  {
    public:

      explicit LogLevel(const ls::LogLevelValue &_value);
      LogLevel();
      ~LogLevel() override = default;

      operator unsigned char() const;
      ls::LogLevel &operator=(const ls::LogLevelValue &_value);
      bool operator<(const ls::LogLevelValue &_value);
      bool operator<=(const ls::LogLevelValue &_value);
      bool operator>(const ls::LogLevelValue &_value);
      bool operator>=(const ls::LogLevelValue &_value);
      bool operator==(const ls::LogLevelValue &_value);

      void setLogLevel(const ls::LogLevelValue &_value);
      void setLogLevel(const std::string &_value);
      std::string toString() const;

    private:

      std::unordered_map<uint8_t, std::string> level{};
      ls::LogLevelValue value{};

      ls::LogLevelValue _getValueFromString(const std::string &_value);
      void _init();
      bool _isValidLogLevelString(const std::string &_value);
  };
}

#endif
