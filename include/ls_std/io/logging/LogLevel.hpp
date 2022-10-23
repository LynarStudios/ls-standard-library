/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-10-23
 *
 * */

#ifndef LS_STD_LOG_LEVEL_HPP
#define LS_STD_LOG_LEVEL_HPP

#include <unordered_map>
#include <ls_std/core/Class.hpp>
#include "LogLevelValue.hpp"
#include <ls_std/os/library/goals/dynamic_goal.hpp>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL LogLevel : public ls::std::core::Class
  {
    public:

      explicit LogLevel(const ls::std::io::LogLevelValue &_value);
      LogLevel();
      ~LogLevel() override = default;

      operator unsigned char() const;
      ls::std::io::LogLevel &operator=(const ls::std::io::LogLevelValue &_value);
      bool operator<(const ls::std::io::LogLevelValue &_value);
      bool operator<=(const ls::std::io::LogLevelValue &_value);
      bool operator>(const ls::std::io::LogLevelValue &_value);
      bool operator>=(const ls::std::io::LogLevelValue &_value);
      bool operator==(const ls::std::io::LogLevelValue &_value);

      void setLogLevel(const ls::std::io::LogLevelValue &_value);
      void setLogLevel(const ::std::string &_value);
      ::std::string toString() const;

    private:

      ::std::unordered_map<uint8_t, ::std::string> level{};
      ls::std::io::LogLevelValue value{};

      ls::std::io::LogLevelValue _getValueFromString(const ::std::string &_value);
      void _init();
      bool _isValidLogLevelString(const ::std::string &_value);
  };
}

#endif
