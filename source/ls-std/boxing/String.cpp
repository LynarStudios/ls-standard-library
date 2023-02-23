/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-23
 *
 * */

#include <algorithm>
#include <ls-std/boxing/String.hpp>

using ls::std::boxing::String;
using ls::std::core::Class;
using ls::std::core::type::byte;
using std::move;
using std::reverse;
using std::string;
using std::transform;
using std::vector;

String::String() : Class("String")
{}

String::String(string _value) : String()
{
  this->value = ::move(_value);
}

String::~String() noexcept = default;

String &String::operator=(string _value)
{
  this->value = ::move(_value);
  return *this;
}

string String::operator+(String _string) const
{
  return this->value + _string.toString();
}

string String::operator+(const string &_string) const
{
  return this->value + _string;
}

string String::operator+(const char *_string) const
{
  return this->value + _string;
}

string String::operator-(int _number)
{
  string copy = this->value;
  return copy.substr(0, copy.size() - _number);
}

String &String::operator+=(String _string)
{
  this->value = this->value + _string.toString();
  return *this;
}

String &String::operator+=(const string &_text)
{
  this->value = this->value + _text;
  return *this;
}

bool String::operator==(String _string)
{
  return this->value == _string.toString();
}

bool String::operator==(const string &_value)
{
  return this->value == _value;
}

bool String::operator==(const char *_value)
{
  return this->value == _value;
}

bool String::operator!=(String _string)
{
  return this->value != _string.toString();
}

bool String::operator!=(const string &_value)
{
  return this->value != _value;
}

bool String::operator!=(const char *_value)
{
  return this->value != _value;
}

void String::parse(string _parseText)
{
  this->value = ::move(_parseText);
}

string String::toString()
{
  return this->value;
}

bool String::contains(const string &_text)
{
  return this->value.find(_text) != string::npos;
}

bool String::endsWith(const string &_text)
{
  return this->value.rfind(_text) == (this->value.size() - _text.size());
}

bool String::equalsIgnoreCase(String _string)
{
  return this->toLowerCase() == _string.toLowerCase();
}

bool String::equalsIgnoreCase(string _text)
{
  return this->toLowerCase() == String{::move(_text)}.toLowerCase();
}

vector<byte> String::getByteData()
{
  vector<byte> byteData(this->value.begin(), this->value.end());
  byteData.push_back('\0');

  return byteData;
}

string String::padLeft(size_t _width, const char _fillCharacter)
{
  return String::_createFillContent(this->value, _width, _fillCharacter) + this->value;
}

string String::padRight(size_t _width, const char _fillCharacter)
{
  return this->value + String::_createFillContent(this->value, _width, _fillCharacter);
}

string String::reverse()
{
  string copy = this->value;
  ::reverse(copy.begin(), copy.end());

  return copy;
}

bool String::startsWith(const string &_text)
{
  return this->value.rfind(_text, 0) == 0;
}

string String::toLowerCase()
{
  string copy = this->value;
  transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

  return copy;
}

string String::toUpperCase()
{
  string copy = this->value;
  transform(copy.begin(), copy.end(), copy.begin(), ::toupper);

  return copy;
}

string String::_buildCharacterChain(size_t _amount, const char _fillCharacter)
{
  string fillContent{};

  for (size_t iteration{}; iteration < _amount; iteration++)
  {
    fillContent += _fillCharacter;
  }

  return fillContent;
}

string String::_createFillContent(const string &_text, size_t _width, const char _fillCharacter)
{
  size_t fillSize = _text.size() > _width ? 0 : _width - _text.size();
  string fillContent{};

  if (fillSize > 0)
  {
    fillContent = String::_buildCharacterChain(fillSize, _fillCharacter);
  }

  return fillContent;
}
