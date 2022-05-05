/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2022-05-05
 *
 * */

#include <algorithm>
#include <ls_std/boxing/Boolean.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::Boolean::Boolean() : ls::Class("Boolean")
{}

ls::Boolean::Boolean(bool _value)
    : ls::Class("Boolean"),
      value(_value)
{}

ls::Boolean::operator bool() const
{
  return this->value;
}

ls::Boolean &ls::Boolean::operator=(int _value)
{
  this->value = _value;
  return *this;
}

ls::Boolean &ls::Boolean::operator=(bool _value)
{
  this->value = _value;
  return *this;
}

bool ls::Boolean::operator&&(const ls::Boolean &_boolean) const
{
  return this->value && _boolean;
}

bool ls::Boolean::operator&&(bool _value) const
{
  return this->value && _value;
}

bool ls::Boolean::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls::Boolean::operator||(const ls::Boolean &_boolean) const
{
  return this->value || _boolean;
}

bool ls::Boolean::operator||(bool _value) const
{
  return this->value || _value;
}

bool ls::Boolean::operator||(int _value) const
{
  return this->value || _value;
}

void ls::Boolean::parse(std::string _parseText)
{
  std::transform(_parseText.begin(), _parseText.end(), _parseText.begin(), ::tolower);

  if (_parseText != this->TRUE_STRING && _parseText != this->FALSE_STRING)
  {
    throw ls::IllegalArgumentException{};
  }
  else
  {
    if (_parseText == this->TRUE_STRING)
    {
      this->value = true;
    }

    if (_parseText == this->FALSE_STRING)
    {
      this->value = false;
    }
  }
}

std::string ls::Boolean::toString()
{
  return this->_toString();
}

bool ls::Boolean::getValue() const
{
  return this->value;
}

bool ls::Boolean::XOR(const ls::Boolean &_leftExpression, const ls::Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::Boolean::XOR(const ls::Boolean &_leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::Boolean::XOR(bool _leftExpression, const ls::Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::Boolean::XOR(bool _leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

std::string ls::Boolean::_toString() const
{
  std::string booleanString{};

  if (this->value)
  {
    booleanString = this->TRUE_STRING;
  }
  else
  {
    booleanString = this->FALSE_STRING;
  }

  return booleanString;
}
