/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-20
*
* */

#include <ls-std/io/section-pair/validator/SectionPairRowListValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowSingleValueValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairRowValidator.hpp>
#include <regex>

ls::std::io::SectionPairRowValidator::SectionPairRowValidator(::std::string _row) : ls::std::core::Class("SectionPairRowValidator"), row(::std::move(_row))
{}

ls::std::io::SectionPairRowValidator::~SectionPairRowValidator() = default;

::std::string ls::std::io::SectionPairRowValidator::getValidationRegex()
{
  return ls::std::io::SectionPairRowValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairRowValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairRowValidator::_getValidationRegex();
  static ::std::regex sectionPairRowRegex = ::std::regex{R"(^()" + validationRegex + R"())"};

  return ::std::regex_match(this->row, sectionPairRowRegex);
}

::std::string ls::std::io::SectionPairRowValidator::_getValidationRegex()
{
  ::std::string listValueRowRegex = ls::std::io::SectionPairRowListValueValidator::getValidationRegex();
  ::std::string singleValueRowRegex = ls::std::io::SectionPairRowSingleValueValidator::getValidationRegex();

  return R"(()" + singleValueRowRegex + R"()|()" + listValueRowRegex + R"())";
}
