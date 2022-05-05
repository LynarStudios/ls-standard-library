/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-05-05
 *
 * */

#include <ls_std/boxing/Integer.hpp>
#include <ls_std/core/exception/IllegalArithmeticOperationException.hpp>

ls::Integer::Integer(int _value)
    : ls::Class("Integer"),
      value(_value)
{}

ls::Integer::Integer() : ls::Class("Integer")
{}

ls::Integer::operator int() const
{
  return this->value;
}

ls::Integer &ls::Integer::operator=(int _value)
{
  this->value = _value;
  return *this;
}

int ls::Integer::operator-() const
{
  return -this->value;
}

int ls::Integer::operator+(const ls::Integer &_integer) const
{
  return this->value + _integer;
}

int ls::Integer::operator+(int _value) const
{
  return this->value + _value;
}

int ls::Integer::operator*(const ls::Integer &_integer) const
{
  return this->value * _integer;
}

int ls::Integer::operator*(int _value) const
{
  return this->value * _value;
}

int ls::Integer::operator-(const ls::Integer &_integer) const
{
  return this->value - _integer;
}

int ls::Integer::operator-(int _value) const
{
  return this->value - _value;
}

int ls::Integer::operator/(const ls::Integer &_integer) const
{
  if (_integer == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _integer;
}

int ls::Integer::operator/(int _value) const
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  return this->value / _value;
}

int ls::Integer::operator%(const ls::Integer &_integer) const
{
  return this->value % _integer;
}

int ls::Integer::operator%(int _value) const
{
  return this->value % _value;
}

ls::Integer &ls::Integer::operator+=(const ls::Integer &_integer)
{
  this->value += _integer;
  return *this;
}

ls::Integer &ls::Integer::operator+=(int _value)
{
  this->value += _value;
  return *this;
}

ls::Integer &ls::Integer::operator-=(const ls::Integer &_integer)
{
  this->value -= _integer;
  return *this;
}

ls::Integer &ls::Integer::operator-=(int _value)
{
  this->value -= _value;
  return *this;
}

ls::Integer &ls::Integer::operator*=(const ls::Integer &_integer)
{
  this->value *= _integer;
  return *this;
}

ls::Integer &ls::Integer::operator*=(int _value)
{
  this->value *= _value;
  return *this;
}

ls::Integer &ls::Integer::operator/=(const ls::Integer &_integer)
{
  if (_integer == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _integer;
  return *this;
}

ls::Integer &ls::Integer::operator/=(int _value)
{
  if (_value == 0)
  {
    throw ls::IllegalArithmeticOperationException{};
  }

  this->value /= _value;
  return *this;
}

bool ls::Integer::operator==(const ls::Integer &_integer) const
{
  return this->value == _integer;
}

bool ls::Integer::operator==(int _value) const
{
  return this->value == _value;
}

bool ls::Integer::operator!=(const ls::Integer &_integer) const
{
  return this->value != _integer;
}

bool ls::Integer::operator!=(int _value) const
{
  return this->value != _value;
}

bool ls::Integer::operator>(const ls::Integer &_integer) const
{
  return this->value > _integer;
}

bool ls::Integer::operator>(int _value) const
{
  return this->value > _value;
}

bool ls::Integer::operator>=(const ls::Integer &_integer) const
{
  return this->value >= _integer;
}

bool ls::Integer::operator>=(int _value) const
{
  return this->value >= _value;
}

bool ls::Integer::operator<(const ls::Integer &_integer) const
{
  return this->value < _integer;
}

bool ls::Integer::operator<(int _value) const
{
  return this->value < _value;
}

bool ls::Integer::operator<=(const ls::Integer &_integer) const
{
  return this->value <= _integer;
}

bool ls::Integer::operator<=(int _value) const
{
  return this->value <= _value;
}

bool ls::Integer::operator&&(const ls::Integer &_integer) const
{
  return this->value && _integer;
}

bool ls::Integer::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls::Integer::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls::Integer::operator||(const ls::Integer &_integer) const
{
  return this->value || _integer;
}

bool ls::Integer::operator||(int _value) const
{
  return this->value || _value;
}

bool ls::Integer::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls::Integer::operator++()
{
  this->value += 1;
}

void ls::Integer::operator--()
{
  this->value -= 1;
}

void ls::Integer::parse(std::string _parseText)
{
  this->value = std::stoi(_parseText);
}

std::string ls::Integer::toString()
{
  return std::to_string(this->value);
}

int ls::Integer::getValue() const
{
  return this->value;
}
