/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairDocumentValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>
#include <regex>

using ls::std::core::Class;
using ls::std::io::SectionPairDocumentValidator;
using ls::std::io::SectionPairSectionValidator;
using std::move;
using std::regex;
using std::regex_match;
using std::string;

SectionPairDocumentValidator::SectionPairDocumentValidator(string _document) : Class("SectionPairDocumentValidator"), document(::move(_document))
{}

SectionPairDocumentValidator::~SectionPairDocumentValidator() noexcept = default;

bool SectionPairDocumentValidator::isValid()
{
  string validationRegex = SectionPairDocumentValidator::_getValidationRegex();
  static regex documentRegex = regex{"^" + validationRegex + "$"};

  return regex_match(this->document, documentRegex);
}

string SectionPairDocumentValidator::_getValidationRegex()
{
  string newLine = R"(((\n)|(\r\n)))";
  string documentHeader = R"((# {1}(section\-pair document))" + newLine + R"())";
  string section = SectionPairSectionValidator::getValidationRegex();
  string atLeastOneSection = R"(()" + section + R"())";
  string optionalSections = R"(()" + section + R"()*)";

  return documentHeader + atLeastOneSection + optionalSections;
}
