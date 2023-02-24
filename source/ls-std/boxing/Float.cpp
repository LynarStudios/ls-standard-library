/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-23
 *
 * */

#include <cmath>
#include <ls-std/boxing/Float.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::boxing::Float;
using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using std::fabs;
using std::stof;
using std::string;
using std::to_string;

Float::Float() : Class("Float"), epsilon(0.00001f)
{}

Float::Float(float _value) : Float()
{
  this->value = _value;
}

Float::~Float() noexcept = default;

Float &Float::operator=(float _value)
{
  this->value = _value;
  return *this;
}

float Float::operator-() const
{
  return -this->value;
}

float Float::operator+(const Float &_float) const
{
  return this->value + _float.getValue();
}

float Float::operator+(float _value) const
{
  return this->value + _value;
}

float Float::operator*(const Float &_float) const
{
  return this->value * _float.getValue();
}

float Float::operator*(float _value) const
{
  return this->value * _value;
}

float Float::operator-(const Float &_float) const
{
  return this->value - _float.getValue();
}

float Float::operator-(float _value) const
{
  return this->value - _value;
}

float Float::operator/(const Float &_float) const
{
  return this->value / _float.getValue();
}

float Float::operator/(float _value) const
{
  return this->value / _value;
}

Float &Float::operator+=(const Float &_float)
{
  this->value += _float.getValue();
  return *this;
}

Float &Float::operator+=(float _value)
{
  this->value += _value;
  return *this;
}

Float &Float::operator-=(const Float &_float)
{
  this->value -= _float.getValue();
  return *this;
}

Float &Float::operator-=(float _value)
{
  this->value -= _value;
  return *this;
}

Float &Float::operator*=(const Float &_float)
{
  this->value *= _float.getValue();
  return *this;
}

Float &Float::operator*=(float _value)
{
  this->value *= _value;
  return *this;
}

Float &Float::operator/=(const Float &_float)
{
  this->value /= _float.getValue();
  return *this;
}

Float &Float::operator/=(float _value)
{
  this->value /= _value;
  return *this;
}

bool Float::operator==(const Float &_float) const
{
  return fabs(this->value - _float.getValue()) < this->epsilon;
}

bool Float::operator==(float _value) const
{
  return fabs(this->value - _value) < this->epsilon;
}

bool Float::operator!=(const Float &_float) const
{
  return fabs(this->value - _float.getValue()) >= this->epsilon;
}

bool Float::operator!=(float _value) const
{
  return fabs(this->value - _value) >= this->epsilon;
}

bool Float::operator>(const Float &_float) const
{
  return this->value > _float.getValue();
}

bool Float::operator>(float _value) const
{
  return this->value > _value;
}

bool Float::operator>=(const Float &_float) const
{
  return this->value >= _float.getValue();
}

bool Float::operator>=(float _value) const
{
  return this->value >= _value;
}

bool Float::operator<(const Float &_float) const
{
  return this->value < _float.getValue();
}

bool Float::operator<(float _value) const
{
  return this->value < _value;
}

bool Float::operator<=(const Float &_float) const
{
  return this->value <= _float.getValue();
}

bool Float::operator<=(float _value) const
{
  return this->value <= _value;
}

void Float::operator++()
{
  this->value += 1.0f;
}

void Float::operator--()
{
  this->value -= 1.0f;
}

void Float::parse(string _parseText)
{
  this->value = stof(_parseText);
}

string Float::toString()
{
  return to_string(this->value);
}

float Float::getEpsilon() const
{
  return this->epsilon;
}

float Float::getValue() const
{
  return this->value;
}

void Float::setEpsilon(float _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void Float::_assignEpsilon(float _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw IllegalArgumentException{"epsilon is less than or equal zero"};
  }

  this->epsilon = _epsilon;
}
