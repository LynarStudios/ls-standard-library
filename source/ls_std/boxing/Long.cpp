/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-06
 *
 * */

#include <ls_std/boxing/Long.hpp>
#include <ls_std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::boxing::Long::Long(ls::long_type _value)
    : ls::Class("Long"),
      value(_value)
{}

ls::std::boxing::Long::Long() : ls::Class("Long")
{}

ls::std::boxing::Long::operator ls::long_type() const
{
  return this->value;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator=(ls::long_type _value)
{
  this->value = _value;
  return *this;
}

ls::long_type ls::std::boxing::Long::operator-() const
{
  return -this->value;
}

ls::long_type ls::std::boxing::Long::operator+(const ls::std::boxing::Long &_long) const
{
  return this->value + _long;
}

ls::long_type ls::std::boxing::Long::operator+(ls::long_type _value) const
{
  return this->value + _value;
}

ls::long_type ls::std::boxing::Long::operator*(const ls::std::boxing::Long &_long) const
{
  return this->value * _long;
}

ls::long_type ls::std::boxing::Long::operator*(ls::long_type _value) const
{
  return this->value * _value;
}

ls::long_type ls::std::boxing::Long::operator-(const ls::std::boxing::Long &_long) const
{
  return this->value - _long;
}

ls::long_type ls::std::boxing::Long::operator-(ls::long_type _value) const
{
  return this->value - _value;
}

ls::long_type ls::std::boxing::Long::operator/(const ls::std::boxing::Long &_long) const
{
  if (_long == (ls::long_type) 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _long;
}

ls::long_type ls::std::boxing::Long::operator/(ls::long_type _value) const
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _value;
}

ls::long_type ls::std::boxing::Long::operator%(const ls::std::boxing::Long &_long) const
{
  return this->value % _long;
}

ls::long_type ls::std::boxing::Long::operator%(ls::long_type _value) const
{
  return this->value % _value;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator+=(const ls::std::boxing::Long &_long)
{
  this->value += _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator+=(ls::long_type _value)
{
  this->value += _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator-=(const ls::std::boxing::Long &_long)
{
  this->value -= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator-=(ls::long_type _value)
{
  this->value -= _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator*=(const ls::std::boxing::Long &_long)
{
  this->value *= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator*=(ls::long_type _value)
{
  this->value *= _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator/=(const ls::std::boxing::Long &_long)
{
  if (_long == (ls::long_type) 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator/=(ls::long_type _value)
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _value;
  return *this;
}

bool ls::std::boxing::Long::operator==(const ls::std::boxing::Long &_long) const
{
  return this->value == _long;
}

bool ls::std::boxing::Long::operator==(ls::long_type _value) const
{
  return this->value == _value;
}

bool ls::std::boxing::Long::operator!=(const ls::std::boxing::Long &_long) const
{
  return this->value != _long;
}

bool ls::std::boxing::Long::operator!=(ls::long_type _value) const
{
  return this->value != _value;
}

bool ls::std::boxing::Long::operator>(const ls::std::boxing::Long &_long) const
{
  return this->value > _long;
}

bool ls::std::boxing::Long::operator>(ls::long_type _value) const
{
  return this->value > _value;
}

bool ls::std::boxing::Long::operator>=(const ls::std::boxing::Long &_long) const
{
  return this->value >= _long;
}

bool ls::std::boxing::Long::operator>=(ls::long_type _value) const
{
  return this->value >= _value;
}

bool ls::std::boxing::Long::operator<(const ls::std::boxing::Long &_long) const
{
  return this->value < _long;
}

bool ls::std::boxing::Long::operator<(ls::long_type _value) const
{
  return this->value < _value;
}

bool ls::std::boxing::Long::operator<=(const ls::std::boxing::Long &_long) const
{
  return this->value <= _long;
}

bool ls::std::boxing::Long::operator<=(ls::long_type _value) const
{
  return this->value <= _value;
}

bool ls::std::boxing::Long::operator&&(const ls::std::boxing::Long &_long) const
{
  return this->value && _long;
}

bool ls::std::boxing::Long::operator&&(ls::long_type _value) const
{
  return this->value && _value;
}

bool ls::std::boxing::Long::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls::std::boxing::Long::operator||(const ls::std::boxing::Long &_long) const
{
  return this->value || _long;
}

bool ls::std::boxing::Long::operator||(ls::long_type _value) const
{
  return this->value || _value;
}

bool ls::std::boxing::Long::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls::std::boxing::Long::operator++()
{
  this->value += 1;
}

void ls::std::boxing::Long::operator--()
{
  this->value -= 1;
}

void ls::std::boxing::Long::parse(::std::string _parseText)
{
  this->value = ::std::stoll(_parseText);
}

std::string ls::std::boxing::Long::toString()
{
  return ::std::to_string(this->value);
}

ls::long_type ls::std::boxing::Long::getValue() const
{
  return this->value;
}
