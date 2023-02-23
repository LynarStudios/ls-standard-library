/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/boxing/Long.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

using ls::std::boxing::Long;
using ls::std::core::Class;
using ls::std::core::IllegalArithmeticOperationException;
using ls::std::core::type::long_type;
using std::stoll;
using std::string;
using std::to_string;

Long::Long(long_type _value) : Long()
{
  this->value = _value;
}

Long::Long() : Class("Long")
{}

Long::~Long() noexcept = default;

Long &Long::operator=(long_type _value)
{
  this->value = _value;
  return *this;
}

long_type Long::operator-() const
{
  return -this->value;
}

long_type Long::operator+(const Long &_long) const
{
  return this->value + _long.getValue();
}

long_type Long::operator+(long_type _value) const
{
  return this->value + _value;
}

long_type Long::operator*(const Long &_long) const
{
  return this->value * _long.getValue();
}

long_type Long::operator*(long_type _value) const
{
  return this->value * _value;
}

long_type Long::operator-(const Long &_long) const
{
  return this->value - _long.getValue();
}

long_type Long::operator-(long_type _value) const
{
  return this->value - _value;
}

long_type Long::operator/(const Long &_long) const
{
  if (_long == (long_type) 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _long.getValue();
}

long_type Long::operator/(long_type _value) const
{
  if (_value == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _value;
}

long_type Long::operator%(const Long &_long) const
{
  return this->value % _long.getValue();
}

long_type Long::operator%(long_type _value) const
{
  return this->value % _value;
}

Long &Long::operator+=(const Long &_long)
{
  this->value += _long.getValue();
  return *this;
}

Long &Long::operator+=(long_type _value)
{
  this->value += _value;
  return *this;
}

Long &Long::operator-=(const Long &_long)
{
  this->value -= _long.getValue();
  return *this;
}

Long &Long::operator-=(long_type _value)
{
  this->value -= _value;
  return *this;
}

Long &Long::operator*=(const Long &_long)
{
  this->value *= _long.getValue();
  return *this;
}

Long &Long::operator*=(long_type _value)
{
  this->value *= _value;
  return *this;
}

Long &Long::operator/=(const Long &_long)
{
  if (_long == (long_type) 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _long.getValue();
  return *this;
}

Long &Long::operator/=(long_type _value)
{
  if (_value == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _value;
  return *this;
}

bool Long::operator==(const Long &_long) const
{
  return this->value == _long.getValue();
}

bool Long::operator==(long_type _value) const
{
  return this->value == _value;
}

bool Long::operator!=(const Long &_long) const
{
  return this->value != _long.getValue();
}

bool Long::operator!=(long_type _value) const
{
  return this->value != _value;
}

bool Long::operator>(const Long &_long) const
{
  return this->value > _long.getValue();
}

bool Long::operator>(long_type _value) const
{
  return this->value > _value;
}

bool Long::operator>=(const Long &_long) const
{
  return this->value >= _long.getValue();
}

bool Long::operator>=(long_type _value) const
{
  return this->value >= _value;
}

bool Long::operator<(const Long &_long) const
{
  return this->value < _long.getValue();
}

bool Long::operator<(long_type _value) const
{
  return this->value < _value;
}

bool Long::operator<=(const Long &_long) const
{
  return this->value <= _long.getValue();
}

bool Long::operator<=(long_type _value) const
{
  return this->value <= _value;
}

bool Long::operator&&(const Long &_long) const
{
  return this->value && _long.getValue();
}

bool Long::operator&&(long_type _value) const
{
  return this->value && _value;
}

bool Long::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool Long::operator||(const Long &_long) const
{
  return this->value || _long.getValue();
}

bool Long::operator||(long_type _value) const
{
  return this->value || _value;
}

bool Long::operator||(bool _expression) const
{
  return this->value || _expression;
}

void Long::operator++()
{
  this->value += 1;
}

void Long::operator--()
{
  this->value -= 1;
}

void Long::parse(string _parseText)
{
  this->value = stoll(_parseText);
}

string Long::toString()
{
  return to_string(this->value);
}

long_type Long::getValue() const
{
  return this->value;
}
