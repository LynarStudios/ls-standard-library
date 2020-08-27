/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-27
 *
 * */

#include "Long.hpp"

#include <utility>
#include "../exception/IllegalArithmeticOperationException.hpp"

ls_std::Long::Long(ls_std::long_type _value) : Class("Long"),
value(_value)
{}

ls_std::Long::Long() : Class("Long")
{}

ls_std::Long::operator ls_std::long_type() const
{
  return this->value;
}

ls_std::Long& ls_std::Long::operator=(ls_std::long_type _value)
{
  this->value = _value;
  return *this;
}

ls_std::long_type ls_std::Long::operator-() const
{
  return -this->value;
}

ls_std::long_type ls_std::Long::operator+(const Long &_long) const
{
  return this->value + _long;
}

ls_std::long_type ls_std::Long::operator+(ls_std::long_type _value) const
{
  return this->value + _value;
}

ls_std::long_type ls_std::Long::operator*(const Long &_long) const
{
  return this->value * _long;
}

ls_std::long_type ls_std::Long::operator*(ls_std::long_type _value) const
{
  return this->value * _value;
}

ls_std::long_type ls_std::Long::operator-(const Long &_long) const
{
  return this->value - _long;
}

ls_std::long_type ls_std::Long::operator-(ls_std::long_type _value) const
{
  return this->value - _value;
}

ls_std::long_type ls_std::Long::operator/(const Long &_long) const
{
  if(_long == (ls_std::long_type) 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _long;
}

ls_std::long_type ls_std::Long::operator/(ls_std::long_type _value) const
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _value;
}

ls_std::long_type ls_std::Long::operator%(const Long &_long) const
{
  return this->value % _long;
}

ls_std::long_type ls_std::Long::operator%(ls_std::long_type _value) const
{
  return this->value % _value;
}

ls_std::Long & ls_std::Long::operator+=(const Long &_long)
{
  this->value += _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator+=(ls_std::long_type _value)
{
  this->value += _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator-=(const Long &_long)
{
  this->value -= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator-=(ls_std::long_type _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator*=(const Long &_long)
{
  this->value *= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator*=(ls_std::long_type _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Long & ls_std::Long::operator/=(const Long &_long)
{
  if(_long == (ls_std::long_type) 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _long;
  return *this;
}

ls_std::Long & ls_std::Long::operator/=(ls_std::long_type _value)
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _value;
  return *this;
}

bool ls_std::Long::operator==(const Long &_long) const
{
  return this->value == _long;
}

bool ls_std::Long::operator==(ls_std::long_type _value) const
{
  return this->value == _value;
}

bool ls_std::Long::operator!=(const Long &_long) const
{
  return this->value != _long;
}

bool ls_std::Long::operator!=(ls_std::long_type _value) const
{
  return this->value != _value;
}

bool ls_std::Long::operator>(const Long &_long) const
{
  return this->value > _long;
}

bool ls_std::Long::operator>(ls_std::long_type _value) const
{
  return this->value > _value;
}

bool ls_std::Long::operator>=(const Long &_long) const
{
  return this->value >= _long;
}

bool ls_std::Long::operator>=(ls_std::long_type _value) const
{
  return this->value >= _value;
}

bool ls_std::Long::operator<(const Long &_long) const
{
  return this->value < _long;
}

bool ls_std::Long::operator<(ls_std::long_type _value) const
{
  return this->value < _value;
}

bool ls_std::Long::operator<=(const Long &_long) const
{
  return this->value <= _long;
}

bool ls_std::Long::operator<=(ls_std::long_type _value) const
{
  return this->value <= _value;
}

bool ls_std::Long::operator&&(const Long &_long) const
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

bool ls_std::Long::operator||(const Long &_long) const
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

ls_std::byte_field ls_std::Long::load()
{
  ls_std::byte_field data {};

  if(this->storable != nullptr && this->serializable != nullptr) {
    data = this->storable->load();
    this->serializable->unmarshal(data);
  }

  return data;
}

ls_std::byte_field ls_std::Long::marshal()
{
  ls_std::byte_field data {};

  if(this->serializable != nullptr) {
    data = this->serializable->marshal();
  }

  return data;
}

void ls_std::Long::parse(std::string _parseText)
{
  this->value = std::stoi(_parseText);
}

void ls_std::Long::save(const ls_std::byte_field& _data)
{
  if(this->serializable != nullptr) {
    if(_data.empty()) {
      this->storable->save(this->serializable->marshal());
    } else {
      this->storable->save(_data);
    }
  }
}

std::string ls_std::Long::toString()
{
  return std::to_string(this->value);
}

void ls_std::Long::unmarshal(const ls_std::byte_field& _data)
{
  if(this->serializable != nullptr) {
    this->serializable->unmarshal(_data);
  }
}

ls_std::long_type ls_std::Long::getValue() const {
  return this->value;
}

void ls_std::Long::setSerializable(std::shared_ptr<ISerializable> _serializable) {
  this->serializable = std::move(_serializable);
}

void ls_std::Long::setStorable(std::shared_ptr<IStorable> _storable) {
  this->storable = std::move(_storable);
}
