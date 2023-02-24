/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-23
 *
 * */

#include <ls-std/boxing/Integer.hpp>
#include <ls-std/core/exception/IllegalArithmeticOperationException.hpp>

using ls::std::boxing::Integer;
using ls::std::core::Class;
using ls::std::core::IllegalArithmeticOperationException;
using std::stoi;
using std::string;
using std::to_string;

Integer::Integer(int _value) : Integer()
{
  this->value = _value;
}

Integer::Integer() : Class("Integer")
{}

Integer::~Integer() noexcept = default;

Integer &Integer::operator=(int _value)
{
  this->value = _value;
  return *this;
}

int Integer::operator-() const
{
  return -this->value;
}

int Integer::operator+(const Integer &_integer) const
{
  return this->value + _integer.getValue();
}

int Integer::operator+(int _value) const
{
  return this->value + _value;
}

int Integer::operator*(const Integer &_integer) const
{
  return this->value * _integer.getValue();
}

int Integer::operator*(int _value) const
{
  return this->value * _value;
}

int Integer::operator-(const Integer &_integer) const
{
  return this->value - _integer.getValue();
}

int Integer::operator-(int _value) const
{
  return this->value - _value;
}

int Integer::operator/(const Integer &_integer) const
{
  if (_integer == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _integer.getValue();
}

int Integer::operator/(int _value) const
{
  if (_value == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  return this->value / _value;
}

int Integer::operator%(const Integer &_integer) const
{
  return this->value % _integer.getValue();
}

int Integer::operator%(int _value) const
{
  return this->value % _value;
}

Integer &Integer::operator+=(const Integer &_integer)
{
  this->value += _integer.getValue();
  return *this;
}

Integer &Integer::operator+=(int _value)
{
  this->value += _value;
  return *this;
}

Integer &Integer::operator-=(const Integer &_integer)
{
  this->value -= _integer.getValue();
  return *this;
}

Integer &Integer::operator-=(int _value)
{
  this->value -= _value;
  return *this;
}

Integer &Integer::operator*=(const Integer &_integer)
{
  this->value *= _integer.getValue();
  return *this;
}

Integer &Integer::operator*=(int _value)
{
  this->value *= _value;
  return *this;
}

Integer &Integer::operator/=(const Integer &_integer)
{
  if (_integer == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _integer.getValue();
  return *this;
}

Integer &Integer::operator/=(int _value)
{
  if (_value == 0)
  {
    throw IllegalArithmeticOperationException{"division by zero is not allowed"};
  }

  this->value /= _value;
  return *this;
}

bool Integer::operator==(const Integer &_integer) const
{
  return this->value == _integer.getValue();
}

bool Integer::operator==(int _value) const
{
  return this->value == _value;
}

bool Integer::operator!=(const Integer &_integer) const
{
  return this->value != _integer.getValue();
}

bool Integer::operator!=(int _value) const
{
  return this->value != _value;
}

bool Integer::operator>(const Integer &_integer) const
{
  return this->value > _integer.getValue();
}

bool Integer::operator>(int _value) const
{
  return this->value > _value;
}

bool Integer::operator>=(const Integer &_integer) const
{
  return this->value >= _integer.getValue();
}

bool Integer::operator>=(int _value) const
{
  return this->value >= _value;
}

bool Integer::operator<(const Integer &_integer) const
{
  return this->value < _integer.getValue();
}

bool Integer::operator<(int _value) const
{
  return this->value < _value;
}

bool Integer::operator<=(const Integer &_integer) const
{
  return this->value <= _integer.getValue();
}

bool Integer::operator<=(int _value) const
{
  return this->value <= _value;
}

bool Integer::operator&&(const Integer &_integer) const
{
  return this->value && _integer.getValue();
}

bool Integer::operator&&(int _value) const
{
  return this->value && _value;
}

bool Integer::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool Integer::operator||(const Integer &_integer) const
{
  return this->value || _integer.getValue();
}

bool Integer::operator||(int _value) const
{
  return this->value || _value;
}

bool Integer::operator||(bool _expression) const
{
  return this->value || _expression;
}

void Integer::operator++()
{
  this->value += 1;
}

void Integer::operator--()
{
  this->value -= 1;
}

void Integer::parse(string _parseText)
{
  this->value = stoi(_parseText);
}

string Integer::toString()
{
  return to_string(this->value);
}

int Integer::getValue() const
{
  return this->value;
}
