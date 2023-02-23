/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::SectionPairIdentifierValidator;
using ls::std::io::SectionPairRowSingleValueValidator;
using ls::std::io::SectionPairValueValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairRowSingleValueValidator::SectionPairRowSingleValueValidator(string _singleValueRow) : Class("SectionPairRowSingleValueValidator"), singleValueRow(::move(_singleValueRow))
{}

SectionPairRowSingleValueValidator::~SectionPairRowSingleValueValidator() noexcept = default;

string SectionPairRowSingleValueValidator::getValidationRegex()
{
  return SectionPairRowSingleValueValidator::_getValidationRegex();
}

bool SectionPairRowSingleValueValidator::isValid()
{
  string validationRegex = SectionPairRowSingleValueValidator::_getValidationRegex();
  static regex singleValueRowRegex = regex{"^" + validationRegex};

  return regex_match(this->singleValueRow, singleValueRowRegex);
}

string SectionPairRowSingleValueValidator::_getValidationRegex()
{
  string identifierRegex = SectionPairIdentifierValidator::getValidationRegex();
  string valueRegex = SectionPairValueValidator::getValidationRegex();

  return R"(()" + identifierRegex + R"()={1}()" + valueRegex + R"(){1}($|\n{1}|\r{1}\n{1}))";
}
