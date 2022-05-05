/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2022-05-05
 *
 * */

#ifndef LS_STD_FLOAT_HPP
#define LS_STD_FLOAT_HPP

#include <memory>
#include <ls_std/core/Class.hpp>
#include "IBoxing.hpp"

namespace ls
{
  class Float : public ls::Class, public ls::IBoxing
  {
    public:

      Float();
      explicit Float(float _value);
      ~Float() override = default;

      // conversion operator

      operator float() const; // do not make explicit!

      // assignment operators

      ls::Float &operator=(float _value);

      // arithmetic operators

      float operator-() const;
      float operator+(const ls::Float &_float) const;
      float operator+(float _value) const;
      float operator*(const ls::Float &_float) const;
      float operator*(float _value) const;
      float operator-(const ls::Float &_float) const;
      float operator-(float _value) const;
      float operator/(const ls::Float &_float) const;
      float operator/(float _value) const;

      // compound operators

      ls::Float &operator+=(const ls::Float &_float);
      ls::Float &operator+=(float _value);
      ls::Float &operator-=(const ls::Float &_float);
      ls::Float &operator-=(float _value);
      ls::Float &operator*=(const ls::Float &_float);
      ls::Float &operator*=(float _value);
      ls::Float &operator/=(const ls::Float &_float);
      ls::Float &operator/=(float _value);

      // comparison operators

      bool operator==(const ls::Float &_float) const;
      bool operator==(float _value) const;
      bool operator!=(const ls::Float &_float) const;
      bool operator!=(float _value) const;
      bool operator>(const ls::Float &_float) const;
      bool operator>(float _value) const;
      bool operator>=(const ls::Float &_float) const;
      bool operator>=(float _value) const;
      bool operator<(const ls::Float &_float) const;
      bool operator<(float _value) const;
      bool operator<=(const ls::Float &_float) const;
      bool operator<=(float _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(std::string _parseText) override;
      std::string toString() override;

      // additional functionality

      float getEpsilon();
      float getValue();
      void setEpsilon(float _epsilon);

    private:

      float epsilon{};
      float value{};

      void _assignEpsilon(float _epsilon);
  };
}

#endif
