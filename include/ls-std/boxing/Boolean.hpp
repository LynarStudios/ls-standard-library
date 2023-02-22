/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2020-08-09
 * Changed:         2023-02-22
 *
 * */

#ifndef LS_STD_BOOLEAN_HPP
#define LS_STD_BOOLEAN_HPP

#include <ls-std/core/Class.hpp>
#include <ls-std/core/interface/IBoxing.hpp>
#include <ls-std/os/dynamic-goal.hpp>
#include <memory>
#include <sstream>

namespace ls::std::boxing
{
  class LS_STD_DYNAMIC_GOAL Boolean : public ls::std::core::Class, public ls::std::core::interface_type::IBoxing
  {
    public:

      explicit Boolean(bool _value);
      Boolean();
      ~Boolean() override;

      // assignment operators

      ls::std::boxing::Boolean &operator=(int _value);
      ls::std::boxing::Boolean &operator=(bool _value);

      // stream operators

      friend ::std::ostream &operator<<(::std::ostream &_outputStream, const ls::std::boxing::Boolean &_boolean)
      {
        _outputStream << _boolean._toString();
        return _outputStream;
      }

      // logical operators

      friend bool operator!(const ls::std::boxing::Boolean &_boolean)
      {
        return !_boolean.value;
      }

      bool operator&&(const ls::std::boxing::Boolean &_boolean) const;
      bool operator&&(bool _value) const;
      bool operator&&(int _value) const;
      bool operator||(const ls::std::boxing::Boolean &_boolean) const;
      bool operator||(bool _value) const;
      bool operator||(int _value) const;
      // INFO: operator ^ can not be taken for XOR, since it's not possible to implement it respecting commutative law

      // implementation

      void parse(::std::string _parseText) override;
      [[nodiscard]] ::std::string toString() override;

      // additional functionality

      [[nodiscard]] bool getValue() const;
      [[nodiscard]] static bool XOR(const ls::std::boxing::Boolean &_leftExpression, const ls::std::boxing::Boolean &_rightExpression);
      [[nodiscard]] static bool XOR(const ls::std::boxing::Boolean &_leftExpression, bool _rightExpression);
      [[nodiscard]] static bool XOR(bool _leftExpression, const ls::std::boxing::Boolean &_rightExpression);
      [[nodiscard]] static bool XOR(bool _leftExpression, bool _rightExpression);

    private:

      bool value{};

      const ::std::string FALSE_STRING = "false";
      const ::std::string TRUE_STRING = "true";

      [[nodiscard]] ::std::string _toString() const;
  };
}

#endif
