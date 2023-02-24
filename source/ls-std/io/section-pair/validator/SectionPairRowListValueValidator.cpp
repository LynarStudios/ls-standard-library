/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairValueValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::SectionPairIdentifierValidator;
using ls::std::io::SectionPairRowListValueValidator;
using ls::std::io::SectionPairValueValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairRowListValueValidator::SectionPairRowListValueValidator(string _listValueRow) : Class("SectionPairRowListValueValidator"), listValueRow(::move(_listValueRow))
{}

SectionPairRowListValueValidator::~SectionPairRowListValueValidator() noexcept = default;

string SectionPairRowListValueValidator::getValidationRegex()
{
  return SectionPairRowListValueValidator::_getValidationRegex();
}

bool SectionPairRowListValueValidator::isValid()
{
  string validationRegex = SectionPairRowListValueValidator::_getValidationRegex();
  static regex listValueRowRegex = regex{"^" + validationRegex};

  return regex_match(this->listValueRow, listValueRowRegex);
}

string SectionPairRowListValueValidator::_getValidationRegex()
{
  string identifierRegex = SectionPairIdentifierValidator::getValidationRegex();
  string valueRegex = SectionPairValueValidator::getValidationRegex();
  string lineBreak = R"(((\n{1})|(\r{1}\n{1})))";
  string firstLine = R"(((()" + identifierRegex + R"():{1}))" + lineBreak + R"())";

  return R"((()" + firstLine + R"(( {2})" + valueRegex + R"()" + lineBreak + R"()){1}(( {2})" + valueRegex + R"()" + lineBreak + R"()*)))";
}
