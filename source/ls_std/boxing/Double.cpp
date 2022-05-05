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

ls_std::Double::Double() : ls_std::Class("Double")
{
  this->_assignEpsilon(0.00000001);
}

ls_std::Double::Double(double _value)
    : ls_std::Class("Double"),
      value(_value)
{
  this->_assignEpsilon(0.00000001);
}

ls_std::Double::operator double() const
{
  return this->value;
}

ls_std::Double &ls_std::Double::operator=(double _value)
{
  this->value = _value;
  return *this;
}

double ls_std::Double::operator-() const
{
  return -this->value;
}

double ls_std::Double::operator+(const ls_std::Double &_double) const
{
  return this->value + _double;
}

double ls_std::Double::operator+(double _value) const
{
  return this->value + _value;
}

double ls_std::Double::operator*(const ls_std::Double &_double) const
{
  return this->value * _double;
}

double ls_std::Double::operator*(double _value) const
{
  return this->value * _value;
}

double ls_std::Double::operator-(const ls_std::Double &_double) const
{
  return this->value - _double;
}

double ls_std::Double::operator-(double _value) const
{
  return this->value - _value;
}

double ls_std::Double::operator/(const ls_std::Double &_double) const
{
  return this->value / _double;
}

double ls_std::Double::operator/(double _value) const
{
  return this->value / _value;
}

ls_std::Double &ls_std::Double::operator+=(const ls_std::Double &_double)
{
  this->value += _double;
  return *this;
}

ls_std::Double &ls_std::Double::operator+=(double _value)
{
  this->value += _value;
  return *this;
}

ls_std::Double &ls_std::Double::operator-=(const ls_std::Double &_double)
{
  this->value -= _double;
  return *this;
}

ls_std::Double &ls_std::Double::operator-=(double _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Double &ls_std::Double::operator*=(const ls_std::Double &_double)
{
  this->value *= _double;
  return *this;
}

ls_std::Double &ls_std::Double::operator*=(double _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Double &ls_std::Double::operator/=(const ls_std::Double &_double)
{
  this->value /= _double;
  return *this;
}

ls_std::Double &ls_std::Double::operator/=(double _value)
{
  this->value /= _value;
  return *this;
}

bool ls_std::Double::operator==(const ls_std::Double &_double) const
{
  return std::fabs(this->value - _double) < this->epsilon;
}

bool ls_std::Double::operator==(double _value) const
{
  return std::fabs(this->value - _value) < this->epsilon;
}

bool ls_std::Double::operator!=(const ls_std::Double &_double) const
{
  return std::fabs(this->value - _double) >= this->epsilon;
}

bool ls_std::Double::operator!=(double _value) const
{
  return std::fabs(this->value - _value) >= this->epsilon;
}

bool ls_std::Double::operator>(const ls_std::Double &_double) const
{
  return this->value > _double;
}

bool ls_std::Double::operator>(double _value) const
{
  return this->value > _value;
}

bool ls_std::Double::operator>=(const ls_std::Double &_double) const
{
  return this->value >= _double;
}

bool ls_std::Double::operator>=(double _value) const
{
  return this->value >= _value;
}

bool ls_std::Double::operator<(const ls_std::Double &_double) const
{
  return this->value < _double;
}

bool ls_std::Double::operator<(double _value) const
{
  return this->value < _value;
}

bool ls_std::Double::operator<=(const ls_std::Double &_double) const
{
  return this->value <= _double;
}

bool ls_std::Double::operator<=(double _value) const
{
  return this->value <= _value;
}

void ls_std::Double::operator++()
{
  this->value += 1.0f;
}

void ls_std::Double::operator--()
{
  this->value -= 1.0f;
}

void ls_std::Double::parse(std::string _parseText)
{
  this->value = std::stod(_parseText);
}

std::string ls_std::Double::toString()
{
  return std::to_string(this->value);
}

double ls_std::Double::getEpsilon()
{
  return this->epsilon;
}

double ls_std::Double::getValue()
{
  return this->value;
}

void ls_std::Double::setEpsilon(double _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void ls_std::Double::_assignEpsilon(double _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw ls_std::IllegalArgumentException{};
  }

  this->epsilon = _epsilon;
}
