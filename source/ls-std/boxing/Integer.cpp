/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-07
 *
 * */

#include <ls-std/boxing/Integer.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

ls::std::boxing::Integer::Integer(int _value) : ls::std::core::Class("Integer"), value(_value)
{}

ls::std::boxing::Integer::Integer() : ls::std::core::Class("Integer")
{}

ls::std::boxing::Integer::~Integer() = default;

ls::std::boxing::Integer::operator int() const
{
  return this->value;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator=(int _value)
{
  this->value = _value;
  return *this;
}

int ls::std::boxing::Integer::operator-() const
{
  return -this->value;
}

int ls::std::boxing::Integer::operator+(const ls::std::boxing::Integer &_integer) const
{
  return this->value + _integer;
}

int ls::std::boxing::Integer::operator+(int _value) const
{
  return this->value + _value;
}

int ls::std::boxing::Integer::operator*(const ls::std::boxing::Integer &_integer) const
{
  return this->value * _integer;
}

int ls::std::boxing::Integer::operator*(int _value) const
{
  return this->value * _value;
}

int ls::std::boxing::Integer::operator-(const ls::std::boxing::Integer &_integer) const
{
  return this->value - _integer;
}

int ls::std::boxing::Integer::operator-(int _value) const
{
  return this->value - _value;
}

int ls::std::boxing::Integer::operator/(const ls::std::boxing::Integer &_integer) const
{
  if (_integer == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _integer;
}

int ls::std::boxing::Integer::operator/(int _value) const
{
  if (_value == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _value;
}

int ls::std::boxing::Integer::operator%(const ls::std::boxing::Integer &_integer) const
{
  return this->value % _integer;
}

int ls::std::boxing::Integer::operator%(int _value) const
{
  return this->value % _value;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator+=(const ls::std::boxing::Integer &_integer)
{
  this->value += _integer;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator+=(int _value)
{
  this->value += _value;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator-=(const ls::std::boxing::Integer &_integer)
{
  this->value -= _integer;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator-=(int _value)
{
  this->value -= _value;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator*=(const ls::std::boxing::Integer &_integer)
{
  this->value *= _integer;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator*=(int _value)
{
  this->value *= _value;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator/=(const ls::std::boxing::Integer &_integer)
{
  if (_integer == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _integer;
  return *this;
}

ls::std::boxing::Integer &ls::std::boxing::Integer::operator/=(int _value)
{
  if (_value == 0)
  {
    throw ls::std::core::IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _value;
  return *this;
}

bool ls::std::boxing::Integer::operator==(const ls::std::boxing::Integer &_integer) const
{
  return this->value == _integer;
}

bool ls::std::boxing::Integer::operator==(int _value) const
{
  return this->value == _value;
}

bool ls::std::boxing::Integer::operator!=(const ls::std::boxing::Integer &_integer) const
{
  return this->value != _integer;
}

bool ls::std::boxing::Integer::operator!=(int _value) const
{
  return this->value != _value;
}

bool ls::std::boxing::Integer::operator>(const ls::std::boxing::Integer &_integer) const
{
  return this->value > _integer;
}

bool ls::std::boxing::Integer::operator>(int _value) const
{
  return this->value > _value;
}

bool ls::std::boxing::Integer::operator>=(const ls::std::boxing::Integer &_integer) const
{
  return this->value >= _integer;
}

bool ls::std::boxing::Integer::operator>=(int _value) const
{
  return this->value >= _value;
}

bool ls::std::boxing::Integer::operator<(const ls::std::boxing::Integer &_integer) const
{
  return this->value < _integer;
}

bool ls::std::boxing::Integer::operator<(int _value) const
{
  return this->value < _value;
}

bool ls::std::boxing::Integer::operator<=(const ls::std::boxing::Integer &_integer) const
{
  return this->value <= _integer;
}

bool ls::std::boxing::Integer::operator<=(int _value) const
{
  return this->value <= _value;
}

bool ls::std::boxing::Integer::operator&&(const ls::std::boxing::Integer &_integer) const
{
  return this->value && _integer;
}

bool ls::std::boxing::Integer::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls::std::boxing::Integer::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls::std::boxing::Integer::operator||(const ls::std::boxing::Integer &_integer) const
{
  return this->value || _integer;
}

bool ls::std::boxing::Integer::operator||(int _value) const
{
  return this->value || _value;
}

bool ls::std::boxing::Integer::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls::std::boxing::Integer::operator++()
{
  this->value += 1;
}

void ls::std::boxing::Integer::operator--()
{
  this->value -= 1;
}

void ls::std::boxing::Integer::parse(::std::string _parseText)
{
  this->value = ::std::stoi(_parseText);
}

std::string ls::std::boxing::Integer::toString()
{
  return ::std::to_string(this->value);
}

int ls::std::boxing::Integer::getValue() const
{
  return this->value;
}
