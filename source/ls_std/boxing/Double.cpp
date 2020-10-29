/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-10-29
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

ls_std::byte_field ls_std::Double::load() {
  ls_std::byte_field data {};

  if(this->storable != nullptr && this->serializable != nullptr) {
    data = this->storable->load();
    this->serializable->unmarshal(data);
  }

  return data;
}

ls_std::byte_field ls_std::Double::marshal() {
  ls_std::byte_field data {};

  if(this->serializable != nullptr) {
    data = this->serializable->marshal();
  }

  return data;
}

void ls_std::Double::parse(std::string _parseText) {
  this->value = std::stod(_parseText);
}

void ls_std::Double::save(const ls_std::byte_field &_data) {
  if(this->serializable != nullptr) {
    if(_data.empty()) {
      this->storable->save(this->serializable->marshal());
    } else {
      this->storable->save(_data);
    }
  }
}

std::string ls_std::Double::toString() {
  return std::to_string(this->value);
}

void ls_std::Double::unmarshal(const ls_std::byte_field &_data) {
  if(this->serializable != nullptr) {
    this->serializable->unmarshal(_data);
  }
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

void ls_std::Double::setSerializable(std::shared_ptr<ISerializable> _serializable) {
  this->serializable = std::move(_serializable);
}

void ls_std::Double::setStorable(std::shared_ptr<IStorable> _storable) {
  this->storable = std::move(_storable);
}
