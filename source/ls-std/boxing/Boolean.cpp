/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2023-02-04
 *
 * */

#include <algorithm>
#include <ls-std/boxing/Boolean.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>

ls::std::boxing::Boolean::Boolean(bool _value)
    : ls::std::core::Class("Boolean"),
      value(_value)
{}

ls::std::boxing::Boolean::Boolean() : ls::std::core::Class("Boolean")
{}

ls::std::boxing::Boolean::~Boolean() = default;

ls::std::boxing::Boolean::operator bool() const
{
  return this->value;
}

ls::std::boxing::Boolean &ls::std::boxing::Boolean::operator=(int _value)
{
  this->value = _value;
  return *this;
}

ls::std::boxing::Boolean &ls::std::boxing::Boolean::operator=(bool _value)
{
  this->value = _value;
  return *this;
}

bool ls::std::boxing::Boolean::operator&&(const ls::std::boxing::Boolean &_boolean) const
{
  return this->value && _boolean;
}

bool ls::std::boxing::Boolean::operator&&(bool _value) const
{
  return this->value && _value;
}

bool ls::std::boxing::Boolean::operator&&(int _value) const
{
  return this->value && _value;
}

bool ls::std::boxing::Boolean::operator||(const ls::std::boxing::Boolean &_boolean) const
{
  return this->value || _boolean;
}

bool ls::std::boxing::Boolean::operator||(bool _value) const
{
  return this->value || _value;
}

bool ls::std::boxing::Boolean::operator||(int _value) const
{
  return this->value || _value;
}

void ls::std::boxing::Boolean::parse(::std::string _parseText)
{
  ::std::transform(_parseText.begin(), _parseText.end(), _parseText.begin(), ::tolower);

  if (_parseText != this->TRUE_STRING && _parseText != this->FALSE_STRING)
  {
    throw ls::std::core::IllegalArgumentException{};
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

::std::string ls::std::boxing::Boolean::toString()
{
  return this->_toString();
}

bool ls::std::boxing::Boolean::getValue() const
{
  return this->value;
}

bool ls::std::boxing::Boolean::XOR(const ls::std::boxing::Boolean &_leftExpression, const ls::std::boxing::Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::std::boxing::Boolean::XOR(const ls::std::boxing::Boolean &_leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::std::boxing::Boolean::XOR(bool _leftExpression, const ls::std::boxing::Boolean &_rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

bool ls::std::boxing::Boolean::XOR(bool _leftExpression, bool _rightExpression)
{
  return (_leftExpression && !_rightExpression) || (!_leftExpression && _rightExpression);
}

::std::string ls::std::boxing::Boolean::_toString() const
{
  ::std::string booleanString{};

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
