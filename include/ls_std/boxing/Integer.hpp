/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-11-26
 *
 * */

#ifndef LS_STD_INTEGER_HPP
#define LS_STD_INTEGER_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "IBoxing.hpp"
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/io/IStorable.hpp>

namespace ls_std {
  class Integer : public Class, public IBoxing, public ISerializable, public IStorable {
    public:

      explicit Integer(int _value);
      Integer();
      ~Integer() override = default;

      // conversion operator

      operator int() const;

      // assignment operators

      Integer& operator=(int _value);

      // arithmetic operators

      int operator-() const;
      int operator+(const Integer& _integer) const;
      int operator+(int _value) const;
      int operator*(const Integer& _integer) const;
      int operator*(int _value) const;
      int operator-(const Integer& _integer) const;
      int operator-(int _value) const;
      int operator/(const Integer& _integer) const;
      int operator/(int _value) const;
      int operator%(const Integer& _integer) const;
      int operator%(int _value) const;

      // compound operators

      Integer& operator+=(const Integer& _integer);
      Integer& operator+=(int _value);
      Integer& operator-=(const Integer& _integer);
      Integer& operator-=(int _value);
      Integer& operator*=(const Integer& _integer);
      Integer& operator*=(int _value);
      Integer& operator/=(const Integer& _integer);
      Integer& operator/=(int _value);

      // comparison operators

      bool operator==(const Integer& _integer) const;
      bool operator==(int _value) const;
      bool operator!=(const Integer& _integer) const;
      bool operator!=(int _value) const;
      bool operator>(const Integer& _integer) const;
      bool operator>(int _value) const;
      bool operator>=(const Integer& _integer) const;
      bool operator>=(int _value) const;
      bool operator<(const Integer& _integer) const;
      bool operator<(int _value) const;
      bool operator<=(const Integer& _integer) const;
      bool operator<=(int _value) const;

      // logical operators

      friend bool operator!(const Integer& _integer) {
        return !_integer.value;
      }

      bool operator&&(const Integer& _integer) const;
      bool operator&&(int _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const Integer& _integer) const;
      bool operator||(int _value) const;
      bool operator||(bool _expression) const;

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

      int getValue() const;
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);

    private:

      std::shared_ptr<ISerializable> serializable {};
      std::shared_ptr<IStorable> storable {};
      int value {};
  };
}

#endif
