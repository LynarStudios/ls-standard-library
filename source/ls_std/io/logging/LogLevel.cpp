/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-20
 * Changed:         2021-04-23
 *
 * */

#include <ls_std/io/logging/LogLevel.hpp>

ls_std::LogLevel::LogLevel(const ls_std::LogLevelValue &_value)
    : ls_std::Class("LogLevel"),
      value(_value)
{
  this->_init();
}

ls_std::LogLevel::LogLevel() : Class("LogLevel")
{}

ls_std::LogLevel::operator unsigned char() const
{
  return this->value;
}

ls_std::LogLevel &ls_std::LogLevel::operator=(const ls_std::LogLevelValue &_value)
{
  this->value = _value;
  return *this;
}

bool ls_std::LogLevel::operator<=(const ls_std::LogLevelValue &_value)
{
  return this->value <= _value;
}

std::string ls_std::LogLevel::toString() const
{
  return this->level.at(this->value);
}

void ls_std::LogLevel::_init()
{
  this->level.insert({ls_std::LogLevelValue::FATAL, "FATAL"});
  this->level.insert({ls_std::LogLevelValue::ERR, "ERROR"});
  this->level.insert({ls_std::LogLevelValue::WARN, "WARN"});
  this->level.insert({ls_std::LogLevelValue::INFO, "INFO"});
  this->level.insert({ls_std::LogLevelValue::DEBUG, "DEBUG"});
  this->level.insert({ls_std::LogLevelValue::TRACE, "TRACE"});
  this->level.insert({ls_std::LogLevelValue::OFF, "OFF"});
}
