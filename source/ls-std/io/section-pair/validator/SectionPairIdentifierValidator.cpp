/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-18
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <regex>

ls::std::io::SectionPairIdentifierValidator::SectionPairIdentifierValidator(ls::std::io::section_pair_identifier _identifier) : ls::std::core::Class("SectionPairIdentifierValidator"), identifier(::std::move(_identifier))
{}

ls::std::io::SectionPairIdentifierValidator::~SectionPairIdentifierValidator() = default;

::std::string ls::std::io::SectionPairIdentifierValidator::getValidationRegex()
{
  return ls::std::io::SectionPairIdentifierValidator::_getValidationRegex();
}

bool ls::std::io::SectionPairIdentifierValidator::isValid()
{
  static ::std::regex identifierRegex("^" + ls::std::io::SectionPairIdentifierValidator::_getValidationRegex());
  return ::std::regex_match(this->identifier, identifierRegex);
}

::std::string ls::std::io::SectionPairIdentifierValidator::_getValidationRegex()
{
  return R"([a-z]([a-z0-9-]){1,15})";
}
