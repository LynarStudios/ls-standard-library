/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <cmath>
#include <ls_std/boxing/Double.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::Double::Double() : ls::Class("Double")
{
  this->_assignEpsilon(0.00000001);
}

ls::Double::Double(double _value)
    : ls::Class("Double"),
      value(_value)
{
  this->_assignEpsilon(0.00000001);
}

ls::Double::operator double() const
{
  return this->value;
}

ls::Double &ls::Double::operator=(double _value)
{
  this->value = _value;
  return *this;
}

double ls::Double::operator-() const
{
  return -this->value;
}

double ls::Double::operator+(const ls::Double &_double) const
{
  return this->value + _double;
}

double ls::Double::operator+(double _value) const
{
  return this->value + _value;
}

double ls::Double::operator*(const ls::Double &_double) const
{
  return this->value * _double;
}

double ls::Double::operator*(double _value) const
{
  return this->value * _value;
}

double ls::Double::operator-(const ls::Double &_double) const
{
  return this->value - _double;
}

double ls::Double::operator-(double _value) const
{
  return this->value - _value;
}

double ls::Double::operator/(const ls::Double &_double) const
{
  return this->value / _double;
}

double ls::Double::operator/(double _value) const
{
  return this->value / _value;
}

ls::Double &ls::Double::operator+=(const ls::Double &_double)
{
  this->value += _double;
  return *this;
}

ls::Double &ls::Double::operator+=(double _value)
{
  this->value += _value;
  return *this;
}

ls::Double &ls::Double::operator-=(const ls::Double &_double)
{
  this->value -= _double;
  return *this;
}

ls::Double &ls::Double::operator-=(double _value)
{
  this->value -= _value;
  return *this;
}

ls::Double &ls::Double::operator*=(const ls::Double &_double)
{
  this->value *= _double;
  return *this;
}

ls::Double &ls::Double::operator*=(double _value)
{
  this->value *= _value;
  return *this;
}

ls::Double &ls::Double::operator/=(const ls::Double &_double)
{
  this->value /= _double;
  return *this;
}

ls::Double &ls::Double::operator/=(double _value)
{
  this->value /= _value;
  return *this;
}

bool ls::Double::operator==(const ls::Double &_double) const
{
  return std::fabs(this->value - _double) < this->epsilon;
}

bool ls::Double::operator==(double _value) const
{
  return std::fabs(this->value - _value) < this->epsilon;
}

bool ls::Double::operator!=(const ls::Double &_double) const
{
  return std::fabs(this->value - _double) >= this->epsilon;
}

bool ls::Double::operator!=(double _value) const
{
  return std::fabs(this->value - _value) >= this->epsilon;
}

bool ls::Double::operator>(const ls::Double &_double) const
{
  return this->value > _double;
}

bool ls::Double::operator>(double _value) const
{
  return this->value > _value;
}

bool ls::Double::operator>=(const ls::Double &_double) const
{
  return this->value >= _double;
}

bool ls::Double::operator>=(double _value) const
{
  return this->value >= _value;
}

bool ls::Double::operator<(const ls::Double &_double) const
{
  return this->value < _double;
}

bool ls::Double::operator<(double _value) const
{
  return this->value < _value;
}

bool ls::Double::operator<=(const ls::Double &_double) const
{
  return this->value <= _double;
}

bool ls::Double::operator<=(double _value) const
{
  return this->value <= _value;
}

void ls::Double::operator++()
{
  this->value += 1.0f;
}

void ls::Double::operator--()
{
  this->value -= 1.0f;
}

void ls::Double::parse(std::string _parseText)
{
  this->value = std::stod(_parseText);
}

std::string ls::Double::toString()
{
  return std::to_string(this->value);
}

double ls::Double::getEpsilon()
{
  return this->epsilon;
}

double ls::Double::getValue()
{
  return this->value;
}

void ls::Double::setEpsilon(double _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void ls::Double::_assignEpsilon(double _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw ls::IllegalArgumentException{};
  }

  this->epsilon = _epsilon;
}
