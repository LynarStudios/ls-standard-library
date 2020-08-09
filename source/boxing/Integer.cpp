/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-08-09
 *
 * */

#include "Integer.hpp"
#include "../exception/IllegalOperationException.hpp"

ls_std::Integer::Integer(int _value) : Class("Integer"),
value(_value)
{}

ls_std::Integer::Integer() : Class("Integer")
{}

ls_std::Integer::operator int() const
{
  return this->value;
}

ls_std::Integer& ls_std::Integer::operator=(int _value)
{
  this->value = _value;
  return *this;
}

int ls_std::Integer::operator-() const
{
  return -this->value;
}

int ls_std::Integer::operator+(const Integer &_integer) const
{
  return this->value + _integer;
}

int ls_std::Integer::operator+(int _value) const
{
  return this->value + _value;
}

int ls_std::Integer::operator*(const Integer &_integer) const
{
  return this->value * _integer;
}

int ls_std::Integer::operator*(int _value) const
{
  return this->value * _value;
}

int ls_std::Integer::operator-(const Integer &_integer) const
{
  return this->value - _integer;
}

int ls_std::Integer::operator-(int _value) const
{
  return this->value - _value;
}

int ls_std::Integer::operator/(const Integer &_integer) const
{
  if(_integer == 0) {
    throw ls_std::IllegalOperationException {};
  }

  return this->value / _integer;
}

int ls_std::Integer::operator/(int _value) const
{
  if(_value == 0) {
    throw ls_std::IllegalOperationException {};
  }

  return this->value / _value;
}

int ls_std::Integer::operator%(const Integer &_integer) const
{
  return this->value % _integer;
}

int ls_std::Integer::operator%(int _value) const
{
  return this->value % _value;
}

ls_std::Integer & ls_std::Integer::operator+=(const Integer &_integer)
{
  this->value += _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator+=(int _value)
{
  this->value += _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator-=(const Integer &_integer)
{
  this->value -= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator-=(int _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator*=(const Integer &_integer)
{
  this->value *= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator*=(int _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator/=(const Integer &_integer)
{
  if(_integer == 0) {
    throw ls_std::IllegalOperationException {};
  }

  this->value /= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator/=(int _value)
{
  if(_value == 0) {
    throw ls_std::IllegalOperationException {};
  }

  this->value /= _value;
  return *this;
}

bool ls_std::Integer::operator==(const Integer &_integer) const
{
  return this->value == _integer;
}

bool ls_std::Integer::operator==(int _value) const
{
  return this->value == _value;
}

bool ls_std::Integer::operator!=(const Integer &_integer) const
{
  return this->value != _integer;
}

bool ls_std::Integer::operator!=(int _value) const
{
  return this->value != _value;
}

bool ls_std::Integer::operator>(const Integer &_integer) const
{
  return this->value > _integer;
}

bool ls_std::Integer::operator>(int _value) const
{
  return this->value > _value;
}

bool ls_std::Integer::operator>=(const Integer &_integer) const
{
  return this->value >= _integer;
}

bool ls_std::Integer::operator>=(int _value) const
{
  return this->value >= _value;
}

bool ls_std::Integer::operator<(const Integer &_integer) const
{
  return this->value < _integer;
}

bool ls_std::Integer::operator<(int _value) const
{
  return this->value < _value;
}

bool ls_std::Integer::operator<=(const Integer &_integer) const
{
  return this->value <= _integer;
}

bool ls_std::Integer::operator<=(int _value) const
{
  return this->value <= _value;
}

bool ls_std::Integer::operator&&(const Integer &_integer) const
{
  return this->value && _integer;
}

bool ls_std::Integer::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls_std::Integer::operator&&(bool expression) const
{
  return this->value && expression;
}

bool ls_std::Integer::operator||(const Integer &_integer) const
{
  return this->value || _integer;
}

bool ls_std::Integer::operator||(int _value) const
{
  return this->value || _value;
}

bool ls_std::Integer::operator||(bool expression) const
{
  return this->value || expression;
}

void ls_std::Integer::operator++()
{
  this->value += 1;
}

void ls_std::Integer::operator--()
{
  this->value -= 1;
}

void ls_std::Integer::parse(std::string parseText)
{
  this->value = std::stoi(parseText);
}

std::string ls_std::Integer::toString()
{
  return std::to_string(this->value);
}
