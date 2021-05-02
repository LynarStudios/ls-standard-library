/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-05-02
 *
 * */

#include <ls_std/io/logging/LogLevel.hpp>
#include <ls_std/exception/IllegalArgumentException.hpp>

ls_std::LogLevel::LogLevel(const ls_std::LogLevelValue &_value)
    : ls_std::Class("LogLevel"),
      value(_value)
{
  this->_init();
}

ls_std::LogLevel::LogLevel() : ls_std::Class("LogLevel")
{
  this->_init();
}

ls_std::LogLevel::operator unsigned char() const
{
  return this->value;
}

ls_std::LogLevel &ls_std::LogLevel::operator=(const ls_std::LogLevelValue &_value)
{
  this->value = _value;
  return *this;
}

bool ls_std::LogLevel::operator<(const ls_std::LogLevelValue &_value)
{
  return this->value < _value;
}

bool ls_std::LogLevel::operator<=(const ls_std::LogLevelValue &_value)
{
  return this->value <= _value;
}

bool ls_std::LogLevel::operator>(const ls_std::LogLevelValue &_value)
{
  return this->value > _value;
}

bool ls_std::LogLevel::operator>=(const ls_std::LogLevelValue &_value)
{
  return this->value >= _value;
}

bool ls_std::LogLevel::operator==(const ls_std::LogLevelValue &_value)
{
  return this->value == _value;
}

void ls_std::LogLevel::setLogLevel(const ls_std::LogLevelValue &_value)
{
  this->value = _value;
}

void ls_std::LogLevel::setLogLevel(const std::string &_value)
{
  if (this->_isValidLogLevelString(_value))
  {
    this->value = _getValueFromString(_value);
  }
  else
  {
    throw ls_std::IllegalArgumentException{};
  }
}

std::string ls_std::LogLevel::toString() const
{
  return this->level.at(this->value);
}

ls_std::LogLevelValue ls_std::LogLevel::_getValueFromString(const std::string &_value)
{
  ls_std::LogLevelValue logLevelValue{};

  for (const auto &logLevelString : this->level)
  {
    if (logLevelString.second == _value)
    {
      logLevelValue = (ls_std::LogLevelValue) logLevelString.first;
      break;
    }
  }

  return logLevelValue;
}

void ls_std::LogLevel::_init()
{
  this->level.insert({ls_std::LogLevelValue::FATAL, "FATAL"});
  this->level.insert({ls_std::LogLevelValue::ERR, "ERROR"});
  this->level.insert({ls_std::LogLevelValue::WARN, "WARN"});
  this->level.insert({ls_std::LogLevelValue::INFO, "INFO"});
  this->level.insert({ls_std::LogLevelValue::DEBUG, "DEBUG"});
  this->level.insert({ls_std::LogLevelValue::TRACE, "TRACE"});
}

bool ls_std::LogLevel::_isValidLogLevelString(const std::string &_value)
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
