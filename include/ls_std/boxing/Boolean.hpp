/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-11-14
 *
 * */

#ifndef LS_STD_BOOLEAN_HPP
#define LS_STD_BOOLEAN_HPP

#include <memory>
#include "../base/Class.hpp"
#include "IBoxing.hpp"
#include "../serialization/ISerializable.hpp"
#include "../io/IStorable.hpp"

namespace ls_std {
  class Boolean : public Class, public IBoxing, public ISerializable, public IStorable {
    public:

      explicit Boolean(bool _value);
      Boolean();
      ~Boolean() override = default;

      // conversion operator

      operator bool() const;

      // assignment operators

      Boolean& operator=(int _value);
      Boolean& operator=(bool _value);

      // stream operators

      friend std::ostream& operator<<(std::ostream& _outputStream, const Boolean& _boolean) {
        _outputStream << _boolean._toString();
        return _outputStream;
      }

      // logical operators

      friend bool operator!(const Boolean& _boolean) {
        return !_boolean.value;
      }

      bool operator&&(const Boolean& _boolean) const;
      bool operator&&(bool _value) const;
      bool operator&&(int _value) const;
      bool operator||(const Boolean& _boolean) const;
      bool operator||(bool _value) const;
      bool operator||(int _value) const;
      // INFO: operator ^ can not be taken for XOR, since it's not possible to implement it respecting commutative law

      // implementation

      ls_std::byte_field load() override;
      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      void save(const ls_std::byte_field& _data) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      bool getValue() const;
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      void setStorable(std::shared_ptr<IStorable> _storable);
      static bool XOR(const Boolean& _leftExpression, const Boolean& _rightExpression);
      static bool XOR(const Boolean& _leftExpression, bool _rightExpression);
      static bool XOR(bool _leftExpression, const Boolean& _rightExpression);
      static bool XOR(bool _leftExpression, bool _rightExpression);

    private:

      std::shared_ptr<ISerializable> serializable {};
      std::shared_ptr<IStorable> storable {};
      bool value {};

      const std::string FALSE_STRING = "false";
      const std::string TRUE_STRING = "true";

      std::string _toString() const;
  };
}

#endif
