/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2022-07-03
 *
 * */

#ifndef LS_STD_LONG_HPP
#define LS_STD_LONG_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include <ls_std/core/interface/IBoxing.hpp>
#include <ls_std/core/types/Types.hpp>
#include <ls_std/os/dynamic_goal.hpp>

namespace ls
{
  namespace std
  {
    namespace boxing
    {
      class LS_STD_DYNAMIC_GOAL Long : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
      {
        public:

          explicit Long(ls::std::core::type::long_type _value);
          Long();
          ~Long() override = default;

          // conversion operator

          operator ls::std::core::type::long_type() const;

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
          ::std::string toString() override;

          // additional functionality

          ls::std::core::type::long_type getValue() const;

        private:

          ls::std::core::type::long_type value{};
      };
    }
  }
}

#endif
