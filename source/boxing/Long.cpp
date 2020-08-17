/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#include "Long.hpp"
#include "../exception/IllegalArithmeticOperationException.hpp"

ls_std::Long::Long(long _value) : Class("Long"),
                                       value(_value)
{}

ls_std::Long::Long() : Class("Long")
{}

ls_std::Long::operator long() const
{
  return this->value;
}

ls_std::Long& ls_std::Long::operator=(long _value)
{
  this->value = _value;
  return *this;
}

long ls_std::Long::operator-() const
{
  return -this->value;
}

long ls_std::Long::operator+(const Long &_integer) const
{
  return this->value + _integer;
}

long ls_std::Long::operator+(long _value) const
{
  return this->value + _value;
}

long ls_std::Long::operator*(const Long &_integer) const
{
  return this->value * _integer;
}

long ls_std::Long::operator*(long _value) const
{
  return this->value * _value;
}

long ls_std::Long::operator-(const Long &_integer) const
{
  return this->value - _integer;
}

long ls_std::Long::operator-(long _value) const
{
  return this->value - _value;
}

long ls_std::Long::operator/(const Long &_long) const
{
  if(_long == (long) 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _long;
}

long ls_std::Long::operator/(long _value) const
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _value;
}

long ls_std::Long::operator%(const Long &_long) const
{
  return this->value % _long;
}

long ls_std::Long::operator%(long _value) const
{
  return this->value % _value;
}

ls_std::Long & ls_std::Long::operator+=(const Long &_long)
{
  this->value += _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator+=(long _value)
{
  this->value += _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator-=(const Long &_long)
{
  this->value -= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator-=(long _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator*=(const Long &_long)
{
  this->value *= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator*=(long _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator/=(const Long &_long)
{
  if(_long == (long) 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator/=(long _value)
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _value;
  return *this;
}

bool ls_std::Long::operator==(const Long &_long) const
{
  return this->value == _long;
}

bool ls_std::Long::operator==(long _value) const
{
  return this->value == _value;
}

bool ls_std::Long::operator!=(const Long &_long) const
{
  return this->value != _long;
}

bool ls_std::Long::operator!=(long _value) const
{
  return this->value != _value;
}

bool ls_std::Long::operator>(const Long &_long) const
{
  return this->value > _long;
}

bool ls_std::Long::operator>(long _value) const
{
  return this->value > _value;
}

bool ls_std::Long::operator>=(const Long &_long) const
{
  return this->value >= _long;
}

bool ls_std::Long::operator>=(long _value) const
{
  return this->value >= _value;
}

bool ls_std::Long::operator<(const Long &_long) const
{
  return this->value < _long;
}

bool ls_std::Long::operator<(long _value) const
{
  return this->value < _value;
}

bool ls_std::Long::operator<=(const Long &_long) const
{
  return this->value <= _long;
}

bool ls_std::Long::operator<=(long _value) const
{
  return this->value <= _value;
}

bool ls_std::Long::operator&&(const Long &_long) const
{
  return this->value && _long;
}

bool ls_std::Long::operator&&(long _value) const
{
  return this->value && _value;
}

bool ls_std::Long::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls_std::Long::operator||(const Long &_long) const
{
  return this->value || _long;
}

bool ls_std::Long::operator||(long _value) const
{
  return this->value || _value;
}

bool ls_std::Long::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls_std::Long::operator++()
{
  this->value += 1;
}

void ls_std::Long::operator--()
{
  this->value -= 1;
}

void ls_std::Long::parse(std::string _parseText)
{
  this->value = std::stoi(_parseText);
}

std::string ls_std::Long::toString()
{
  return std::to_string(this->value);
}

long ls_std::Long::getValue() const {
  return this->value;
}
