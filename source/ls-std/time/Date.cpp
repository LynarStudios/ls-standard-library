/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-03
 *
 * */

#include <iomanip>
#include <ls-std/time/Date.hpp>

ls::std::time::Date::Date() : ls::std::core::Class("Date")
{
  this->timestamp = ::std::time(nullptr);
  this->_init();
}

ls::std::time::Date &ls::std::time::Date::operator+(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

ls::std::time::Date &ls::std::time::Date::operator-(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

ls::std::time::Date &ls::std::time::Date::operator+=(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

ls::std::time::Date &ls::std::time::Date::operator-=(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

bool ls::std::time::Date::after(const ls::std::time::Date &_foreignDate) const
{
  return this->timestamp > _foreignDate.getTime();
}

bool ls::std::time::Date::before(const ls::std::time::Date &_foreignDate) const
{
  return this->timestamp < _foreignDate.getTime();
}

int ls::std::time::Date::getDay()
{
  return this->localTime->tm_mday;
}

int ls::std::time::Date::getHour()
{
  return this->localTime->tm_hour;
}

int ls::std::time::Date::getMinute()
{
  return this->localTime->tm_min;
}

int ls::std::time::Date::getMonth()
{
  return this->localTime->tm_mon + 1;
}

int ls::std::time::Date::getSecond()
{
  return this->localTime->tm_sec;
}

int ls::std::time::Date::getYear()
{
  return this->localTime->tm_year + 1900;
}

time_t ls::std::time::Date::getTime() const
{
  return this->timestamp;
}

void ls::std::time::Date::setTime(time_t _timestamp)
{
  this->timestamp = _timestamp;
  this->_init();
}

::std::string ls::std::time::Date::toString()
{
  ::std::stringstream _stream{};
  _stream << ::std::put_time(this->localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void ls::std::time::Date::_decrementByDays(int _value)
{
  this->timestamp -= (_value * 86400);
}

void ls::std::time::Date::_incrementByDays(int _value)
{
  this->timestamp += (_value * 86400);
}

void ls::std::time::Date::_init()
{
  this->localTime = ::std::localtime(&this->timestamp);
}
