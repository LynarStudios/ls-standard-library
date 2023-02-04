/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-03
 *
 * */

#include <cmath>
#include <ls-std/boxing/Float.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::boxing::Float::Float()
    : ls::std::core::Class("Float"),
      epsilon(0.00001f)
{}

ls::std::boxing::Float::Float(float _value)
    : ls::std::core::Class("Float"),
      epsilon(0.00001f),
      value(_value)
{}

ls::std::boxing::Float::operator float() const
{
  return this->value;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator=(float _value)
{
  this->value = _value;
  return *this;
}

float ls::std::boxing::Float::operator-() const
{
  return -this->value;
}

float ls::std::boxing::Float::operator+(const ls::std::boxing::Float &_float) const
{
  return this->value + _float;
}

float ls::std::boxing::Float::operator+(float _value) const
{
  return this->value + _value;
}

float ls::std::boxing::Float::operator*(const ls::std::boxing::Float &_float) const
{
  return this->value * _float;
}

float ls::std::boxing::Float::operator*(float _value) const
{
  return this->value * _value;
}

float ls::std::boxing::Float::operator-(const ls::std::boxing::Float &_float) const
{
  return this->value - _float;
}

float ls::std::boxing::Float::operator-(float _value) const
{
  return this->value - _value;
}

float ls::std::boxing::Float::operator/(const ls::std::boxing::Float &_float) const
{
  return this->value / _float;
}

float ls::std::boxing::Float::operator/(float _value) const
{
  return this->value / _value;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator+=(const ls::std::boxing::Float &_float)
{
  this->value += _float;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator+=(float _value)
{
  this->value += _value;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator-=(const ls::std::boxing::Float &_float)
{
  this->value -= _float;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator-=(float _value)
{
  this->value -= _value;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator*=(const ls::std::boxing::Float &_float)
{
  this->value *= _float;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator*=(float _value)
{
  this->value *= _value;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator/=(const ls::std::boxing::Float &_float)
{
  this->value /= _float;
  return *this;
}

ls::std::boxing::Float &ls::std::boxing::Float::operator/=(float _value)
{
  this->value /= _value;
  return *this;
}

bool ls::std::boxing::Float::operator==(const ls::std::boxing::Float &_float) const
{
  return ::std::fabs(this->value - _float) < this->epsilon;
}

bool ls::std::boxing::Float::operator==(float _value) const
{
  return ::std::fabs(this->value - _value) < this->epsilon;
}

bool ls::std::boxing::Float::operator!=(const ls::std::boxing::Float &_float) const
{
  return ::std::fabs(this->value - _float) >= this->epsilon;
}

bool ls::std::boxing::Float::operator!=(float _value) const
{
  return ::std::fabs(this->value - _value) >= this->epsilon;
}

bool ls::std::boxing::Float::operator>(const ls::std::boxing::Float &_float) const
{
  return this->value > _float;
}

bool ls::std::boxing::Float::operator>(float _value) const
{
  return this->value > _value;
}

bool ls::std::boxing::Float::operator>=(const ls::std::boxing::Float &_float) const
{
  return this->value >= _float;
}

bool ls::std::boxing::Float::operator>=(float _value) const
{
  return this->value >= _value;
}

bool ls::std::boxing::Float::operator<(const ls::std::boxing::Float &_float) const
{
  return this->value < _float;
}

bool ls::std::boxing::Float::operator<(float _value) const
{
  return this->value < _value;
}

bool ls::std::boxing::Float::operator<=(const ls::std::boxing::Float &_float) const
{
  return this->value <= _float;
}

bool ls::std::boxing::Float::operator<=(float _value) const
{
  return this->value <= _value;
}

void ls::std::boxing::Float::operator++()
{
  this->value += 1.0f;
}

void ls::std::boxing::Float::operator--()
{
  this->value -= 1.0f;
}

void ls::std::boxing::Float::parse(::std::string _parseText)
{
  this->value = ::std::stof(_parseText);
}

::std::string ls::std::boxing::Float::toString()
{
  return ::std::to_string(this->value);
}

float ls::std::boxing::Float::getEpsilon()
{
  return this->epsilon;
}

float ls::std::boxing::Float::getValue()
{
  return this->value;
}

void ls::std::boxing::Float::setEpsilon(float _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void ls::std::boxing::Float::_assignEpsilon(float _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw ls::std::core::IllegalArgumentException{};
  }

  this->epsilon = _epsilon;
}
