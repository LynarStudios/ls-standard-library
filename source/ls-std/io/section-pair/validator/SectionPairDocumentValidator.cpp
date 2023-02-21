/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-21
*
* */

#include <ls-std/io/section-pair/validator/SectionPairDocumentValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionValidator.hpp>
#include <regex>

ls::std::io::SectionPairDocumentValidator::SectionPairDocumentValidator(::std::string _document) : ls::std::core::Class("SectionPairDocumentValidator"), document(::std::move(_document))
{}

ls::std::io::SectionPairDocumentValidator::~SectionPairDocumentValidator() = default;

bool ls::std::io::SectionPairDocumentValidator::isValid()
{
  ::std::string validationRegex = ls::std::io::SectionPairDocumentValidator::_getValidationRegex();
  static ::std::regex documentRegex = ::std::regex{"^" + validationRegex + "$"};

  return ::std::regex_match(this->document, documentRegex);
}

::std::string ls::std::io::SectionPairDocumentValidator::_getValidationRegex()
{
  ::std::string newLine = R"(((\n)|(\r\n)))";
  ::std::string documentHeader = R"((# {1}(section\-pair document))" + newLine + R"())";
  ::std::string section = ls::std::io::SectionPairSectionValidator::getValidationRegex();
  ::std::string atLeastOneSection = R"(()" + section + R"())";
  ::std::string optionalSections = R"(()" + section + R"()*)";

  return documentHeader + atLeastOneSection + optionalSections;
}
