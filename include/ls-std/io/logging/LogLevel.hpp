/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_LOG_LEVEL_HPP
#define LS_STD_LOG_LEVEL_HPP

#include "LogLevelValue.hpp"
#include <ls-std/core/Class.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <unordered_map>

namespace ls::std::io
{
  class LS_STD_DYNAMIC_GOAL LogLevel : public ls::std::core::Class
  {
    public:

      explicit LogLevel(const ls::std::io::LogLevelValue &_value);
      LogLevel();
      ~LogLevel() noexcept override;
      ;
      ls::std::io::LogLevel &operator=(const ls::std::io::LogLevelValue &_value);
      bool operator<(const ls::std::io::LogLevelValue &_value);
      bool operator<=(const ls::std::io::LogLevelValue &_value);
      bool operator>(const ls::std::io::LogLevelValue &_value);
      bool operator>=(const ls::std::io::LogLevelValue &_value);
      bool operator==(const ls::std::io::LogLevelValue &_value);

      [[nodiscard]] ls::std::io::LogLevelValue getValue();
      void setLogLevel(const ls::std::io::LogLevelValue &_value);
      void setLogLevel(const ::std::string &_value);
      [[nodiscard]] ::std::string toString() const;

    private:

      ::std::unordered_map<uint8_t, ::std::string> level{};
      ls::std::io::LogLevelValue value{};

      [[nodiscard]] ls::std::io::LogLevelValue _getValueFromString(const ::std::string &_value);
      void _init();
      [[nodiscard]] bool _isValidLogLevelString(const ::std::string &_value);
  };
}

#endif
