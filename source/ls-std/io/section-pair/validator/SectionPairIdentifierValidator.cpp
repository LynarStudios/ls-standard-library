/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::section_pair_identifier;
using ls::std::io::SectionPairIdentifierValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairIdentifierValidator::SectionPairIdentifierValidator(section_pair_identifier _identifier) : Class("SectionPairIdentifierValidator"), identifier(::move(_identifier))
{}

SectionPairIdentifierValidator::~SectionPairIdentifierValidator() noexcept = default;

string SectionPairIdentifierValidator::getValidationRegex()
{
  return SectionPairIdentifierValidator::_getValidationRegex();
}

bool SectionPairIdentifierValidator::isValid()
{
  static regex identifierRegex("^" + SectionPairIdentifierValidator::_getValidationRegex());
  return regex_match(this->identifier, identifierRegex);
}

string SectionPairIdentifierValidator::_getValidationRegex()
{
  return R"([a-z]([a-z0-9-]){1,31})";
}
