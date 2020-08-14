/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-14
 *
 * */

#include <algorithm>
#include <utility>
#include "String.hpp"

ls_std::String::String() : Class("String")
{}

ls_std::String::String(std::string _value) : Class("String"),
value(std::move(_value))
{}

ls_std::String::operator const char*() const {
  return this->value.c_str();
}

ls_std::String::operator std::string() const {
  return this->value;
}

ls_std::String & ls_std::String::operator=(std::string _value) {
  this->value = std::move(_value);
  return *this;
}

std::string ls_std::String::operator+(String _string) const {
  return this->value + _string.toString();
}

std::string ls_std::String::operator+(const std::string& _string) const {
  return this->value + _string;
}

std::string ls_std::String::operator+(const char *_string) const {
  return this->value + _string;
}

std::string ls_std::String::operator-(int _number) {
  std::string copy = this->value;
  return copy.substr(0, copy.size() - _number);;
}

ls_std::String & ls_std::String::operator+=(String _string) {
  this->value = this->value + _string.toString();
  return *this;
}

ls_std::String & ls_std::String::operator+=(const std::string &_text) {
  this->value = this->value + _text;
  return *this;
}

bool ls_std::String::operator==(String _string) {
  return this->value == _string.toString();
}

bool ls_std::String::operator==(const std::string& _value) {
  return this->value == _value;
}

bool ls_std::String::operator==(const char *_value) {
  return this->value == _value;
}

bool ls_std::String::operator!=(String _string) {
  return this->value != _string.toString();
}

bool ls_std::String::operator!=(const std::string& _value) {
  return this->value != _value;
}

bool ls_std::String::operator!=(const char *_value) {
  return this->value != _value;
}

void ls_std::String::parse(std::string parseText) {
  this->value = std::move(parseText);
}

std::string ls_std::String::toString() {
  return this->value;
}

bool ls_std::String::contains(const std::string& _text) {
  return this->value.find(_text) != std::string::npos;
}

bool ls_std::String::endsWith(const std::string &_text) {
  return this->value.rfind(_text) == (this->value.size() - _text.size());
}

bool ls_std::String::equalsIgnoreCase(String _string) {
  return this->toLowerCase() == _string.toLowerCase();
}

bool ls_std::String::equalsIgnoreCase(std::string _text) {
  return this->toLowerCase() == ls_std::String{std::move(_text)}.toLowerCase();
}

std::string ls_std::String::reverse() {
  std::string copy = this->value;
  std::reverse(copy.begin(), copy.end());

  return copy;
}

bool ls_std::String::startsWith(const std::string &_text) {
  return this->value.rfind(_text, 0) == 0;
}

std::string ls_std::String::toLowerCase() {
  std::string copy = this->value;
  std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

  return copy;
}

std::string ls_std::String::toUpperCase() {
  std::string copy = this->value;
  std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);

  return copy;
}