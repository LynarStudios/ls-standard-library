/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-20
*
* */

#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>
#include <regex>
#include <string>

ls::std::io::SectionPairSectionValidator::SectionPairSectionValidator(::std::string _section) : ls::std::core::Class("SectionPairSectionValidator"), section(::std::move(_section))
{}

ls::std::io::SectionPairSectionValidator::~SectionPairSectionValidator() = default;

::std::string ls::std::io::SectionPairSectionValidator::getValidationRegex()
{
  return ls::std::io::SectionPairSectionValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairSectionValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairSectionValidator::_getValidationRegex();
  static ::std::regex sectionRegex = ::std::regex{"^" + validationRegex};

  return ::std::regex_match(this->section, sectionRegex);
}

::std::string ls::std::io::SectionPairSectionValidator::_getValidationRegex()
{
  ::std::string newLine = R"(((\n)|(\r\n)))";
  ::std::string sectionHeader = newLine + R"(\[{1}([a-z]([a-z0-9-]){1,15})\]{1}()" + newLine + R"({2}))";
  ::std::string row = ls::std::io::SectionPairRowValidator::getValidationRegex();
  ::std::string atLeastOneRow = R"((()" + row + R"(){1}))";
  ::std::string optionalRows = R"((()" + row + R"()*))";

  return sectionHeader + atLeastOneRow + optionalRows;
}
