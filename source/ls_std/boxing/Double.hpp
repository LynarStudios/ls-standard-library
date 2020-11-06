/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-14
 * Changed:         2020-11-06
 *
 * */

#ifndef LS_STD_DOUBLE_HPP
#define LS_STD_DOUBLE_HPP

#include <memory>
#include "../../../include/base/Class.hpp"
#include "IBoxing.hpp"
#include "../serialization/ISerializable.hpp"
#include "../io/IStorable.hpp"

namespace ls_std {
  class Double : public Class, public IBoxing, public ISerializable, public IStorable {
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

      ls_std::byte_field load() override;
      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      void save(const ls_std::byte_field& _data) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      double getEpsilon();
      double getValue();
      void setEpsilon(double _epsilon);
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);

    private:

      double epsilon {};
      std::shared_ptr<ISerializable> serializable {};
      std::shared_ptr<IStorable> storable {};
      double value {};
  };
}

#endif
