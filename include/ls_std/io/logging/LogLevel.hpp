/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-05-02
 *
 * */

#ifndef LS_STD_LOG_LEVEL_HPP
#define LS_STD_LOG_LEVEL_HPP

#include <unordered_map>
#include <ls_std/base/Class.hpp>
#include "LogLevelValue.hpp"

namespace ls_std
{
  class LogLevel : public ls_std::Class
  {
    public:

      explicit LogLevel(const ls_std::LogLevelValue &_value);
      LogLevel();
      ~LogLevel() override = default;

      operator unsigned char() const;
      ls_std::LogLevel &operator=(const ls_std::LogLevelValue &_value);
      bool operator<(const ls_std::LogLevelValue &_value);
      bool operator<=(const ls_std::LogLevelValue &_value);
      bool operator>(const ls_std::LogLevelValue &_value);
      bool operator>=(const ls_std::LogLevelValue &_value);
      bool operator==(const ls_std::LogLevelValue &_value);

      void setLogLevel(const ls_std::LogLevelValue &_value);
      void setLogLevel(const std::string &_value);
      std::string toString() const;

    private:

      std::unordered_map<uint8_t, std::string> level{};
      ls_std::LogLevelValue value{};

      ls_std::LogLevelValue _getValueFromString(const std::string &_value);
      void _init();
      bool _isValidLogLevelString(const std::string &_value);
  };
}

#endif
