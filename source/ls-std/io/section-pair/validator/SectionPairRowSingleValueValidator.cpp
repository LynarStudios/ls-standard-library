/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-22
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

ls::std::io::SectionPairRowSingleValueValidator::SectionPairRowSingleValueValidator(::std::string _singleValueRow) : ls::std::core::Class("SectionPairRowSingleValueValidator"), singleValueRow(::std::move(_singleValueRow))
{}

ls::std::io::SectionPairRowSingleValueValidator::~SectionPairRowSingleValueValidator() noexcept = default;

::std::string ls::std::io::SectionPairRowSingleValueValidator::getValidationRegex()
{
  return ls::std::io::SectionPairRowSingleValueValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairRowSingleValueValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairRowSingleValueValidator::_getValidationRegex();
  static ::std::regex singleValueRowRegex = ::std::regex{"^" + validationRegex};

  return ::std::regex_match(this->singleValueRow, singleValueRowRegex);
}

::std::string ls::std::io::SectionPairRowSingleValueValidator::_getValidationRegex()
{
  ::std::string identifierRegex = ls::std::io::SectionPairIdentifierValidator::getValidationRegex();
  ::std::string valueRegex = ls::std::io::SectionPairValueValidator::getValidationRegex();

  return R"(()" + identifierRegex + R"()={1}()" + valueRegex + R"(){1}($|\n{1}|\r{1}\n{1}))";
}
