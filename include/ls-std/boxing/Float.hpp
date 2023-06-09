/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_FLOAT_HPP
#define LS_STD_FLOAT_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL Float : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      Float();
      explicit Float(float _value);
      ~Float() noexcept override;

      // assignment operators

      ls::std::boxing::Float &operator=(float _value);

      // arithmetic operators

      float operator-() const;
      float operator+(const ls::std::boxing::Float &_float) const;
      float operator+(float _value) const;
      float operator*(const ls::std::boxing::Float &_float) const;
      float operator*(float _value) const;
      float operator-(const ls::std::boxing::Float &_float) const;
      float operator-(float _value) const;
      float operator/(const ls::std::boxing::Float &_float) const;
      float operator/(float _value) const;

      // compound operators

      ls::std::boxing::Float &operator+=(const ls::std::boxing::Float &_float);
      ls::std::boxing::Float &operator+=(float _value);
      ls::std::boxing::Float &operator-=(const ls::std::boxing::Float &_float);
      ls::std::boxing::Float &operator-=(float _value);
      ls::std::boxing::Float &operator*=(const ls::std::boxing::Float &_float);
      ls::std::boxing::Float &operator*=(float _value);
      ls::std::boxing::Float &operator/=(const ls::std::boxing::Float &_float);
      ls::std::boxing::Float &operator/=(float _value);

      // comparison operators

      bool operator==(const ls::std::boxing::Float &_float) const;
      bool operator==(float _value) const;
      bool operator!=(const ls::std::boxing::Float &_float) const;
      bool operator!=(float _value) const;
      bool operator>(const ls::std::boxing::Float &_float) const;
      bool operator>(float _value) const;
      bool operator>=(const ls::std::boxing::Float &_float) const;
      bool operator>=(float _value) const;
      bool operator<(const ls::std::boxing::Float &_float) const;
      bool operator<(float _value) const;
      bool operator<=(const ls::std::boxing::Float &_float) const;
      bool operator<=(float _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      void parse(::std::string _parseText) override;
      [[nodiscard]] ::std::string toString() override;

      // additional functionality

      [[nodiscard]] float getEpsilon() const;
      [[nodiscard]] float getValue() const;
      void setEpsilon(float _epsilon);

    private:

      float epsilon{};
      float value{};

      void _assignEpsilon(float _epsilon);
  };
}

#endif
