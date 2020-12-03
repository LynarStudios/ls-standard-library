/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-11-26
 *
 * */

#include <ls_std/boxing/Integer.hpp>
#include <ls_std/exception/IllegalArithmeticOperationException.hpp>

ls_std::Integer::Integer(int _value) : ls_std::Class("Integer"),
value(_value)
{}

ls_std::Integer::Integer() : ls_std::Class("Integer")
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

int ls_std::Integer::operator+(const ls_std::Integer &_integer) const
{
  return this->value + _integer;
}

int ls_std::Integer::operator+(int _value) const
{
  return this->value + _value;
}

int ls_std::Integer::operator*(const ls_std::Integer &_integer) const
{
  return this->value * _integer;
}

int ls_std::Integer::operator*(int _value) const
{
  return this->value * _value;
}

int ls_std::Integer::operator-(const ls_std::Integer &_integer) const
{
  return this->value - _integer;
}

int ls_std::Integer::operator-(int _value) const
{
  return this->value - _value;
}

int ls_std::Integer::operator/(const ls_std::Integer &_integer) const
{
  if(_integer == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _integer;
}

int ls_std::Integer::operator/(int _value) const
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  return this->value / _value;
}

int ls_std::Integer::operator%(const ls_std::Integer &_integer) const
{
  return this->value % _integer;
}

int ls_std::Integer::operator%(int _value) const
{
  return this->value % _value;
}

ls_std::Integer & ls_std::Integer::operator+=(const ls_std::Integer &_integer)
{
  this->value += _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator+=(int _value)
{
  this->value += _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator-=(const ls_std::Integer &_integer)
{
  this->value -= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator-=(int _value)
{
  this->value -= _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator*=(const ls_std::Integer &_integer)
{
  this->value *= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator*=(int _value)
{
  this->value *= _value;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator/=(const ls_std::Integer &_integer)
{
  if(_integer == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _integer;
  return *this;
}

ls_std::Integer & ls_std::Integer::operator/=(int _value)
{
  if(_value == 0) {
    throw ls_std::IllegalArithmeticOperationException {};
  }

  this->value /= _value;
  return *this;
}

bool ls_std::Integer::operator==(const ls_std::Integer &_integer) const
{
  return this->value == _integer;
}

bool ls_std::Integer::operator==(int _value) const
{
  return this->value == _value;
}

bool ls_std::Integer::operator!=(const ls_std::Integer &_integer) const
{
  return this->value != _integer;
}

bool ls_std::Integer::operator!=(int _value) const
{
  return this->value != _value;
}

bool ls_std::Integer::operator>(const ls_std::Integer &_integer) const
{
  return this->value > _integer;
}

bool ls_std::Integer::operator>(int _value) const
{
  return this->value > _value;
}

bool ls_std::Integer::operator>=(const ls_std::Integer &_integer) const
{
  return this->value >= _integer;
}

bool ls_std::Integer::operator>=(int _value) const
{
  return this->value >= _value;
}

bool ls_std::Integer::operator<(const ls_std::Integer &_integer) const
{
  return this->value < _integer;
}

bool ls_std::Integer::operator<(int _value) const
{
  return this->value < _value;
}

bool ls_std::Integer::operator<=(const ls_std::Integer &_integer) const
{
  return this->value <= _integer;
}

bool ls_std::Integer::operator<=(int _value) const
{
  return this->value <= _value;
}

bool ls_std::Integer::operator&&(const ls_std::Integer &_integer) const
{
  return this->value && _integer;
}

bool ls_std::Integer::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls_std::Integer::operator&&(bool _expression) const
{
  return this->value && _expression;
}

bool ls_std::Integer::operator||(const ls_std::Integer &_integer) const
{
  return this->value || _integer;
}

bool ls_std::Integer::operator||(int _value) const
{
  return this->value || _value;
}

bool ls_std::Integer::operator||(bool _expression) const
{
  return this->value || _expression;
}

void ls_std::Integer::operator++()
{
  this->value += 1;
}

void ls_std::Integer::operator--()
{
  this->value -= 1;
}

ls_std::byte_field ls_std::Integer::load()
{
  ls_std::byte_field data {};

  if(this->storable != nullptr && this->serializable != nullptr) {
    data = this->storable->load();
    this->serializable->unmarshal(data);
  }

  return data;
}

ls_std::byte_field ls_std::Integer::marshal()
{
  ls_std::byte_field data {};

  if(this->serializable != nullptr) {
    data = this->serializable->marshal();
  }

  return data;
}

void ls_std::Integer::parse(std::string _parseText)
{
  this->value = std::stoi(_parseText);
}

void ls_std::Integer::save(const ls_std::byte_field& _data)
{
  if(this->serializable != nullptr) {
    if(_data.empty()) {
      this->storable->save(this->serializable->marshal());
    } else {
      this->storable->save(_data);
    }
  }
}

std::string ls_std::Integer::toString()
{
  return std::to_string(this->value);
}

void ls_std::Integer::unmarshal(const ls_std::byte_field& _data)
{
  if(this->serializable != nullptr) {
    this->serializable->unmarshal(_data);
  }
}

int ls_std::Integer::getValue() const {
  return this->value;
}

void ls_std::Integer::setSerializable(std::shared_ptr<ISerializable> _serializable)
{
  this->serializable = std::move(_serializable);
}

void ls_std::Integer::setStorable(std::shared_ptr<IStorable> _storable)
{
  this->storable = std::move(_storable);
}
