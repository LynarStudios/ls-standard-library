/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_DOUBLE_HPP
#define LS_STD_DOUBLE_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL Double : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      Double();
      explicit Double(double _value);
      ~Double() override;

      // assignment operators

      ls::std::boxing::Double &operator=(double _value);

      // arithmetic operators

      double operator-() const;
      double operator+(const ls::std::boxing::Double &_double) const;
      double operator+(double _value) const;
      double operator*(const ls::std::boxing::Double &_double) const;
      double operator*(double _value) const;
      double operator-(const ls::std::boxing::Double &_double) const;
      double operator-(double _value) const;
      double operator/(const ls::std::boxing::Double &_double) const;
      double operator/(double _value) const;

      // compound operators

      ls::std::boxing::Double &operator+=(const ls::std::boxing::Double &_double);
      ls::std::boxing::Double &operator+=(double _value);
      ls::std::boxing::Double &operator-=(const ls::std::boxing::Double &_double);
      ls::std::boxing::Double &operator-=(double _value);
      ls::std::boxing::Double &operator*=(const ls::std::boxing::Double &_double);
      ls::std::boxing::Double &operator*=(double _value);
      ls::std::boxing::Double &operator/=(const ls::std::boxing::Double &_double);
      ls::std::boxing::Double &operator/=(double _value);

      // comparison operators

      bool operator==(const ls::std::boxing::Double &_double) const;
      bool operator==(double _value) const;
      bool operator!=(const ls::std::boxing::Double &_double) const;
      bool operator!=(double _value) const;
      bool operator>(const ls::std::boxing::Double &_double) const;
      bool operator>(double _value) const;
      bool operator>=(const ls::std::boxing::Double &_double) const;
      bool operator>=(double _value) const;
      bool operator<(const ls::std::boxing::Double &_double) const;
      bool operator<(double _value) const;
      bool operator<=(const ls::std::boxing::Double &_double) const;
      bool operator<=(double _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      [[nodiscard]] ::std::string toString() override;

      // additional functionality

      [[nodiscard]] double getEpsilon() const;
      [[nodiscard]] double getValue() const;
      void setEpsilon(double _epsilon);

    private:

      double epsilon{};
      double value{};

      void _assignEpsilon(double _epsilon);
  };
}

#endif
