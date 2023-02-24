/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-23
 *
 * */

#include <cmath>
#include <ls-std/boxing/Double.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::boxing::Double;
using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using std::fabs;
using std::stod;
using std::string;
using std::to_string;

Double::Double() : Class("Double")
{
  this->_assignEpsilon(0.00000001);
}

Double::Double(double _value) : Double()
{
  this->value = _value;
}

Double::~Double() noexcept = default;

Double &Double::operator=(double _value)
{
  this->value = _value;
  return *this;
}

double Double::operator-() const
{
  return -this->value;
}

double Double::operator+(const Double &_double) const
{
  return this->value + _double.getValue();
}

double Double::operator+(double _value) const
{
  return this->value + _value;
}

double Double::operator*(const Double &_double) const
{
  return this->value * _double.getValue();
}

double Double::operator*(double _value) const
{
  return this->value * _value;
}

double Double::operator-(const Double &_double) const
{
  return this->value - _double.getValue();
}

double Double::operator-(double _value) const
{
  return this->value - _value;
}

double Double::operator/(const Double &_double) const
{
  return this->value / _double.getValue();
}

double Double::operator/(double _value) const
{
  return this->value / _value;
}

Double &Double::operator+=(const Double &_double)
{
  this->value += _double.getValue();
  return *this;
}

Double &Double::operator+=(double _value)
{
  this->value += _value;
  return *this;
}

Double &Double::operator-=(const Double &_double)
{
  this->value -= _double.getValue();
  return *this;
}

Double &Double::operator-=(double _value)
{
  this->value -= _value;
  return *this;
}

Double &Double::operator*=(const Double &_double)
{
  this->value *= _double.getValue();
  return *this;
}

Double &Double::operator*=(double _value)
{
  this->value *= _value;
  return *this;
}

Double &Double::operator/=(const Double &_double)
{
  this->value /= _double.getValue();
  return *this;
}

Double &Double::operator/=(double _value)
{
  this->value /= _value;
  return *this;
}

bool Double::operator==(const Double &_double) const
{
  return fabs(this->value - _double.getValue()) < this->epsilon;
}

bool Double::operator==(double _value) const
{
  return fabs(this->value - _value) < this->epsilon;
}

bool Double::operator!=(const Double &_double) const
{
  return fabs(this->value - _double.getValue()) >= this->epsilon;
}

bool Double::operator!=(double _value) const
{
  return fabs(this->value - _value) >= this->epsilon;
}

bool Double::operator>(const Double &_double) const
{
  return this->value > _double.getValue();
}

bool Double::operator>(double _value) const
{
  return this->value > _value;
}

bool Double::operator>=(const Double &_double) const
{
  return this->value >= _double.getValue();
}

bool Double::operator>=(double _value) const
{
  return this->value >= _value;
}

bool Double::operator<(const Double &_double) const
{
  return this->value < _double.getValue();
}

bool Double::operator<(double _value) const
{
  return this->value < _value;
}

bool Double::operator<=(const Double &_double) const
{
  return this->value <= _double.getValue();
}

bool Double::operator<=(double _value) const
{
  return this->value <= _value;
}

void Double::operator++()
{
  this->value += 1.0f;
}

void Double::operator--()
{
  this->value -= 1.0f;
}

void Double::parse(string _parseText)
{
  this->value = stod(_parseText);
}

string Double::toString()
{
  return to_string(this->value);
}

double Double::getEpsilon() const
{
  return this->epsilon;
}

double Double::getValue() const
{
  return this->value;
}

void Double::setEpsilon(double _epsilon)
{
  this->_assignEpsilon(_epsilon);
}

void Double::_assignEpsilon(double _epsilon)
{
  if (_epsilon <= 0.0)
  {
    throw IllegalArgumentException{"_epsilon is less than or equal zero"};
  }

  this->epsilon = _epsilon;
}
