/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/boxing/Long.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::boxing::Long::Long(ls::std::core::type::long_type _value) : ls::std::core::Class("Long"), value(_value)
{}

ls::std::boxing::Long::Long() : ls::std::core::Class("Long")
{}

ls::std::boxing::Long::~Long() = default;

ls::std::boxing::Long::operator ls::std::core::type::long_type() const
{
  return this->value;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator=(ls::std::core::type::long_type _value)
{
  this->value = _value;
  return *this;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator-() const
{
  return -this->value;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator+(const ls::std::boxing::Long &_long) const
{
  return this->value + _long;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator+(ls::std::core::type::long_type _value) const
{
  return this->value + _value;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator*(const ls::std::boxing::Long &_long) const
{
  return this->value * _long;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator*(ls::std::core::type::long_type _value) const
{
  return this->value * _value;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator-(const ls::std::boxing::Long &_long) const
{
  return this->value - _long;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator-(ls::std::core::type::long_type _value) const
{
  return this->value - _value;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator/(const ls::std::boxing::Long &_long) const
{
  if (_long == (ls::std::core::type::long_type) 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _long;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator/(ls::std::core::type::long_type _value) const
{
  if (_value == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _value;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator%(const ls::std::boxing::Long &_long) const
{
  return this->value % _long;
}

ls::std::core::type::long_type ls::std::boxing::Long::operator%(ls::std::core::type::long_type _value) const
{
  return this->value % _value;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator+=(const ls::std::boxing::Long &_long)
{
  this->value += _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator+=(ls::std::core::type::long_type _value)
{
  this->value += _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator-=(const ls::std::boxing::Long &_long)
{
  this->value -= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator-=(ls::std::core::type::long_type _value)
{
  this->value -= _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator*=(const ls::std::boxing::Long &_long)
{
  this->value *= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator*=(ls::std::core::type::long_type _value)
{
  this->value *= _value;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator/=(const ls::std::boxing::Long &_long)
{
  if (_long == (ls::std::core::type::long_type) 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _long;
  return *this;
}

ls::std::boxing::Long &ls::std::boxing::Long::operator/=(ls::std::core::type::long_type _value)
{
  if (_value == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _value;
  return *this;
}

bool ls::std::boxing::Long::operator==(const ls::std::boxing::Long &_long) const
{
  return this->value == _long;
}

bool ls::std::boxing::Long::operator==(ls::std::core::type::long_type _value) const
{
  return this->value == _value;
}

bool ls::std::boxing::Long::operator!=(const ls::std::boxing::Long &_long) const
{
  return this->value != _long;
}

bool ls::std::boxing::Long::operator!=(ls::std::core::type::long_type _value) const
{
  return this->value != _value;
}

bool ls::std::boxing::Long::operator>(const ls::std::boxing::Long &_long) const
{
  return this->value > _long;
}

bool ls::std::boxing::Long::operator>(ls::std::core::type::long_type _value) const
{
  return this->value > _value;
}

bool ls::std::boxing::Long::operator>=(const ls::std::boxing::Long &_long) const
{
  return this->value >= _long;
}

bool ls::std::boxing::Long::operator>=(ls::std::core::type::long_type _value) const
{
  return this->value >= _value;
}

bool ls::std::boxing::Long::operator<(const ls::std::boxing::Long &_long) const
{
  return this->value < _long;
}

bool ls::std::boxing::Long::operator<(ls::std::core::type::long_type _value) const
{
  return this->value < _value;
}

bool ls::std::boxing::Long::operator<=(const ls::std::boxing::Long &_long) const
{
  return this->value <= _long;
}

bool ls::std::boxing::Long::operator<=(ls::std::core::type::long_type _value) const
{
  return this->value <= _value;
}

bool ls::std::boxing::Long::operator&&(const ls::std::boxing::Long &_long) const
{
  return this->value && _long;
}

bool ls::std::boxing::Long::operator&&(ls::std::core::type::long_type _value) const
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

bool ls::std::boxing::Long::operator||(ls::std::core::type::long_type _value) const
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

ls::std::core::type::long_type ls::std::boxing::Long::getValue() const
{
  return this->value;
}
