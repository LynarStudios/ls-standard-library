/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-09-04
 *
 * */

#include <algorithm>
#include "Boolean.hpp"
#include "../exception/IllegalArgumentException.hpp"

ls_std::Boolean::Boolean() : Class("Boolean")
{}

ls_std::Boolean::Boolean(bool _value) : Class("Boolean"),
value(_value)
{}

ls_std::Boolean::operator bool() const
{
  return this->value;
}

ls_std::Boolean & ls_std::Boolean::operator=(int _value)
{
  this->value = _value;
  return *this;
}

ls_std::Boolean & ls_std::Boolean::operator=(bool _value)
{
  this->value = _value;
  return *this;
}

bool ls_std::Boolean::operator&&(const Boolean &_boolean) const
{
  return this->value && _boolean;
}

bool ls_std::Boolean::operator&&(bool _value) const
{
  return this->value && _value;
}

bool ls_std::Boolean::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls_std::Boolean::operator||(const Boolean &_boolean) const
{
  return this->value || _boolean;
}

bool ls_std::Boolean::operator||(bool _value) const
{
  return this->value || _value;
}

bool ls_std::Boolean::operator||(int _value) const
{
  return this->value || _value;
}

ls_std::byte_field ls_std::Boolean::marshal() {
  ls_std::byte_field data {};

  if(this->serializable != nullptr) {
    data = this->serializable->marshal();
  }

  return data;
}

void ls_std::Boolean::parse(std::string _parseText)
{
  std::transform(_parseText.begin(), _parseText.end(), _parseText.begin(), ::tolower);

  if(_parseText != this->TRUE_STRING && _parseText != this->FALSE_STRING) {
    throw ls_std::IllegalArgumentException {};
  } else {
    if(_parseText == this->TRUE_STRING) {
      this->value = true;
    }

    if(_parseText == this->FALSE_STRING) {
      this->value = false;
    }
  }
}

std::string ls_std::Boolean::toString()
{
  return this->_toString();
}

void ls_std::Boolean::unmarshal(const ls_std::byte_field &_data) {
  if(this->serializable != nullptr) {
    this->serializable->unmarshal(_data);
  }
}

bool ls_std::Boolean::getValue() {
  return this->value;
}

void ls_std::Boolean::setSerializable(std::shared_ptr<ISerializable> _serializable) {
  this->serializable = std::move(_serializable);
}

bool ls_std::Boolean::XOR(const Boolean &_leftExpression, const Boolean &_rightExpression) {
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls_std::Boolean::XOR(const Boolean &_leftExpression, bool _rightExpression) {
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls_std::Boolean::XOR(bool _leftExpression, const Boolean &_rightExpression) {
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls_std::Boolean::XOR(bool _leftExpression, bool _rightExpression) {
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

std::string ls_std::Boolean::_toString() const
{
  std::string booleanString {};

  if(this->value) {
    booleanString = this->TRUE_STRING;
  } else {
    booleanString = this->FALSE_STRING;
  }

  return booleanString;
}
