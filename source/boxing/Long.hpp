/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-17
 * Changed:         2020-08-27
 *
 * */

#ifndef LONG_HPP
#define LONG_HPP

#include <memory>
#include "../base/Class.hpp"
#include "IBoxing.hpp"
#include "../base/Types.hpp"
#include "../serialization/ISerializable.hpp"

namespace ls_std {
  class Long : public Class, public IBoxing, public ISerializable {
    public:

      explicit Long(ls_std::long_type _value);
      Long();
      ~Long() = default;

      // conversion operator

      operator ls_std::long_type() const;

      // assignment operators

      Long& operator=(ls_std::long_type _value);

      // arithmetic operators

      ls_std::long_type operator-() const;
      ls_std::long_type operator+(const Long& _long) const;
      ls_std::long_type operator+(ls_std::long_type _value) const;
      ls_std::long_type operator*(const Long& _long) const;
      ls_std::long_type operator*(ls_std::long_type _value) const;
      ls_std::long_type operator-(const Long& _long) const;
      ls_std::long_type operator-(ls_std::long_type _value) const;
      ls_std::long_type operator/(const Long& _long) const;
      ls_std::long_type operator/(ls_std::long_type _value) const;
      ls_std::long_type operator%(const Long& _long) const;
      ls_std::long_type operator%(ls_std::long_type _value) const;

      // compound operators

      Long& operator+=(const Long& _long);
      Long& operator+=(ls_std::long_type _value);
      Long& operator-=(const Long& _long);
      Long& operator-=(ls_std::long_type _value);
      Long& operator*=(const Long& _long);
      Long& operator*=(ls_std::long_type _value);
      Long& operator/=(const Long& _long);
      Long& operator/=(ls_std::long_type _value);

      // comparison operators

      bool operator==(const Long& _long) const;
      bool operator==(ls_std::long_type _value) const;
      bool operator!=(const Long& _long) const;
      bool operator!=(ls_std::long_type _value) const;
      bool operator>(const Long& _long) const;
      bool operator>(ls_std::long_type _value) const;
      bool operator>=(const Long& _long) const;
      bool operator>=(ls_std::long_type _value) const;
      bool operator<(const Long& _long) const;
      bool operator<(ls_std::long_type _value) const;
      bool operator<=(const Long& _long) const;
      bool operator<=(ls_std::long_type _value) const;

      // logical operators

      friend bool operator!(const Long& _long) {
        return !_long.value;
      }

      bool operator&&(const Long& _long) const;
      bool operator&&(ls_std::long_type _value) const;
      bool operator&&(bool _expression) const;
      bool operator||(const Long& _long) const;
      bool operator||(ls_std::long_type _value) const;
      bool operator||(bool _expression) const;

      // increment / decrement operator

      void operator++();
      void operator--();

      // implementation

      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      ls_std::long_type getValue() const;
      void setSerializable(std::shared_ptr<ISerializable> _serializable);

    private:

      std::shared_ptr<ISerializable> serializable {};
      ls_std::long_type value {};
  };
}

#endif
