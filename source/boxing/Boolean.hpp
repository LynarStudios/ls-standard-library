/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2020-08-13
 *
 * */

#ifndef BOOLEAN_HPP
#define BOOLEAN_HPP

#include "../base/Class.hpp"
#include "IBoxing.hpp"

namespace ls_std {
  class Boolean : public Class, IBoxing {
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

      friend std::ostream& operator<<(std::ostream& outputStream, const Boolean& _boolean) {
        outputStream << _boolean._toString();
        return outputStream;
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

      void parse(std::string parseText) override;
      std::string toString() override;

      // additional functionality

      static bool XOR(const Boolean& _leftExpression, const Boolean& _rightExpression);
      static bool XOR(const Boolean& _leftExpression, bool _rightExpression);
      static bool XOR(bool _leftExpression, const Boolean& _rightExpression);
      static bool XOR(bool _leftExpression, bool _rightExpression);

    private:

      bool value {};
      const std::string TRUE_STRING = "true";
      const std::string FALSE_STRING = "false";

      std::string _toString() const;
  };
}

#endif
