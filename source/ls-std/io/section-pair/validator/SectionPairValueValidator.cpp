/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-20
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

ls::std::io::SectionPairValueValidator::SectionPairValueValidator(ls::std::io::section_pair_row_value _value) : ls::std::core::Class("SectionPairValueValidator"), value(::std::move(_value))
{}

ls::std::io::SectionPairValueValidator::~SectionPairValueValidator() = default;

::std::string ls::std::io::SectionPairValueValidator::getValidationRegex()
{
  return ls::std::io::SectionPairValueValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairValueValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairValueValidator::_getValidationRegex();
  ::std::string concatenation = "(^" + validationRegex + ")|(^" + validationRegex + R"(\n{1})|(^)" + validationRegex + R"(\r{1}\n{1}))";
  static ::std::regex valueRegex{concatenation};

  return ::std::regex_match(this->value, valueRegex);
}

::std::string ls::std::io::SectionPairValueValidator::_getValidationRegex()
{
  ::std::string value = R"([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32})";
  return value;
}
