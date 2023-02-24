/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-23
 *
 * */

#include <iomanip>
#include <ls-std/time/Date.hpp>
#if defined(_WIN32) || defined(__APPLE__)
  #include <sstream> // only MSVC and Apple need this
#endif

using ls::std::core::Class;
using ls::std::time::Date;
using std::localtime;
using std::put_time;
using std::string;
using std::stringstream;
using std::time;

Date::Date() : Class("Date")
{
  this->timestamp = ::time(nullptr);
  this->_init();
}

Date::~Date() noexcept = default;

Date &Date::operator+(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

Date &Date::operator-(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

Date &Date::operator+=(int _value)
{
  this->_incrementByDays(_value);
  return *this;
}

Date &Date::operator-=(int _value)
{
  this->_decrementByDays(_value);
  return *this;
}

bool Date::after(const Date &_foreignDate) const
{
  return this->timestamp > _foreignDate.getTime();
}

bool Date::before(const Date &_foreignDate) const
{
  return this->timestamp < _foreignDate.getTime();
}

int Date::getDay()
{
  return this->localTime->tm_mday;
}

int Date::getHour()
{
  return this->localTime->tm_hour;
}

int Date::getMinute()
{
  return this->localTime->tm_min;
}

int Date::getMonth()
{
  return this->localTime->tm_mon + 1;
}

int Date::getSecond()
{
  return this->localTime->tm_sec;
}

int Date::getYear()
{
  return this->localTime->tm_year + 1900;
}

time_t Date::getTime() const
{
  return this->timestamp;
}

void Date::setTime(time_t _timestamp)
{
  this->timestamp = _timestamp;
  this->_init();
}

string Date::toString()
{
  stringstream _stream{};
  _stream << put_time(this->localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void Date::_decrementByDays(int _value)
{
  this->timestamp -= (_value * 86400);
}

void Date::_incrementByDays(int _value)
{
  this->timestamp += (_value * 86400);
}

void Date::_init()
{
  this->localTime = localtime(&this->timestamp);
}
