/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-23
*
* */

#include "MathOddValidator.hpp"

using test::core::MathOddValidator;

MathOddValidator::MathOddValidator() = default;

MathOddValidator::~MathOddValidator() = default;

bool MathOddValidator::isOdd() const
{
  return this->isOddNumber;
}

void MathOddValidator::validate(int _number)
{
  this->isOddNumber = _number % 2 != 0;
}
