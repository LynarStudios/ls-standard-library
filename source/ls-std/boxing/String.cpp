/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-22
 *
 * */

#include <algorithm>
#include <ls-std/boxing/String.hpp>

ls::std::boxing::String::String() : ls::std::core::Class("String")
{}

ls::std::boxing::String::String(::std::string _value) : ls::std::core::Class("String"), value(::std::move(_value))
{}

ls::std::boxing::String::~String() = default;

ls::std::boxing::String &ls::std::boxing::String::operator=(::std::string _value)
{
  this->value = ::std::move(_value);
  return *this;
}

::std::string ls::std::boxing::String::operator+(ls::std::boxing::String _string) const
{
  return this->value + _string.toString();
}

::std::string ls::std::boxing::String::operator+(const ::std::string &_string) const
{
  return this->value + _string;
}

::std::string ls::std::boxing::String::operator+(const char *_string) const
{
  return this->value + _string;
}

::std::string ls::std::boxing::String::operator-(int _number)
{
  ::std::string copy = this->value;
  return copy.substr(0, copy.size() - _number);
}

ls::std::boxing::String &ls::std::boxing::String::operator+=(ls::std::boxing::String _string)
{
  this->value = this->value + _string.toString();
  return *this;
}

ls::std::boxing::String &ls::std::boxing::String::operator+=(const ::std::string &_text)
{
  this->value = this->value + _text;
  return *this;
}

bool ls::std::boxing::String::operator==(ls::std::boxing::String _string)
{
  return this->value == _string.toString();
}

bool ls::std::boxing::String::operator==(const ::std::string &_value)
{
  return this->value == _value;
}

bool ls::std::boxing::String::operator==(const char *_value)
{
  return this->value == _value;
}

bool ls::std::boxing::String::operator!=(ls::std::boxing::String _string)
{
  return this->value != _string.toString();
}

bool ls::std::boxing::String::operator!=(const ::std::string &_value)
{
  return this->value != _value;
}

bool ls::std::boxing::String::operator!=(const char *_value)
{
  return this->value != _value;
}

void ls::std::boxing::String::parse(::std::string _parseText)
{
  this->value = ::std::move(_parseText);
}

::std::string ls::std::boxing::String::toString()
{
  return this->value;
}

bool ls::std::boxing::String::contains(const ::std::string &_text)
{
  return this->value.find(_text) != ::std::string::npos;
}

bool ls::std::boxing::String::endsWith(const ::std::string &_text)
{
  return this->value.rfind(_text) == (this->value.size() - _text.size());
}

bool ls::std::boxing::String::equalsIgnoreCase(ls::std::boxing::String _string)
{
  return this->toLowerCase() == _string.toLowerCase();
}

bool ls::std::boxing::String::equalsIgnoreCase(::std::string _text)
{
  return this->toLowerCase() == ls::std::boxing::String{::std::move(_text)}.toLowerCase();
}

::std::vector<ls::std::core::type::byte> ls::std::boxing::String::getByteData()
{
  ::std::vector<ls::std::core::type::byte> byteData(this->value.begin(), this->value.end());
  byteData.push_back('\0');

  return byteData;
}

::std::string ls::std::boxing::String::padLeft(size_t _width, const char _fillCharacter)
{
  return ls::std::boxing::String::_createFillContent(this->value, _width, _fillCharacter) + this->value;
}

::std::string ls::std::boxing::String::padRight(size_t _width, const char _fillCharacter)
{
  return this->value + ls::std::boxing::String::_createFillContent(this->value, _width, _fillCharacter);
}

::std::string ls::std::boxing::String::reverse()
{
  ::std::string copy = this->value;
  ::std::reverse(copy.begin(), copy.end());

  return copy;
}

bool ls::std::boxing::String::startsWith(const ::std::string &_text)
{
  return this->value.rfind(_text, 0) == 0;
}

::std::string ls::std::boxing::String::toLowerCase()
{
  ::std::string copy = this->value;
  ::std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

  return copy;
}

::std::string ls::std::boxing::String::toUpperCase()
{
  ::std::string copy = this->value;
  ::std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);

  return copy;
}

::std::string ls::std::boxing::String::_buildCharacterChain(size_t _amount, const char _fillCharacter)
{
  ::std::string fillContent{};

  for (size_t iteration{}; iteration < _amount; iteration++) { fillContent += _fillCharacter; }

  return fillContent;
}

::std::string ls::std::boxing::String::_createFillContent(const ::std::string &_text, size_t _width, const char _fillCharacter)
{
  size_t fillSize = _text.size() > _width ? 0 : _width - _text.size();
  ::std::string fillContent{};

  if (fillSize > 0)
  {
    fillContent = ls::std::boxing::String::_buildCharacterChain(fillSize, _fillCharacter);
  }

  return fillContent;
}
