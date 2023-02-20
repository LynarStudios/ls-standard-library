/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-20
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

ls::std::io::SectionPairRowListValueValidator::SectionPairRowListValueValidator(::std::string _listValueRow) : ls::std::core::Class("SectionPairRowListValueValidator"), listValueRow(::std::move(_listValueRow))
{}

ls::std::io::SectionPairRowListValueValidator::~SectionPairRowListValueValidator() = default;

::std::string ls::std::io::SectionPairRowListValueValidator::getValidationRegex()
{
  return ls::std::io::SectionPairRowListValueValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairRowListValueValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairRowListValueValidator::_getValidationRegex();
  static ::std::regex listValueRowRegex = ::std::regex{"^" + validationRegex};

  return ::std::regex_match(this->listValueRow, listValueRowRegex);
}

::std::string ls::std::io::SectionPairRowListValueValidator::_getValidationRegex()
{
  ::std::string identifierRegex = ls::std::io::SectionPairIdentifierValidator::getValidationRegex();
  ::std::string valueRegex = ls::std::io::SectionPairValueValidator::getValidationRegex();
  ::std::string windowsFirstLine = R"(((()" + identifierRegex + R"():{1})\r{1}\n{1}))";
  ::std::string unixFirstLine = R"(((()" + identifierRegex + R"():{1})\n{1}))";
  ::std::string windowsValidationRegex = R"((()" + windowsFirstLine + R"(( {2})" + valueRegex + R"(\r{1}\n{1})){1}(( {2})" + valueRegex + R"(\r{1}\n{1})*)))";
  ::std::string unixValidationRegex = R"(|(()" + unixFirstLine + R"(( {2})" + valueRegex + R"(\n{1})){1}(( {2})" + valueRegex + R"(\n{1})*)))";

  return windowsValidationRegex + unixValidationRegex;
}
