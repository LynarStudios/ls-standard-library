/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-09-04
 *
 * */

#ifndef LS_STD_BOOLEAN_HPP
#define LS_STD_BOOLEAN_HPP

#include <memory>
#include "../base/Class.hpp"
#include "IBoxing.hpp"
#include "../serialization/ISerializable.hpp"

namespace ls_std {
  class Boolean : public Class, public IBoxing, public ISerializable {
    public:

      explicit Boolean(bool _value);
      Boolean();
      ~Boolean() = default;

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

      ls_std::byte_field marshal() override;
      void parse(std::string _parseText) override;
      std::string toString() override;
      void unmarshal(const ls_std::byte_field& _data) override;

      // additional functionality

      bool getValue();
      void setSerializable(std::shared_ptr<ISerializable> _serializable);
      static bool XOR(const Boolean& _leftExpression, const Boolean& _rightExpression);
      static bool XOR(const Boolean& _leftExpression, bool _rightExpression);
      static bool XOR(bool _leftExpression, const Boolean& _rightExpression);
      static bool XOR(bool _leftExpression, bool _rightExpression);

    private:

      std::shared_ptr<ISerializable> serializable {};
      bool value {};
      const std::string TRUE_STRING = "true";
      const std::string FALSE_STRING = "false";

      std::string _toString() const;
  };
}

#endif
