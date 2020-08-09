/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-08-09
 *
 * */

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "../base/Class.hpp"
#include "IBoxing.hpp"

namespace ls_std {
  class Integer : public Class, IBoxing {
    public:

      explicit Integer(int _value);
      Integer();
      ~Integer() = default;

      // conversion operator

      operator int() const;

      // assignment operators

      Integer& operator=(int _value);

      // arithmetic operators

      int operator-() const;
      int operator+(const Integer& _integer) const;
      int operator+(int _value) const;
      int operator*(const Integer& _integer) const;
      int operator*(int _value) const;
      int operator-(const Integer& _integer) const;
      int operator-(int _value) const;
      int operator/(const Integer& _integer) const;
      int operator/(int _value) const;
      int operator%(const Integer& _integer) const;
      int operator%(int _value) const;

      // compound operators

      Integer& operator+=(const Integer& _integer);
      Integer& operator+=(int _value);
      Integer& operator-=(const Integer& _integer);
      Integer& operator-=(int _value);
      Integer& operator*=(const Integer& _integer);
      Integer& operator*=(int _value);
      Integer& operator/=(const Integer& _integer);
      Integer& operator/=(int _value);

      // comparison operators

      bool operator==(const Integer& _integer) const;
      bool operator==(int _value) const;
      bool operator!=(const Integer& _integer) const;
      bool operator!=(int _value) const;
      bool operator>(const Integer& _integer) const;
      bool operator>(int _value) const;
      bool operator>=(const Integer& _integer) const;
      bool operator>=(int _value) const;
      bool operator<(const Integer& _integer) const;
      bool operator<(int _value) const;
      bool operator<=(const Integer& _integer) const;
      bool operator<=(int _value) const;

      // stream operators

      friend std::ostream& operator<<(std::ostream& outputStream, const Integer& _integer) {
        outputStream << _integer.value;
        return outputStream;
      }

      friend std::istream& operator>>(std::istream& inputStream, Integer& _integer) {
        inputStream >> _integer.value;
        return inputStream;
      }

      // logical operators

      friend bool operator!(const Integer& _integer) {
        return !_integer.value;
      }

      bool operator&&(const Integer& _integer) const;
      bool operator&&(int _value) const;
      bool operator&&(bool expression) const;
      bool operator||(const Integer& _integer) const;
      bool operator||(int _value) const;
      bool operator||(bool expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(std::string parseText) override;
      std::string toString() override;

    private:

      int value {};
  };
}

#endif
