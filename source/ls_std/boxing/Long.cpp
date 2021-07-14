/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2021-07-14
 *
 * */

#include <ls_std/boxing/Long.hpp>
#include <ls_std/exception/IllegalArithmeticOperationException.hpp>

ls_std::Long::Long(ls_std::long_type _value)
    : ls_std::Class("Long"),
      value(_value)
{}

ls_std::Long::Long() : ls_std::Class("Long")
{}

ls_std::Long::operator ls_std::long_type() const
{
  return this->value;
}

ls_std::Long &ls_std::Long::operator=(ls_std::long_type _value)
{
  this->value = _value;
  return *this;
}

ls_std::long_type ls_std::Long::operator-() const
{
  return -this->value;
}

ls_std::long_type ls_std::Long::operator+(const ls_std::Long &_long) const
{
  return this->value + _long;
}

ls_std::long_type ls_std::Long::operator+(ls_std::long_type _value) const
{
  return this->value + _value;
}

ls_std::long_type ls_std::Long::operator*(const ls_std::Long &_long) const
{
  return this->value * _long;
}

ls_std::long_type ls_std::Long::operator*(ls_std::long_type _value) const
{
  return this->value * _value;
}

ls_std::long_type ls_std::Long::operator-(const ls_std::Long &_long) const
{
  return this->value - _long;
}

ls_std::long_type ls_std::Long::operator-(ls_std::long_type _value) const
{
  return this->value - _value;
}

ls_std::long_type ls_std::Long::operator/(const ls_std::Long &_long) const
{
  if (_long == (ls_std::long_type) 0)
  {
    throw ls_std::IllegalArithmeticOperationException{};
  }

  return this->value / _long;
}

ls_std::long_type ls_std::Long::operator/(ls_std::long_type _value) const
{
  if (_value == 0)
  {
    throw ls_std::IllegalArithmeticOperationException{};
  }

  return this->value / _value;
}

ls_std::long_type ls_std::Long::operator%(const ls_std::Long &_long) const
{
  return this->value % _long;
}

ls_std::long_type ls_std::Long::operator%(ls_std::long_type _value) const
{
  return this->value % _value;
}

ls_std::Long &ls_std::Long::operator+=(const ls_std::Long &_long)
{
  this->value += _long;
  return *this;
}

ls_std::Long &ls_std::Long::operator+=(ls_std::long_type _value)
{
  this->value += _value;
  return *this;
}

ls_std::Long &ls_std::Long::operator-=(const ls_std::Long &_long)
{
  this->value -= _long;
  return *this;
}

ls_std::Long &ls_std::Long::operator-=(ls_std::long_type _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Long &ls_std::Long::operator*=(const ls_std::Long &_long)
{
  this->value *= _long;
  return *this;
}

ls_std::Long &ls_std::Long::operator*=(ls_std::long_type _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Long &ls_std::Long::operator/=(const ls_std::Long &_long)
{
  if (_long == (ls_std::long_type) 0)
  {
    throw ls_std::IllegalArithmeticOperationException{};
  }

  this->value /= _long;
  return *this;
}

ls_std::Long &ls_std::Long::operator/=(ls_std::long_type _value)
{
  if (_value == 0)
  {
    throw ls_std::IllegalArithmeticOperationException{};
  }

  this->value /= _value;
  return *this;
}

bool ls_std::Long::operator==(const ls_std::Long &_long) const
{
  return this->value == _long;
}

bool ls_std::Long::operator==(ls_std::long_type _value) const
{
  return this->value == _value;
}

bool ls_std::Long::operator!=(const ls_std::Long &_long) const
{
  return this->value != _long;
}

bool ls_std::Long::operator!=(ls_std::long_type _value) const
{
  return this->value != _value;
}

bool ls_std::Long::operator>(const ls_std::Long &_long) const
{
  return this->value > _long;
}

bool ls_std::Long::operator>(ls_std::long_type _value) const
{
  return this->value > _value;
}

bool ls_std::Long::operator>=(const ls_std::Long &_long) const
{
  return this->value >= _long;
}

bool ls_std::Long::operator>=(ls_std::long_type _value) const
{
  return this->value >= _value;
}

bool ls_std::Long::operator<(const ls_std::Long &_long) const
{
  return this->value < _long;
}

bool ls_std::Long::operator<(ls_std::long_type _value) const
{
  return this->value < _value;
}

bool ls_std::Long::operator<=(const ls_std::Long &_long) const
{
  return this->value <= _long;
}

bool ls_std::Long::operator<=(ls_std::long_type _value) const
{
  return this->value <= _value;
}

bool ls_std::Long::operator&&(const ls_std::Long &_long) const
{
  return this->value && _long;
}

bool ls_std::Long::operator&&(ls_std::long_type _value) const
{
  return this->value && _value;
}

bool ls_std::Long::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls_std::Long::operator||(const ls_std::Long &_long) const
{
  return this->value || _long;
}

bool ls_std::Long::operator||(ls_std::long_type _value) const
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
  this->value = std::stoll(_parseText);
}

std::string ls_std::Long::toString()
{
  return std::to_string(this->value);
}

ls_std::long_type ls_std::Long::getValue() const
{
  return this->value;
}
