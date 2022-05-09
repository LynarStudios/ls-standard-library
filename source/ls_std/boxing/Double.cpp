/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-09
 *
 * */

#include <cmath>
#include <ls_std/boxing/Double.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::std::boxing::Double::Double() : ls::std::core::Class("Double")
{
  this->_assignEpsilon(0.00000001);
}

ls::std::boxing::Double::Double(double _value)
    : ls::std::core::Class("Double"),
      value(_value)
{
  this->_assignEpsilon(0.00000001);
}

ls::std::boxing::Double::operator double() const
{
  return this->value;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator=(double _value)
{
  this->value = _value;
  return *this;
}

double ls::std::boxing::Double::operator-() const
{
  return -this->value;
}

double ls::std::boxing::Double::operator+(const ls::std::boxing::Double &_double) const
{
  return this->value + _double;
}

double ls::std::boxing::Double::operator+(double _value) const
{
  return this->value + _value;
}

double ls::std::boxing::Double::operator*(const ls::std::boxing::Double &_double) const
{
  return this->value * _double;
}

double ls::std::boxing::Double::operator*(double _value) const
{
  return this->value * _value;
}

double ls::std::boxing::Double::operator-(const ls::std::boxing::Double &_double) const
{
  return this->value - _double;
}

double ls::std::boxing::Double::operator-(double _value) const
{
  return this->value - _value;
}

double ls::std::boxing::Double::operator/(const ls::std::boxing::Double &_double) const
{
  return this->value / _double;
}

double ls::std::boxing::Double::operator/(double _value) const
{
  return this->value / _value;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator+=(const ls::std::boxing::Double &_double)
{
  this->value += _double;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator+=(double _value)
{
  this->value += _value;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator-=(const ls::std::boxing::Double &_double)
{
  this->value -= _double;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator-=(double _value)
{
  this->value -= _value;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator*=(const ls::std::boxing::Double &_double)
{
  this->value *= _double;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator*=(double _value)
{
  this->value *= _value;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator/=(const ls::std::boxing::Double &_double)
{
  this->value /= _double;
  return *this;
}

ls::std::boxing::Double &ls::std::boxing::Double::operator/=(double _value)
{
  this->value /= _value;
  return *this;
}

bool ls::std::boxing::Double::operator==(const ls::std::boxing::Double &_double) const
{
  return ::std::fabs(this->value - _double) < this->epsilon;
}

bool ls::std::boxing::Double::operator==(double _value) const
{
  return ::std::fabs(this->value - _value) < this->epsilon;
}

bool ls::std::boxing::Double::operator!=(const ls::std::boxing::Double &_double) const
{
  return ::std::fabs(this->value - _double) >= this->epsilon;
}

bool ls::std::boxing::Double::operator!=(double _value) const
{
  return ::std::fabs(this->value - _value) >= this->epsilon;
}

bool ls::std::boxing::Double::operator>(const ls::std::boxing::Double &_double) const
{
  return this->value > _double;
}

bool ls::std::boxing::Double::operator>(double _value) const
{
  return this->value > _value;
}

bool ls::std::boxing::Double::operator>=(const ls::std::boxing::Double &_double) const
{
  return this->value >= _double;
}

bool ls::std::boxing::Double::operator>=(double _value) const
{
  return this->value >= _value;
}

bool ls::std::boxing::Double::operator<(const ls::std::boxing::Double &_double) const
{
  return this->value < _double;
}

bool ls::std::boxing::Double::operator<(double _value) const
{
  return this->value < _value;
}

bool ls::std::boxing::Double::operator<=(const ls::std::boxing::Double &_double) const
{
  return this->value <= _double;
}

bool ls::std::boxing::Double::operator<=(double _value) const
{
  return this->value <= _value;
}

void ls::std::boxing::Double::operator++()
{
  this->value += 1.0f;
}

void ls::std::boxing::Double::operator--()
{
  this->value -= 1.0f;
}

void ls::std::boxing::Double::parse(::std::string _parseText)
{
  this->value = ::std::stod(_parseText);
}

std::string ls::std::boxing::Double::toString()
{
  return ::std::to_string(this->value);
}

double ls::std::boxing::Double::getEpsilon()
{
  return this->epsilon;
}

double ls::std::boxing::Double::getValue()
{
  return this->value;
}

void ls::std::boxing::Double::setEpsilon(double _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void ls::std::boxing::Double::_assignEpsilon(double _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->epsilon = _epsilon;
}
