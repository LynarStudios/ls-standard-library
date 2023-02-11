/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-11
*
* */

#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>

ls::std::io::SectionPairIdentifierValidator::SectionPairIdentifierValidator(ls::std::io::section_pair_identifier _identifier) : ls::std::core::Class("SectionPairIdentifierValidator"), identifier(::std::move(_identifier))
{}

ls::std::io::SectionPairIdentifierValidator::~SectionPairIdentifierValidator() = default;

bool ls::std::io::SectionPairIdentifierValidator::isValid()
{
  bool startsWithValidCharacter{}, containsValidCharacters{}, doesNotExceedMaxSize{};

  if (!this->identifier.empty())
  {
    size_t foundPosition = this->identifier.find_first_not_of("abcdefghijklmnopqrstuvwxyz-0123456789");
    startsWithValidCharacter = ls::std::io::section_pair_identifier{this->identifier[0]}.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == ::std::string::npos;
    containsValidCharacters = foundPosition == ls::std::io::section_pair_identifier::npos;
    doesNotExceedMaxSize = this->identifier.size() <= 16;
  }

  return startsWithValidCharacter && containsValidCharacters && doesNotExceedMaxSize;
}
