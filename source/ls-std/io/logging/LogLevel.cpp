/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/logging/LogLevel.hpp>

using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using ls::std::io::LogLevel;
using ls::std::io::LogLevelValue;
using std::string;

LogLevel::LogLevel(const LogLevelValue &_value) : Class("LogLevel"), value(_value)
{
  this->_init();
}

LogLevel::LogLevel() : Class("LogLevel")
{
  this->_init();
}

LogLevel::~LogLevel() noexcept = default;

LogLevel &LogLevel::operator=(const LogLevelValue &_value)
{
  this->value = _value;
  return *this;
}

bool LogLevel::operator<(const LogLevelValue &_value)
{
  return this->value < _value;
}

bool LogLevel::operator<=(const LogLevelValue &_value)
{
  return this->value <= _value;
}

bool LogLevel::operator>(const LogLevelValue &_value)
{
  return this->value > _value;
}

bool LogLevel::operator>=(const LogLevelValue &_value)
{
  return this->value >= _value;
}

bool LogLevel::operator==(const LogLevelValue &_value)
{
  return this->value == _value;
}

LogLevelValue LogLevel::getValue()
{
  return this->value;
}

void LogLevel::setLogLevel(const LogLevelValue &_value)
{
  this->value = _value;
}

void LogLevel::setLogLevel(const string &_value)
{
  if (this->_isValidLogLevelString(_value))
  {
    this->value = _getValueFromString(_value);
  }
  else
  {
    throw IllegalArgumentException{_value + " is not a valid log level string"};
  }
}

string LogLevel::toString() const
{
  return this->level.at(this->value);
}

LogLevelValue LogLevel::_getValueFromString(const string &_value)
{
  LogLevelValue logLevelValue{};

  for (const auto &logLevelString : this->level)
  {
    if (logLevelString.second == _value)
    {
      logLevelValue = (LogLevelValue) logLevelString.first;
      break;
    }
  }

  return logLevelValue;
}

void LogLevel::_init()
{
  this->level.insert({LogLevelValue::FATAL, "FATAL"});
  this->level.insert({LogLevelValue::ERR, "ERROR"});
  this->level.insert({LogLevelValue::WARN, "WARN"});
  this->level.insert({LogLevelValue::INFO, "INFO"});
  this->level.insert({LogLevelValue::DEBUG, "DEBUG"});
  this->level.insert({LogLevelValue::TRACE, "TRACE"});
}

bool LogLevel::_isValidLogLevelString(const string &_value)
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
