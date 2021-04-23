/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2021-04-23
 *
 * */

#ifndef LS_STD_LONG_HPP
#define LS_STD_LONG_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "IBoxing.hpp"
#include <ls_std/base/Types.hpp>
#include <ls_std/serialization/ISerializable.hpp>
#include <ls_std/io/IStorable.hpp>

namespace ls_std
{
  class Long : public Class, public IBoxing, public ISerializable, public IStorable
  {
    public:

      explicit Long(ls_std::long_type _value);
      Long();
      ~Long() override = default;

      // conversion operator

      operator ls_std::long_type() const;

      // assignment operators

      ls_std::Long &operator=(ls_std::long_type _value);

      // arithmetic operators

      ls_std::long_type operator-() const;
      ls_std::long_type operator+(const ls_std::Long &_long) const;
      ls_std::long_type operator+(ls_std::long_type _value) const;
      ls_std::long_type operator*(const ls_std::Long &_long) const;
      ls_std::long_type operator*(ls_std::long_type _value) const;
      ls_std::long_type operator-(const ls_std::Long &_long) const;
      ls_std::long_type operator-(ls_std::long_type _value) const;
      ls_std::long_type operator/(const ls_std::Long &_long) const;
      ls_std::long_type operator/(ls_std::long_type _value) const;
      ls_std::long_type operator%(const ls_std::Long &_long) const;
      ls_std::long_type operator%(ls_std::long_type _value) const;

      // compound operators

      ls_std::Long &operator+=(const ls_std::Long &_long);
      ls_std::Long &operator+=(ls_std::long_type _value);
      ls_std::Long &operator-=(const ls_std::Long &_long);
      ls_std::Long &operator-=(ls_std::long_type _value);
      ls_std::Long &operator*=(const ls_std::Long &_long);
      ls_std::Long &operator*=(ls_std::long_type _value);
      ls_std::Long &operator/=(const ls_std::Long &_long);
      ls_std::Long &operator/=(ls_std::long_type _value);

      // comparison operators

      bool operator==(const ls_std::Long &_long) const;
      bool operator==(ls_std::long_type _value) const;
      bool operator!=(const ls_std::Long &_long) const;
      bool operator!=(ls_std::long_type _value) const;
      bool operator>(const ls_std::Long &_long) const;
      bool operator>(ls_std::long_type _value) const;
      bool operator>=(const ls_std::Long &_long) const;
      bool operator>=(ls_std::long_type _value) const;
      bool operator<(const ls_std::Long &_long) const;
      bool operator<(ls_std::long_type _value) const;
      bool operator<=(const ls_std::Long &_long) const;
      bool operator<=(ls_std::long_type _value) const;

      // logical operators

      friend bool operator!(const ls_std::Long &_long)
      {
        return !_long.value;
      }

      bool operator&&(const ls_std::Long &_long) const;
      bool operator&&(ls_std::long_type _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const ls_std::Long &_long) const;
      bool operator||(ls_std::long_type _value) const;
      bool operator||(bool _expression) const;

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

      ls_std::long_type getValue() const;
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);

    private:

      std::shared_ptr<ISerializable> serializable{};
      std::shared_ptr<IStorable> storable{};
      ls_std::long_type value{};
  };
}

#endif
