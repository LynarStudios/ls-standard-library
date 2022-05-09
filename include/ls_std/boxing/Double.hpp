/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-09
 *
 * */

#ifndef LS_STD_DOUBLE_HPP
#define LS_STD_DOUBLE_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "IBoxing.hpp"

namespace ls
{
  namespace std
  {
    namespace boxing
    {
      class Double : public ls::std::core::Class, public ls::std::boxing::IBoxing
      {
        public:

          Double();
          explicit Double(double _value);
          ~Double() override = default;

          // conversion operator

          operator double() const; // do not make explicit!

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
          ::std::string toString() override;

          // additional functionality

          double getEpsilon();
          double getValue();
          void setEpsilon(double _epsilon);

        private:

          double epsilon{};
          double value{};

          void _assignEpsilon(double _epsilon);
      };
    }
  }
}

#endif
