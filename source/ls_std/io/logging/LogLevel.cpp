/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/io/logging/LogLevel.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::LogLevel::LogLevel(const ls::LogLevelValue &_value)
    : ls::Class("LogLevel"),
      value(_value)
{
  this->_init();
}

ls::LogLevel::LogLevel() : ls::Class("LogLevel")
{
  this->_init();
}

ls::LogLevel::operator unsigned char() const
{
  return this->value;
}

ls::LogLevel &ls::LogLevel::operator=(const ls::LogLevelValue &_value)
{
  this->value = _value;
  return *this;
}

bool ls::LogLevel::operator<(const ls::LogLevelValue &_value)
{
  return this->value < _value;
}

bool ls::LogLevel::operator<=(const ls::LogLevelValue &_value)
{
  return this->value <= _value;
}

bool ls::LogLevel::operator>(const ls::LogLevelValue &_value)
{
  return this->value > _value;
}

bool ls::LogLevel::operator>=(const ls::LogLevelValue &_value)
{
  return this->value >= _value;
}

bool ls::LogLevel::operator==(const ls::LogLevelValue &_value)
{
  return this->value == _value;
}

void ls::LogLevel::setLogLevel(const ls::LogLevelValue &_value)
{
  this->value = _value;
}

void ls::LogLevel::setLogLevel(const std::string &_value)
{
  if (this->_isValidLogLevelString(_value))
  {
    this->value = _getValueFromString(_value);
  }
  else
  {
    throw ls::IllegalArgumentException{};
  }
}

std::string ls::LogLevel::toString() const
{
  return this->level.at(this->value);
}

ls::LogLevelValue ls::LogLevel::_getValueFromString(const std::string &_value)
{
  ls::LogLevelValue logLevelValue{};

  for (const auto &logLevelString : this->level)
  {
    if (logLevelString.second == _value)
    {
      logLevelValue = (ls::LogLevelValue) logLevelString.first;
      break;
    }
  }

  return logLevelValue;
}

void ls::LogLevel::_init()
{
  this->level.insert({ls::LogLevelValue::FATAL, "FATAL"});
  this->level.insert({ls::LogLevelValue::ERR, "ERROR"});
  this->level.insert({ls::LogLevelValue::WARN, "WARN"});
  this->level.insert({ls::LogLevelValue::INFO, "INFO"});
  this->level.insert({ls::LogLevelValue::DEBUG, "DEBUG"});
  this->level.insert({ls::LogLevelValue::TRACE, "TRACE"});
}

bool ls::LogLevel::_isValidLogLevelString(const std::string &_value)
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
