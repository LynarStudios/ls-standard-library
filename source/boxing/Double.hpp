/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-08-16
 *
 * */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "../base/Class.hpp"
#include "IBoxing.hpp"

namespace ls_std {
  class Double : public Class, IBoxing {
    public:

      Double();
      explicit Double(double _value);
      ~Double() = default;

      // conversion operator

      operator double() const; // do not make explicit!

      // assignment operators

      Double& operator=(double _value);

      // arithmetic operators

      double operator-() const;
      double operator+(const Double& _double) const;
      double operator+(double _value) const;
      double operator*(const Double& _double) const;
      double operator*(double _value) const;
      double operator-(const Double& _double) const;
      double operator-(double _value) const;
      double operator/(const Double& _double) const;
      double operator/(double _value) const;

      // compound operators

      Double& operator+=(const Double& _double);
      Double& operator+=(double _value);
      Double& operator-=(const Double& _double);
      Double& operator-=(double _value);
      Double& operator*=(const Double& _double);
      Double& operator*=(double _value);
      Double& operator/=(const Double& _double);
      Double& operator/=(double _value);

      // comparison operators

      bool operator==(const Double& _double) const;
      bool operator==(double _value) const;
      bool operator!=(const Double& _double) const;
      bool operator!=(double _value) const;
      bool operator>(const Double& _double) const;
      bool operator>(double _value) const;
      bool operator>=(const Double& _double) const;
      bool operator>=(double _value) const;
      bool operator<(const Double& _double) const;
      bool operator<(double _value) const;
      bool operator<=(const Double& _double) const;
      bool operator<=(double _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(std::string _parseText) override;
      std::string toString() override;

      // additional functionality

      double getEpsilon();
      double getValue();
      void setEpsilon(double _epsilon);

    private:

      double value {};
      double epsilon {};
  };
}

#endif
