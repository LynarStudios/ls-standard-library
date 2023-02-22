/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_LONG_HPP
#define LS_STD_LONG_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/core/type/Types.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL Long : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      explicit Long(ls::std::core::type::long_type _value);
      Long();
      ~Long() noexcept override;

      // assignment operators

      ls::std::boxing::Long &operator=(ls::std::core::type::long_type _value);

      // arithmetic operators

      ls::std::core::type::long_type operator-() const;
      ls::std::core::type::long_type operator+(const ls::std::boxing::Long &_long) const;
      ls::std::core::type::long_type operator+(ls::std::core::type::long_type _value) const;
      ls::std::core::type::long_type operator*(const ls::std::boxing::Long &_long) const;
      ls::std::core::type::long_type operator*(ls::std::core::type::long_type _value) const;
      ls::std::core::type::long_type operator-(const ls::std::boxing::Long &_long) const;
      ls::std::core::type::long_type operator-(ls::std::core::type::long_type _value) const;
      ls::std::core::type::long_type operator/(const ls::std::boxing::Long &_long) const;
      ls::std::core::type::long_type operator/(ls::std::core::type::long_type _value) const;
      ls::std::core::type::long_type operator%(const ls::std::boxing::Long &_long) const;
      ls::std::core::type::long_type operator%(ls::std::core::type::long_type _value) const;

      // compound operators

      ls::std::boxing::Long &operator+=(const ls::std::boxing::Long &_long);
      ls::std::boxing::Long &operator+=(ls::std::core::type::long_type _value);
      ls::std::boxing::Long &operator-=(const ls::std::boxing::Long &_long);
      ls::std::boxing::Long &operator-=(ls::std::core::type::long_type _value);
      ls::std::boxing::Long &operator*=(const ls::std::boxing::Long &_long);
      ls::std::boxing::Long &operator*=(ls::std::core::type::long_type _value);
      ls::std::boxing::Long &operator/=(const ls::std::boxing::Long &_long);
      ls::std::boxing::Long &operator/=(ls::std::core::type::long_type _value);

      // comparison operators

      bool operator==(const ls::std::boxing::Long &_long) const;
      bool operator==(ls::std::core::type::long_type _value) const;
      bool operator!=(const ls::std::boxing::Long &_long) const;
      bool operator!=(ls::std::core::type::long_type _value) const;
      bool operator>(const ls::std::boxing::Long &_long) const;
      bool operator>(ls::std::core::type::long_type _value) const;
      bool operator>=(const ls::std::boxing::Long &_long) const;
      bool operator>=(ls::std::core::type::long_type _value) const;
      bool operator<(const ls::std::boxing::Long &_long) const;
      bool operator<(ls::std::core::type::long_type _value) const;
      bool operator<=(const ls::std::boxing::Long &_long) const;
      bool operator<=(ls::std::core::type::long_type _value) const;

      // logical operators

      friend bool operator!(const ls::std::boxing::Long &_long)
      {
        return !_long.value;
      }

      bool operator&&(const ls::std::boxing::Long &_long) const;
      bool operator&&(ls::std::core::type::long_type _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const ls::std::boxing::Long &_long) const;
      bool operator||(ls::std::core::type::long_type _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      [[nodiscard]] ::std::string toString() override;

      // additional functionality

      [[nodiscard]] ls::std::core::type::long_type getValue() const;

    private:

      ls::std::core::type::long_type value{};
  };
}

#endif
