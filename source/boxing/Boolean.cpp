/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-08-14
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

void ls_std::Boolean::parse(std::string parseText)
{
  std::transform(parseText.begin(), parseText.end(), parseText.begin(), ::tolower);

  if(parseText != this->TRUE_STRING && parseText != this->FALSE_STRING) {
    throw ls_std::IllegalArgumentException {};
  } else {
    if(parseText == this->TRUE_STRING) {
      this->value = true;
    }

    if(parseText == this->FALSE_STRING) {
      this->value = false;
    }
  }
}

std::string ls_std::Boolean::toString()
{
  return this->_toString();
}

bool ls_std::Boolean::getValue() {
  return this->value;
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
