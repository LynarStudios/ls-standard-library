/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2021-07-08
 *
 * */

#ifndef LS_STD_BOOLEAN_HPP
#define LS_STD_BOOLEAN_HPP

#include <memory>
#include <ls_std/base/Class.hpp>
#include "IBoxing.hpp"

namespace ls_std
{
  class Boolean : public ls_std::Class, public ls_std::IBoxing
  {
    public:

      explicit Boolean(bool _value);
      Boolean();
      ~Boolean() override = default;

      // conversion operator

      operator bool() const;

      // assignment operators

      ls_std::Boolean &operator=(int _value);
      ls_std::Boolean &operator=(bool _value);

      // stream operators

      friend std::ostream &operator<<(std::ostream &_outputStream, const ls_std::Boolean &_boolean)
      {
        _outputStream << _boolean._toString();
        return _outputStream;
      }

      // logical operators

      friend bool operator!(const ls_std::Boolean &_boolean)
      {
        return !_boolean.value;
      }

      bool operator&&(const ls_std::Boolean &_boolean) const;
      bool operator&&(bool _value) const;
      bool operator&&(int _value) const;
      bool operator||(const ls_std::Boolean &_boolean) const;
      bool operator||(bool _value) const;
      bool operator||(int _value) const;
      // INFO: operator ^ can not be taken for XOR, since it's not possible to implement it respecting commutative law

      // implementation

      void parse(std::string _parseText) override;
      std::string toString() override;

      // additional functionality

      bool getValue() const;
      static bool XOR(const ls_std::Boolean &_leftExpression, const ls_std::Boolean &_rightExpression);
      static bool XOR(const ls_std::Boolean &_leftExpression, bool _rightExpression);
      static bool XOR(bool _leftExpression, const ls_std::Boolean &_rightExpression);
      static bool XOR(bool _leftExpression, bool _rightExpression);

    private:

      bool value{};

      const std::string FALSE_STRING = "false";
      const std::string TRUE_STRING = "true";

      std::string _toString() const;
  };
}

#endif
