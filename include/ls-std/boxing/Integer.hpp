/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_INTEGER_HPP
#define LS_STD_INTEGER_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL Integer : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      explicit Integer(int _value);
      Integer();
      ~Integer() noexcept override;

      // assignment operators

      ls::std::boxing::Integer &operator=(int _value);

      // arithmetic operators

      int operator-() const;
      int operator+(const ls::std::boxing::Integer &_integer) const;
      int operator+(int _value) const;
      int operator*(const ls::std::boxing::Integer &_integer) const;
      int operator*(int _value) const;
      int operator-(const ls::std::boxing::Integer &_integer) const;
      int operator-(int _value) const;
      int operator/(const ls::std::boxing::Integer &_integer) const;
      int operator/(int _value) const;
      int operator%(const ls::std::boxing::Integer &_integer) const;
      int operator%(int _value) const;

      // compound operators

      ls::std::boxing::Integer &operator+=(const ls::std::boxing::Integer &_integer);
      ls::std::boxing::Integer &operator+=(int _value);
      ls::std::boxing::Integer &operator-=(const ls::std::boxing::Integer &_integer);
      ls::std::boxing::Integer &operator-=(int _value);
      ls::std::boxing::Integer &operator*=(const ls::std::boxing::Integer &_integer);
      ls::std::boxing::Integer &operator*=(int _value);
      ls::std::boxing::Integer &operator/=(const ls::std::boxing::Integer &_integer);
      ls::std::boxing::Integer &operator/=(int _value);

      // comparison operators

      bool operator==(const ls::std::boxing::Integer &_integer) const;
      bool operator==(int _value) const;
      bool operator!=(const ls::std::boxing::Integer &_integer) const;
      bool operator!=(int _value) const;
      bool operator>(const ls::std::boxing::Integer &_integer) const;
      bool operator>(int _value) const;
      bool operator>=(const ls::std::boxing::Integer &_integer) const;
      bool operator>=(int _value) const;
      bool operator<(const ls::std::boxing::Integer &_integer) const;
      bool operator<(int _value) const;
      bool operator<=(const ls::std::boxing::Integer &_integer) const;
      bool operator<=(int _value) const;

      // logical operators

      friend bool operator!(const ls::std::boxing::Integer &_integer)
      {
        return !_integer.value;
      }

      bool operator&&(const ls::std::boxing::Integer &_integer) const;
      bool operator&&(int _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const ls::std::boxing::Integer &_integer) const;
      bool operator||(int _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      [[nodiscard]] ::std::string toString() override;

      // additional functionality

      [[nodiscard]] int getValue() const;

    private:

      int value{};
  };
}

#endif
