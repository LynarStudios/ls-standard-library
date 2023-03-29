/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-03-29
* Changed:         2023-03-29
*
* */

#include <ls-std/time/common/DateParameter.hpp>

using ls::std::time::DateParameter;
using ls::std::time::type::Day;
using ls::std::time::type::Hour;
using ls::std::time::type::Millisecond;
using ls::std::time::type::Minute;
using ls::std::time::type::Month;
using ls::std::time::type::Second;
using ls::std::time::type::Year;

DateParameter::DateParameter(Year _year, Month _month, Day _day, Hour _hour, Minute _minute, Second _second, Millisecond _millisecond) : year(_year), month(_month), day(_day), hour(_hour), minute(_minute), second(_second), millisecond(_millisecond)
{}

DateParameter::DateParameter() = default;

DateParameter::~DateParameter() = default;

Day DateParameter::getDay() const
{
  return this->day;
}

Hour DateParameter::getHour() const
{
  return this->hour;
}

Millisecond DateParameter::getMillisecond() const
{
  return this->millisecond;
}

Minute DateParameter::getMinute() const
{
  return this->minute;
}

Month DateParameter::getMonth() const
{
  return this->month;
}

Second DateParameter::getSecond() const
{
  return this->second;
}

Year DateParameter::getYear() const
{
  return this->year;
}

void DateParameter::setDay(Day _day)
{
  this->day = _day;
}

void DateParameter::setHour(Hour _hour)
{
  this->hour = _hour;
}

void DateParameter::setMillisecond(Millisecond _millisecond)
{
  this->millisecond = _millisecond;
}

void DateParameter::setMinute(Minute _minute)
{
  this->minute = _minute;
}

void DateParameter::setMonth(Month _month)
{
  this->month = _month;
}

void DateParameter::setSecond(Second _second)
{
  this->second = _second;
}

void DateParameter::setYear(Year _year)
{
  this->year = _year;
}
