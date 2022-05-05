/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <cmath>
#include <ls_std/boxing/Float.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::Float::Float()
    : ls::Class("Float"),
      epsilon(0.00001f)
{}

ls::Float::Float(float _value)
    : ls::Class("Float"),
      epsilon(0.00001f),
      value(_value)
{}

ls::Float::operator float() const
{
  return this->value;
}

ls::Float &ls::Float::operator=(float _value)
{
  this->value = _value;
  return *this;
}

float ls::Float::operator-() const
{
  return -this->value;
}

float ls::Float::operator+(const ls::Float &_float) const
{
  return this->value + _float;
}

float ls::Float::operator+(float _value) const
{
  return this->value + _value;
}

float ls::Float::operator*(const ls::Float &_float) const
{
  return this->value * _float;
}

float ls::Float::operator*(float _value) const
{
  return this->value * _value;
}

float ls::Float::operator-(const ls::Float &_float) const
{
  return this->value - _float;
}

float ls::Float::operator-(float _value) const
{
  return this->value - _value;
}

float ls::Float::operator/(const ls::Float &_float) const
{
  return this->value / _float;
}

float ls::Float::operator/(float _value) const
{
  return this->value / _value;
}

ls::Float &ls::Float::operator+=(const ls::Float &_float)
{
  this->value += _float;
  return *this;
}

ls::Float &ls::Float::operator+=(float _value)
{
  this->value += _value;
  return *this;
}

ls::Float &ls::Float::operator-=(const ls::Float &_float)
{
  this->value -= _float;
  return *this;
}

ls::Float &ls::Float::operator-=(float _value)
{
  this->value -= _value;
  return *this;
}

ls::Float &ls::Float::operator*=(const ls::Float &_float)
{
  this->value *= _float;
  return *this;
}

ls::Float &ls::Float::operator*=(float _value)
{
  this->value *= _value;
  return *this;
}

ls::Float &ls::Float::operator/=(const ls::Float &_float)
{
  this->value /= _float;
  return *this;
}

ls::Float &ls::Float::operator/=(float _value)
{
  this->value /= _value;
  return *this;
}

bool ls::Float::operator==(const ls::Float &_float) const
{
  return std::fabs(this->value - _float) < this->epsilon;
}

bool ls::Float::operator==(float _value) const
{
  return std::fabs(this->value - _value) < this->epsilon;
}

bool ls::Float::operator!=(const ls::Float &_float) const
{
  return std::fabs(this->value - _float) >= this->epsilon;
}

bool ls::Float::operator!=(float _value) const
{
  return std::fabs(this->value - _value) >= this->epsilon;
}

bool ls::Float::operator>(const ls::Float &_float) const
{
  return this->value > _float;
}

bool ls::Float::operator>(float _value) const
{
  return this->value > _value;
}

bool ls::Float::operator>=(const ls::Float &_float) const
{
  return this->value >= _float;
}

bool ls::Float::operator>=(float _value) const
{
  return this->value >= _value;
}

bool ls::Float::operator<(const ls::Float &_float) const
{
  return this->value < _float;
}

bool ls::Float::operator<(float _value) const
{
  return this->value < _value;
}

bool ls::Float::operator<=(const ls::Float &_float) const
{
  return this->value <= _float;
}

bool ls::Float::operator<=(float _value) const
{
  return this->value <= _value;
}

void ls::Float::operator++()
{
  this->value += 1.0f;
}

void ls::Float::operator--()
{
  this->value -= 1.0f;
}

void ls::Float::parse(std::string _parseText)
{
  this->value = std::stof(_parseText);
}

std::string ls::Float::toString()
{
  return std::to_string(this->value);
}

float ls::Float::getEpsilon()
{
  return this->epsilon;
}

float ls::Float::getValue()
{
  return this->value;
}

void ls::Float::setEpsilon(float _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void ls::Float::_assignEpsilon(float _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw ls::IllegalArgumentException{};
  }

  this->epsilon = _epsilon;
}
