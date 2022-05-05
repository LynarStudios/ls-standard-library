/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/boxing/Long.hpp>
#include <ls_std/core/exception/IllegalArithmeticOperationException.hpp>

ls::Long::Long(ls::long_type _value)
    : ls::Class("Long"),
      value(_value)
{}

ls::Long::Long() : ls::Class("Long")
{}

ls::Long::operator ls::long_type() const
{
  return this->value;
}

ls::Long &ls::Long::operator=(ls::long_type _value)
{
  this->value = _value;
  return *this;
}

ls::long_type ls::Long::operator-() const
{
  return -this->value;
}

ls::long_type ls::Long::operator+(const ls::Long &_long) const
{
  return this->value + _long;
}

ls::long_type ls::Long::operator+(ls::long_type _value) const
{
  return this->value + _value;
}

ls::long_type ls::Long::operator*(const ls::Long &_long) const
{
  return this->value * _long;
}

ls::long_type ls::Long::operator*(ls::long_type _value) const
{
  return this->value * _value;
}

ls::long_type ls::Long::operator-(const ls::Long &_long) const
{
  return this->value - _long;
}

ls::long_type ls::Long::operator-(ls::long_type _value) const
{
  return this->value - _value;
}

ls::long_type ls::Long::operator/(const ls::Long &_long) const
{
  if (_long == (ls::long_type) 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _long;
}

ls::long_type ls::Long::operator/(ls::long_type _value) const
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _value;
}

ls::long_type ls::Long::operator%(const ls::Long &_long) const
{
  return this->value % _long;
}

ls::long_type ls::Long::operator%(ls::long_type _value) const
{
  return this->value % _value;
}

ls::Long &ls::Long::operator+=(const ls::Long &_long)
{
  this->value += _long;
  return *this;
}

ls::Long &ls::Long::operator+=(ls::long_type _value)
{
  this->value += _value;
  return *this;
}

ls::Long &ls::Long::operator-=(const ls::Long &_long)
{
  this->value -= _long;
  return *this;
}

ls::Long &ls::Long::operator-=(ls::long_type _value)
{
  this->value -= _value;
  return *this;
}

ls::Long &ls::Long::operator*=(const ls::Long &_long)
{
  this->value *= _long;
  return *this;
}

ls::Long &ls::Long::operator*=(ls::long_type _value)
{
  this->value *= _value;
  return *this;
}

ls::Long &ls::Long::operator/=(const ls::Long &_long)
{
  if (_long == (ls::long_type) 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _long;
  return *this;
}

ls::Long &ls::Long::operator/=(ls::long_type _value)
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _value;
  return *this;
}

bool ls::Long::operator==(const ls::Long &_long) const
{
  return this->value == _long;
}

bool ls::Long::operator==(ls::long_type _value) const
{
  return this->value == _value;
}

bool ls::Long::operator!=(const ls::Long &_long) const
{
  return this->value != _long;
}

bool ls::Long::operator!=(ls::long_type _value) const
{
  return this->value != _value;
}

bool ls::Long::operator>(const ls::Long &_long) const
{
  return this->value > _long;
}

bool ls::Long::operator>(ls::long_type _value) const
{
  return this->value > _value;
}

bool ls::Long::operator>=(const ls::Long &_long) const
{
  return this->value >= _long;
}

bool ls::Long::operator>=(ls::long_type _value) const
{
  return this->value >= _value;
}

bool ls::Long::operator<(const ls::Long &_long) const
{
  return this->value < _long;
}

bool ls::Long::operator<(ls::long_type _value) const
{
  return this->value < _value;
}

bool ls::Long::operator<=(const ls::Long &_long) const
{
  return this->value <= _long;
}

bool ls::Long::operator<=(ls::long_type _value) const
{
  return this->value <= _value;
}

bool ls::Long::operator&&(const ls::Long &_long) const
{
  return this->value && _long;
}

bool ls::Long::operator&&(ls::long_type _value) const
{
  return this->value && _value;
}

bool ls::Long::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls::Long::operator||(const ls::Long &_long) const
{
  return this->value || _long;
}

bool ls::Long::operator||(ls::long_type _value) const
{
  return this->value || _value;
}

bool ls::Long::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls::Long::operator++()
{
  this->value += 1;
}

void ls::Long::operator--()
{
  this->value -= 1;
}

void ls::Long::parse(std::string _parseText)
{
  this->value = std::stoll(_parseText);
}

std::string ls::Long::toString()
{
  return std::to_string(this->value);
}

ls::long_type ls::Long::getValue() const
{
  return this->value;
}
