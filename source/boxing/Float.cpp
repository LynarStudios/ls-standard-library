/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-16
 *
 * */

#include <cmath>
#include "Float.hpp"

ls_std::Float::Float() : Class("Float"),
epsilon(0.00001f)
{}

ls_std::Float::Float(float _value) : Class("Float"),
epsilon(0.00001f),
value(_value)
{}

ls_std::Float::operator float() const {
  return this->value;
}

ls_std::Float & ls_std::Float::operator=(float _value) {
  this->value = _value;
  return *this;
}

float ls_std::Float::operator-() const {
  return -this->value;
}

float ls_std::Float::operator+(const Float &_float) const {
  return this->value + _float;
}

float ls_std::Float::operator+(float _value) const {
  return this->value + _value;
}

float ls_std::Float::operator*(const Float &_float) const {
  return this->value * _float;
}

float ls_std::Float::operator*(float _value) const {
  return this->value * _value;
}

float ls_std::Float::operator-(const Float &_float) const {
  return this->value - _float;
}

float ls_std::Float::operator-(float _value) const {
  return this->value - _value;
}

float ls_std::Float::operator/(const Float &_float) const {
  return this->value / _float;
}

float ls_std::Float::operator/(float _value) const {
  return this->value / _value;
}

ls_std::Float & ls_std::Float::operator+=(const Float &_float) {
  this->value += _float;
  return *this;
}

ls_std::Float & ls_std::Float::operator+=(float _value) {
  this->value += _value;
  return *this;
}

ls_std::Float & ls_std::Float::operator-=(const Float &_float) {
  this->value -= _float;
  return *this;
}

ls_std::Float & ls_std::Float::operator-=(float _value) {
  this->value -= _value;
  return *this;
}

ls_std::Float & ls_std::Float::operator*=(const Float &_float) {
  this->value *= _float;
  return *this;
}

ls_std::Float & ls_std::Float::operator*=(float _value) {
  this->value *= _value;
  return *this;
}

ls_std::Float & ls_std::Float::operator/=(const Float &_float) {
  this->value /= _float;
  return *this;
}

ls_std::Float & ls_std::Float::operator/=(float _value) {
  this->value /= _value;
  return *this;
}

bool ls_std::Float::operator==(const Float &_float) const {
  return std::fabs(this->value - _float) < this->epsilon;
}

bool ls_std::Float::operator==(float _value) const {
  return std::fabs(this->value - _value) < this->epsilon;
}

bool ls_std::Float::operator!=(const Float &_float) const {
  return std::fabs(this->value - _float) >= this->epsilon;
}

bool ls_std::Float::operator!=(float _value) const {
  return std::fabs(this->value - _value) >= this->epsilon;
}

bool ls_std::Float::operator>(const Float &_float) const {
  return this->value > _float;
}

bool ls_std::Float::operator>(float _value) const {
  return this->value > _value;
}

bool ls_std::Float::operator>=(const Float &_float) const {
  return this->value >= _float;
}

bool ls_std::Float::operator>=(float _value) const {
  return this->value >= _value;
}

bool ls_std::Float::operator<(const Float &_float) const {
  return this->value < _float;
}

bool ls_std::Float::operator<(float _value) const {
  return this->value < _value;
}

bool ls_std::Float::operator<=(const Float &_float) const {
  return this->value <= _float;
}

bool ls_std::Float::operator<=(float _value) const {
  return this->value <= _value;
}

void ls_std::Float::operator++() {
  this->value += 1.0f;
}

void ls_std::Float::operator--() {
  this->value -= 1.0f;
}

void ls_std::Float::parse(std::string _parseText) {
  this->value = std::stof(_parseText);
}

std::string ls_std::Float::toString() {
  return std::to_string(this->value);
}

float ls_std::Float::getEpsilon() {
  return this->epsilon;
}

float ls_std::Float::getValue() {
  return this->value;
}

void ls_std::Float::setEpsilon(float _epsilon) {
  this->epsilon = _epsilon;
}
