/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#include <algorithm>
#include <ls_std/boxing/String.hpp>
#include <ls_std/core/exception/IllegalArgumentException.hpp>

ls::String::String() : ls::Class("String")
{}

ls::String::String(std::string _value)
    : ls::Class("String"),
      value(std::move(_value))
{}

ls::String::operator const char *() const
{
  return this->value.c_str();
}

ls::String::operator std::string() const
{
  return this->value;
}

ls::String &ls::String::operator=(std::string _value)
{
  this->value = std::move(_value);
  return *this;
}

std::string ls::String::operator+(ls::String _string) const
{
  return this->value + _string.toString();
}

std::string ls::String::operator+(const std::string &_string) const
{
  return this->value + _string;
}

std::string ls::String::operator+(const char *_string) const
{
  return this->value + _string;
}

std::string ls::String::operator-(int _number)
{
  std::string copy = this->value;
  return copy.substr(0, copy.size() - _number);
}

ls::String &ls::String::operator+=(ls::String _string)
{
  this->value = this->value + _string.toString();
  return *this;
}

ls::String &ls::String::operator+=(const std::string &_text)
{
  this->value = this->value + _text;
  return *this;
}

bool ls::String::operator==(ls::String _string)
{
  return this->value == _string.toString();
}

bool ls::String::operator==(const std::string &_value)
{
  return this->value == _value;
}

bool ls::String::operator==(const char *_value)
{
  return this->value == _value;
}

bool ls::String::operator!=(ls::String _string)
{
  return this->value != _string.toString();
}

bool ls::String::operator!=(const std::string &_value)
{
  return this->value != _value;
}

bool ls::String::operator!=(const char *_value)
{
  return this->value != _value;
}

void ls::String::parse(std::string _parseText)
{
  this->value = std::move(_parseText);
}

std::string ls::String::toString()
{
  return this->value;
}

bool ls::String::contains(const std::string &_text)
{
  return this->value.find(_text) != std::string::npos;
}

bool ls::String::endsWith(const std::string &_text)
{
  return this->value.rfind(_text) == (this->value.size() - _text.size());
}

bool ls::String::equalsIgnoreCase(ls::String _string)
{
  return this->toLowerCase() == _string.toLowerCase();
}

bool ls::String::equalsIgnoreCase(std::string _text)
{
  return this->toLowerCase() == ls::String{std::move(_text)}.toLowerCase();
}

std::vector<ls::byte> ls::String::getByteData()
{
  std::vector<ls::byte> byteData(this->value.begin(), this->value.end());
  byteData.push_back('\0');

  return byteData;
}

std::string ls::String::padLeft(size_t _width, const char _fillCharacter)
{
  return ls::String::_createFillContent(this->value, _width, _fillCharacter) + this->value;
}

std::string ls::String::padRight(size_t _width, const char _fillCharacter)
{
  return this->value + ls::String::_createFillContent(this->value, _width, _fillCharacter);
}

std::string ls::String::reverse()
{
  std::string copy = this->value;
  std::reverse(copy.begin(), copy.end());

  return copy;
}

bool ls::String::startsWith(const std::string &_text)
{
  return this->value.rfind(_text, 0) == 0;
}

std::string ls::String::toLowerCase()
{
  std::string copy = this->value;
  std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

  return copy;
}

std::string ls::String::toUpperCase()
{
  std::string copy = this->value;
  std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);

  return copy;
}

std::string ls::String::_buildCharacterChain(size_t _amount, const char _fillCharacter)
{
  std::string fillContent{};

  for (size_t iteration{}; iteration < _amount; iteration++)
  {
    fillContent += _fillCharacter;
  }

  return fillContent;
}

std::string ls::String::_createFillContent(const std::string &_text, size_t _width, const char _fillCharacter)
{
  size_t fillSize = _text.size() > _width ? 0 : _width - _text.size();
  std::string fillContent{};

  if (fillSize > 0)
  {
    fillContent = ls::String::_buildCharacterChain(fillSize, _fillCharacter);
  }

  return fillContent;
}
