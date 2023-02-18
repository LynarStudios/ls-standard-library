/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-18
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValueValidator.hpp>
#include <regex>

ls::std::io::SectionPairRowValueValidator::SectionPairRowValueValidator(ls::std::io::section_pair_row_value _value) : ls::std::core::Class("SectionPairRowValueValidator"), value(::std::move(_value))
{}

ls::std::io::SectionPairRowValueValidator::~SectionPairRowValueValidator() = default;

::std::string ls::std::io::SectionPairRowValueValidator::getValidationRegex()
{
  ::std::string validationRegex = ls::std::io::SectionPairRowValueValidator::_getValidationRegex();
  return "(" + validationRegex + ")|(" + validationRegex + "\\n{1})|(" + validationRegex + "\\r{1}\\n{1})";
}

bool ls::std::io::SectionPairRowValueValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairRowValueValidator::_getValidationRegex();
  ::std::string concatenation = "(^" + validationRegex + ")|(^" + validationRegex + R"(\n{1})|(^)" + validationRegex + R"(\r{1}\n{1}))";
  static ::std::regex valueRegex{concatenation};

  return ::std::regex_match(this->value, valueRegex);
}

::std::string ls::std::io::SectionPairRowValueValidator::_getValidationRegex()
{
  ::std::string value = R"([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32})";
  return value;
}
