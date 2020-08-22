/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-07
 * Changed:         2020-08-22
 *
 * */

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <memory>
#include "../base/Class.hpp"
#include "IBoxing.hpp"
#include "../serialization/ISerializable.hpp"
#include "../io/IStorable.hpp"

namespace ls_std {
  class Integer : public Class, public IBoxing, public ISerializable, public IStorable {
    public:

      explicit Integer(int _value);
      Integer();
      ~Integer() = default;

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

      // stream operators

      // TODO: not compilable
//      friend std::ostream& operator<<(std::ostream& outputStream, const Integer& _integer) {
//        outputStream << _integer.value;
//        return outputStream;
//      }
//
//      friend std::istream& operator>>(std::istream& inputStream, Integer& _integer) {
//        inputStream >> _integer.value;
//        return inputStream;
//      }

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

      ls_std::byte* load() override;
      const ls_std::byte* marshal() override;
      void parse(std::string _parseText) override;
      void save(ls_std::byte* _data) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte* _data) override;

      // additional functionality

      int getValue() const;
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);

    private:

      int value {};
      std::shared_ptr<ISerializable> serializable {};
      std::shared_ptr<IStorable> storable {};
  };
}

#endif
