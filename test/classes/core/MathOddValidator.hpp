/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-23
*
* */

#ifndef LS_STD_MATH_ODD_VALIDATOR_HPP
#define LS_STD_MATH_ODD_VALIDATOR_HPP

namespace test::core
{
  class MathOddValidator
  {
    public:

      MathOddValidator();
      ~MathOddValidator();

      [[nodiscard]] bool isOdd() const;
      void validate(int _number);

    private:

      bool isOddNumber{};
  };
}

#endif
