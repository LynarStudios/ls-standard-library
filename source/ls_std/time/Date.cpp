/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <iomanip>
#include <sstream>
#include <ls_std/time/Date.hpp>

ls::Date::Date() : ls::Class("Date")
{
  this->timestamp = std::time(nullptr);
  this->_init();
}

ls::Date &ls::Date::operator+(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

ls::Date &ls::Date::operator-(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

ls::Date &ls::Date::operator+=(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

ls::Date &ls::Date::operator-=(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

bool ls::Date::after(const ls::Date &_foreignDate) const
{
  return this->timestamp > _foreignDate.getTime();
}

bool ls::Date::before(const ls::Date &_foreignDate) const
{
  return this->timestamp < _foreignDate.getTime();
}

int ls::Date::getDay()
{
  return this->localTime->tm_mday;
}

int ls::Date::getHour()
{
  return this->localTime->tm_hour;
}

int ls::Date::getMinute()
{
  return this->localTime->tm_min;
}

int ls::Date::getMonth()
{
  return this->localTime->tm_mon + 1;
}

int ls::Date::getSecond()
{
  return this->localTime->tm_sec;
}

int ls::Date::getYear()
{
  return this->localTime->tm_year + 1900;
}

time_t ls::Date::getTime() const
{
  return this->timestamp;
}

void ls::Date::setTime(time_t _timestamp)
{
  this->timestamp = _timestamp;
  this->_init();
}

std::string ls::Date::toString()
{
  std::stringstream _stream{};
  _stream << std::put_time(this->localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void ls::Date::_decrementByDays(int _value)
{
  this->timestamp -= (_value * 86400);
}

void ls::Date::_incrementByDays(int _value)
{
  this->timestamp += (_value * 86400);
}

void ls::Date::_init()
{
  this->localTime = std::localtime(&this->timestamp);
}
