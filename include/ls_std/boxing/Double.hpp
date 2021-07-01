/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2021-07-01
 *
 * */

#ifndef LS_STD_DOUBLE_HPP
#define LS_STD_DOUBLE_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "IBoxing.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/io/IStorable.hpp>

namespace ls_std
{
  class Double : public ls_std::Class, public ls_std::IBoxing, public ls_std::ISerializable, public ls_std::IStorable
  {
    public:

      Double();
      explicit Double(double _value);
      ~Double() override = default;

      // conversion operator

      operator double() const; // do not make explicit!

      // assignment operators

      ls_std::Double &operator=(double _value);

      // arithmetic operators

      double operator-() const;
      double operator+(const ls_std::Double &_double) const;
      double operator+(double _value) const;
      double operator*(const ls_std::Double &_double) const;
      double operator*(double _value) const;
      double operator-(const ls_std::Double &_double) const;
      double operator-(double _value) const;
      double operator/(const ls_std::Double &_double) const;
      double operator/(double _value) const;

      // compound operators

      ls_std::Double &operator+=(const ls_std::Double &_double);
      ls_std::Double &operator+=(double _value);
      ls_std::Double &operator-=(const ls_std::Double &_double);
      ls_std::Double &operator-=(double _value);
      ls_std::Double &operator*=(const ls_std::Double &_double);
      ls_std::Double &operator*=(double _value);
      ls_std::Double &operator/=(const ls_std::Double &_double);
      ls_std::Double &operator/=(double _value);

      // comparison operators

      bool operator==(const ls_std::Double &_double) const;
      bool operator==(double _value) const;
      bool operator!=(const ls_std::Double &_double) const;
      bool operator!=(double _value) const;
      bool operator>(const ls_std::Double &_double) const;
      bool operator>(double _value) const;
      bool operator>=(const ls_std::Double &_double) const;
      bool operator>=(double _value) const;
      bool operator<(const ls_std::Double &_double) const;
      bool operator<(double _value) const;
      bool operator<=(const ls_std::Double &_double) const;
      bool operator<=(double _value) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      ls_std::byte_field load() override;
      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      void save(const ls_std::byte_field &_data) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field &_data) override;

      // additional functionality

      double getEpsilon();
      double getValue();
      void setEpsilon(double _epsilon);
      void setSerializable(const std::shared_ptr<ls_std::ISerializable>& _serializable);
      void setStorable(const std::shared_ptr<ls_std::IStorable>& _storable);

    private:

      double epsilon{};
      std::shared_ptr<ls_std::ISerializable> serializable{};
      std::shared_ptr<ls_std::IStorable> storable{};
      double value{};

      void _assignEpsilon(double _epsilon);
      void _assignSerializable(const std::shared_ptr<ls_std::ISerializable>& _serializable);
      void _assignStorable(const std::shared_ptr<ls_std::IStorable>& _storable);
  };
}

#endif
