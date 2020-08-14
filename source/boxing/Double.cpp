/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-14
 *
 * */

#include <cmath>
#include "Double.hpp"

ls_std::Double::Double() : Class("Double"),
epsilon(0.00000001)
{}

ls_std::Double::Double(double _value) : Class("Double"),
epsilon(0.00000001),
value(_value)
{}

ls_std::Double::operator double() const {
  return this->value;
}

ls_std::Double & ls_std::Double::operator=(double _value) {
  this->value = _value;
  return *this;
}

double ls_std::Double::operator-() const {
  return -this->value;
}

double ls_std::Double::operator+(const Double &_double) const {
  return this->value + _double;
}

double ls_std::Double::operator+(double _value) const {
  return this->value + _value;
}

double ls_std::Double::operator*(const Double &_double) const {
  return this->value * _double;
}

double ls_std::Double::operator*(double _value) const {
  return this->value * _value;
}

double ls_std::Double::operator-(const Double &_double) const {
  return this->value - _double;
}

double ls_std::Double::operator-(double _value) const {
  return this->value - _value;
}

double ls_std::Double::operator/(const Double &_double) const {
  return this->value / _double;
}

double ls_std::Double::operator/(double _value) const {
  return this->value / _value;
}

ls_std::Double & ls_std::Double::operator+=(const Double &_double) {
  this->value += _double;
  return *this;
}

ls_std::Double & ls_std::Double::operator+=(double _value) {
  this->value += _value;
  return *this;
}

ls_std::Double & ls_std::Double::operator-=(const Double &_double) {
  this->value -= _double;
  return *this;
}

ls_std::Double & ls_std::Double::operator-=(double _value) {
  this->value -= _value;
  return *this;
}

ls_std::Double & ls_std::Double::operator*=(const Double &_double) {
  this->value *= _double;
  return *this;
}

ls_std::Double & ls_std::Double::operator*=(double _value) {
  this->value *= _value;
  return *this;
}

ls_std::Double & ls_std::Double::operator/=(const Double &_double) {
  this->value /= _double;
  return *this;
}

ls_std::Double & ls_std::Double::operator/=(double _value) {
  this->value /= _value;
  return *this;
}

bool ls_std::Double::operator==(const Double &_double) const {
  return std::fabs(this->value - _double) < this->epsilon;
}

bool ls_std::Double::operator==(double _value) const {
  return std::fabs(this->value - _value) < this->epsilon;
}

bool ls_std::Double::operator!=(const Double &_double) const {
  return std::fabs(this->value - _double) >= this->epsilon;
}

bool ls_std::Double::operator!=(double _value) const {
  return std::fabs(this->value - _value) >= this->epsilon;
}

bool ls_std::Double::operator>(const Double &_double) const {
  return this->value > _double;
}

bool ls_std::Double::operator>(double _value) const {
  return this->value > _value;
}

bool ls_std::Double::operator>=(const Double &_double) const {
  return this->value >= _double;
}

bool ls_std::Double::operator>=(double _value) const {
  return this->value >= _value;
}

bool ls_std::Double::operator<(const Double &_double) const {
  return this->value < _double;
}

bool ls_std::Double::operator<(double _value) const {
  return this->value < _value;
}

bool ls_std::Double::operator<=(const Double &_double) const {
  return this->value <= _double;
}

bool ls_std::Double::operator<=(double _value) const {
  return this->value <= _value;
}

void ls_std::Double::operator++() {
  this->value += 1.0f;
}

void ls_std::Double::operator--() {
  this->value -= 1.0f;
}

void ls_std::Double::parse(std::string parseText) {
  this->value = std::stod(parseText);
}

std::string ls_std::Double::toString() {
  return std::to_string(this->value);
}

double ls_std::Double::getEpsilon() {
  return this->epsilon;
}

double ls_std::Double::getValue() {
  return this->value;
}

void ls_std::Double::setEpsilon(double _epsilon) {
  this->epsilon = _epsilon;
}
