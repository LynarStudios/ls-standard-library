/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-04-13
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairValueValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairValueValidator::SectionPairValueValidator(section_pair_row_value _value) : Class("SectionPairValueValidator"), value(::move(_value))
{}

SectionPairValueValidator::~SectionPairValueValidator() noexcept = default;

string SectionPairValueValidator::getValidationRegex()
{
  return SectionPairValueValidator::_getValidationRegex();
}

bool SectionPairValueValidator::isValid()
{
  string validationRegex = SectionPairValueValidator::_getValidationRegex();
  string concatenation = "(^" + validationRegex + ")|(^" + validationRegex + R"(\n{1})|(^)" + validationRegex + R"(\r{1}\n{1}))";
  static regex valueRegex{concatenation};

  return regex_match(this->value, valueRegex);
}

string SectionPairValueValidator::_getValidationRegex()
{
  string value = R"([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,512})";
  return value;
}
