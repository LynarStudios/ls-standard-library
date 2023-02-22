/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-13
*
* */

#include "MathOddValidator.hpp"

test::core::MathOddValidator::MathOddValidator() = default;

test::core::MathOddValidator::~MathOddValidator() = default;

bool test::core::MathOddValidator::isEven() const
{
  return !this->isOddNumber;
}

bool test::core::MathOddValidator::isOdd() const
{
  return this->isOddNumber;
}

void test::core::MathOddValidator::validate(int _number)
{
  this->isOddNumber = _number % 2 != 0;
}
