/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>
#include <regex>
#include <string>

using ls::std::core::Class;
using ls::std::io::SectionPairIdentifierValidator;
using ls::std::io::SectionPairRowValidator;
using ls::std::io::SectionPairSectionValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairSectionValidator::SectionPairSectionValidator(string _section) : Class("SectionPairSectionValidator"), section(::move(_section))
{}

SectionPairSectionValidator::~SectionPairSectionValidator() noexcept = default;

string SectionPairSectionValidator::getValidationRegex()
{
  return SectionPairSectionValidator::_getValidationRegex();
}

bool SectionPairSectionValidator::isValid()
{
  string validationRegex = SectionPairSectionValidator::_getValidationRegex();
  static regex sectionRegex = regex{"^" + validationRegex};

  return regex_match(this->section, sectionRegex);
}

string SectionPairSectionValidator::_getValidationRegex()
{
  string newLine = R"(((\n)|(\r\n)))";
  string identifier = SectionPairIdentifierValidator::getValidationRegex();
  string sectionHeader = newLine + R"(\[{1}()" + identifier + R"()\]{1}()" + newLine + R"({2}))";
  string row = SectionPairRowValidator::getValidationRegex();
  string atLeastOneRow = R"((()" + row + R"(){1}))";
  string optionalRows = R"((()" + row + R"()*))";

  return sectionHeader + atLeastOneRow + optionalRows;
}
