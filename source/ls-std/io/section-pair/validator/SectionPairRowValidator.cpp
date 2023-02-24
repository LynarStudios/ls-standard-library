/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::SectionPairRowListValueValidator;
using ls::std::io::SectionPairRowValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairRowValidator::SectionPairRowValidator(string _row) : Class("SectionPairRowValidator"), row(::move(_row))
{}

SectionPairRowValidator::~SectionPairRowValidator() noexcept = default;

string SectionPairRowValidator::getValidationRegex()
{
  return SectionPairRowValidator::_getValidationRegex();
}

bool SectionPairRowValidator::isValid()
{
  string validationRegex = SectionPairRowValidator::_getValidationRegex();
  static regex sectionPairRowRegex = regex{R"(^()" + validationRegex + R"())"};

  return regex_match(this->row, sectionPairRowRegex);
}

string SectionPairRowValidator::_getValidationRegex()
{
  string listValueRowRegex = SectionPairRowListValueValidator::getValidationRegex();
  string singleValueRowRegex = SectionPairRowSingleValueValidator::getValidationRegex();

  return R"(()" + singleValueRowRegex + R"()|()" + listValueRowRegex + R"())";
}
