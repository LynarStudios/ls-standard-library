/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/logging/LogLevel.hpp>

ls::std::io::LogLevel::LogLevel(const ls::std::io::LogLevelValue &_value) : ls::std::core::Class("LogLevel"), value(_value)
{
  this->_init();
}

ls::std::io::LogLevel::LogLevel() : ls::std::core::Class("LogLevel")
{
  this->_init();
}

ls::std::io::LogLevel::~LogLevel() = default;

ls::std::io::LogLevel::operator unsigned char() const
{
  return this->value;
}

ls::std::io::LogLevel &ls::std::io::LogLevel::operator=(const ls::std::io::LogLevelValue &_value)
{
  this->value = _value;
  return *this;
}

bool ls::std::io::LogLevel::operator<(const ls::std::io::LogLevelValue &_value)
{
  return this->value < _value;
}

bool ls::std::io::LogLevel::operator<=(const ls::std::io::LogLevelValue &_value)
{
  return this->value <= _value;
}

bool ls::std::io::LogLevel::operator>(const ls::std::io::LogLevelValue &_value)
{
  return this->value > _value;
}

bool ls::std::io::LogLevel::operator>=(const ls::std::io::LogLevelValue &_value)
{
  return this->value >= _value;
}

bool ls::std::io::LogLevel::operator==(const ls::std::io::LogLevelValue &_value)
{
  return this->value == _value;
}

void ls::std::io::LogLevel::setLogLevel(const ls::std::io::LogLevelValue &_value)
{
  this->value = _value;
}

void ls::std::io::LogLevel::setLogLevel(const ::std::string &_value)
{
  if (this->_isValidLogLevelString(_value))
  {
    this->value = _getValueFromString(_value);
  }
  else
  {
    throw ls::std::core::IllegalArgumentException{_value + " is not a valid log level string"};
  }
}

::std::string ls::std::io::LogLevel::toString() const
{
  return this->level.at(this->value);
}

ls::std::io::LogLevelValue ls::std::io::LogLevel::_getValueFromString(const ::std::string &_value)
{
  ls::std::io::LogLevelValue logLevelValue{};

  for (const auto &logLevelString : this->level)
  {
    if (logLevelString.second == _value)
    {
      logLevelValue = (ls::std::io::LogLevelValue) logLevelString.first;
      break;
    }
  }

  return logLevelValue;
}

void ls::std::io::LogLevel::_init()
{
  this->level.insert({ls::std::io::LogLevelValue::FATAL, "FATAL"});
  this->level.insert({ls::std::io::LogLevelValue::ERR, "ERROR"});
  this->level.insert({ls::std::io::LogLevelValue::WARN, "WARN"});
  this->level.insert({ls::std::io::LogLevelValue::INFO, "INFO"});
  this->level.insert({ls::std::io::LogLevelValue::DEBUG, "DEBUG"});
  this->level.insert({ls::std::io::LogLevelValue::TRACE, "TRACE"});
}

bool ls::std::io::LogLevel::_isValidLogLevelString(const ::std::string &_value)
{
  bool isValidString{};

  for (const auto &logLevelString : this->level)
  {
    isValidString = logLevelString.second == _value;

    if (isValidString)
    {
      break;
    }
  }

  return isValidString;
}
