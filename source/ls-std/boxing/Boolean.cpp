/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2023-02-23
 *
 * */

#include <algorithm>
#include <ls-std/boxing/Boolean.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

using ls::std::boxing::Boolean;
using ls::std::core::Class;
using ls::std::core::IllegalArgumentException;
using std::string;
using std::transform;

Boolean::Boolean(bool _value) : Boolean()
{
  this->value = _value;
}

Boolean::Boolean() : Class("Boolean")
{}

Boolean::~Boolean() noexcept = default;

Boolean &Boolean::operator=(int _value)
{
  this->value = _value;
  return *this;
}

Boolean &Boolean::operator=(bool _value)
{
  this->value = _value;
  return *this;
}

bool Boolean::operator&&(const Boolean &_boolean) const
{
  return this->value && _boolean.getValue();
}

bool Boolean::operator&&(bool _value) const
{
  return this->value && _value;
}

bool Boolean::operator&&(int _value) const
{
  return this->value && _value;
}

bool Boolean::operator||(const Boolean &_boolean) const
{
  return this->value || _boolean.getValue();
}

bool Boolean::operator||(bool _value) const
{
  return this->value || _value;
}

bool Boolean::operator||(int _value) const
{
  return this->value || _value;
}

void Boolean::parse(string _parseText)
{
  transform(_parseText.begin(), _parseText.end(), _parseText.begin(), ::tolower);

  if (_parseText != this->TRUE_STRING && _parseText != this->FALSE_STRING)
  {
    throw IllegalArgumentException{_parseText + " is not a valid string representation"};
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

string Boolean::toString()
{
  return this->_toString();
}

bool Boolean::getValue() const
{
  return this->value;
}

bool Boolean::XOR(const Boolean &_leftExpression, const Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression.getValue());
}

bool Boolean::XOR(const Boolean &_leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool Boolean::XOR(bool _leftExpression, const Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression.getValue());
}

bool Boolean::XOR(bool _leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

string Boolean::_toString() const
{
  string booleanString{};

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
