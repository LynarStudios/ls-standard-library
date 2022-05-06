/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2022-05-06
 *
 * */

#ifndef LS_STD_INTEGER_HPP
#define LS_STD_INTEGER_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "IBoxing.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/io/IStorable.hpp>

namespace ls
{
  class Integer : public ls::Class, public ls::std::boxing::IBoxing
  {
    public:

      explicit Integer(int _value);
      Integer();
      ~Integer() override = default;

      // conversion operator

      operator int() const;

      // assignment operators

      ls::Integer &operator=(int _value);

      // arithmetic operators

      int operator-() const;
      int operator+(const ls::Integer &_integer) const;
      int operator+(int _value) const;
      int operator*(const ls::Integer &_integer) const;
      int operator*(int _value) const;
      int operator-(const ls::Integer &_integer) const;
      int operator-(int _value) const;
      int operator/(const ls::Integer &_integer) const;
      int operator/(int _value) const;
      int operator%(const ls::Integer &_integer) const;
      int operator%(int _value) const;

      // compound operators

      ls::Integer &operator+=(const ls::Integer &_integer);
      ls::Integer &operator+=(int _value);
      ls::Integer &operator-=(const ls::Integer &_integer);
      ls::Integer &operator-=(int _value);
      ls::Integer &operator*=(const ls::Integer &_integer);
      ls::Integer &operator*=(int _value);
      ls::Integer &operator/=(const ls::Integer &_integer);
      ls::Integer &operator/=(int _value);

      // comparison operators

      bool operator==(const ls::Integer &_integer) const;
      bool operator==(int _value) const;
      bool operator!=(const ls::Integer &_integer) const;
      bool operator!=(int _value) const;
      bool operator>(const ls::Integer &_integer) const;
      bool operator>(int _value) const;
      bool operator>=(const ls::Integer &_integer) const;
      bool operator>=(int _value) const;
      bool operator<(const ls::Integer &_integer) const;
      bool operator<(int _value) const;
      bool operator<=(const ls::Integer &_integer) const;
      bool operator<=(int _value) const;

      // logical operators

      friend bool operator!(const ls::Integer &_integer)
      {
        return !_integer.value;
      }

      bool operator&&(const ls::Integer &_integer) const;
      bool operator&&(int _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const ls::Integer &_integer) const;
      bool operator||(int _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      ::std::string toString() override;

      // additional functionality

      int getValue() const;

    private:

      int value{};
  };
}

#endif
