/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-05-06
 *
 * */

#ifndef LS_STD_LONG_HPP
#define LS_STD_LONG_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "IBoxing.hpp"
#include <ls_std/core/Types.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/io/IStorable.hpp>

namespace ls
{
  class Long : public ls::Class, public ls::std::boxing::IBoxing
  {
    public:

      explicit Long(ls::long_type _value);
      Long();
      ~Long() override = default;

      // conversion operator

      operator ls::long_type() const;

      // assignment operators

      ls::Long &operator=(ls::long_type _value);

      // arithmetic operators

      ls::long_type operator-() const;
      ls::long_type operator+(const ls::Long &_long) const;
      ls::long_type operator+(ls::long_type _value) const;
      ls::long_type operator*(const ls::Long &_long) const;
      ls::long_type operator*(ls::long_type _value) const;
      ls::long_type operator-(const ls::Long &_long) const;
      ls::long_type operator-(ls::long_type _value) const;
      ls::long_type operator/(const ls::Long &_long) const;
      ls::long_type operator/(ls::long_type _value) const;
      ls::long_type operator%(const ls::Long &_long) const;
      ls::long_type operator%(ls::long_type _value) const;

      // compound operators

      ls::Long &operator+=(const ls::Long &_long);
      ls::Long &operator+=(ls::long_type _value);
      ls::Long &operator-=(const ls::Long &_long);
      ls::Long &operator-=(ls::long_type _value);
      ls::Long &operator*=(const ls::Long &_long);
      ls::Long &operator*=(ls::long_type _value);
      ls::Long &operator/=(const ls::Long &_long);
      ls::Long &operator/=(ls::long_type _value);

      // comparison operators

      bool operator==(const ls::Long &_long) const;
      bool operator==(ls::long_type _value) const;
      bool operator!=(const ls::Long &_long) const;
      bool operator!=(ls::long_type _value) const;
      bool operator>(const ls::Long &_long) const;
      bool operator>(ls::long_type _value) const;
      bool operator>=(const ls::Long &_long) const;
      bool operator>=(ls::long_type _value) const;
      bool operator<(const ls::Long &_long) const;
      bool operator<(ls::long_type _value) const;
      bool operator<=(const ls::Long &_long) const;
      bool operator<=(ls::long_type _value) const;

      // logical operators

      friend bool operator!(const ls::Long &_long)
      {
        return !_long.value;
      }

      bool operator&&(const ls::Long &_long) const;
      bool operator&&(ls::long_type _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const ls::Long &_long) const;
      bool operator||(ls::long_type _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      ::std::string toString() override;

      // additional functionality

      ls::long_type getValue() const;

    private:

      ls::long_type value{};
  };
}

#endif
