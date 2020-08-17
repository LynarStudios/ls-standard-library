/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-17
 *
 * */

#ifndef LONG_HPP
#define LONG_HPP

#include "../base/Class.hpp"
#include "IBoxing.hpp"

namespace ls_std {
  class Long : public Class, IBoxing {
    public:

      explicit Long(long _value);
      Long();
      ~Long() = default;

      // conversion operator

      operator long() const;

      // assignment operators

      Long& operator=(long _value);

      // arithmetic operators

      long operator-() const;
      long operator+(const Long& _long) const;
      long operator+(long _value) const;
      long operator*(const Long& _long) const;
      long operator*(long _value) const;
      long operator-(const Long& _long) const;
      long operator-(long _value) const;
      long operator/(const Long& _long) const;
      long operator/(long _value) const;
      long operator%(const Long& _long) const;
      long operator%(long _value) const;

      // compound operators

      Long& operator+=(const Long& _long);
      Long& operator+=(long _value);
      Long& operator-=(const Long& _long);
      Long& operator-=(long _value);
      Long& operator*=(const Long& _long);
      Long& operator*=(long _value);
      Long& operator/=(const Long& _long);
      Long& operator/=(long _value);

      // comparison operators

      bool operator==(const Long& _long) const;
      bool operator==(long _value) const;
      bool operator!=(const Long& _long) const;
      bool operator!=(long _value) const;
      bool operator>(const Long& _long) const;
      bool operator>(long _value) const;
      bool operator>=(const Long& _long) const;
      bool operator>=(long _value) const;
      bool operator<(const Long& _long) const;
      bool operator<(long _value) const;
      bool operator<=(const Long& _long) const;
      bool operator<=(long _value) const;

      // stream operators

      // TODO: not compilable
//      friend std::ostream& operator<<(std::ostream& outputStream, const Long& _long) {
//        outputStream << _long.value;
//        return outputStream;
//      }
//
//      friend std::istream& operator>>(std::istream& inputStream, Long& _long) {
//        inputStream >> _long.value;
//        return inputStream;
//      }

      // logical operators

      friend bool operator!(const Long& _long) {
        return !_long.value;
      }

      bool operator&&(const Long& _long) const;
      bool operator&&(long _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const Long& _long) const;
      bool operator||(long _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(std::string _parseText) override;
      std::string toString() override;

      // additional functionality

      long getValue() const;

    private:

      long value {};
  };
}

#endif
