/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-10-29
 *
 * */

#include <iomanip>
#include <sstream>
#include "Date.hpp"

ls_std::Date::Date() : Class("Date")
{
  this->timestamp = std::time(nullptr);
  this->_init();
}

ls_std::Date & ls_std::Date::operator+(int _value) {
  this->timestamp += (_value * 86400);
  return *this;
}

ls_std::Date & ls_std::Date::operator-(int _value) {
  this->timestamp -= (_value * 86400);
  return *this;
}

bool ls_std::Date::after(const Date& _foreignDate) const {
  return this->timestamp > _foreignDate.getTime();
}

bool ls_std::Date::before(const Date& _foreignDate) const {
  return this->timestamp < _foreignDate.getTime();
}

int ls_std::Date::getDay() {
  return this->localTime->tm_mday;
}

int ls_std::Date::getHour() {
  return this->localTime->tm_hour;
}

int ls_std::Date::getMinute() {
  return this->localTime->tm_min;
}

int ls_std::Date::getMonth() {
  return this->localTime->tm_mon + 1;
}

int ls_std::Date::getSecond() {
  return this->localTime->tm_sec;
}

int ls_std::Date::getYear() {
  return this->localTime->tm_year + 1900;
}

time_t ls_std::Date::getTime() const {
  return this->timestamp;
}

void ls_std::Date::setTime(time_t _timestamp) {
  this->timestamp = _timestamp;
  this->_init();
}

std::string ls_std::Date::toString() {
  std::stringstream _stream {};
  _stream << std::put_time(this->localTime, "%Y-%m-%d %H:%M:%S");

  return _stream.str();
}

void ls_std::Date::_init() {
  this->localTime = std::localtime(&this->timestamp);
}
