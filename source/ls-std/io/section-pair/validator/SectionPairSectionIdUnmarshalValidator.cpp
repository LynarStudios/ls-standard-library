/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-15
*
* */

#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/validator/SectionPairIdentifierValidator.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionIdUnmarshalValidator.hpp>

ls::std::io::SectionPairSectionIdUnmarshalValidator::SectionPairSectionIdUnmarshalValidator(ls::std::core::type::byte_field _data) : ls::std::core::Class("SectionPairSectionIdUnmarshalValidator"), data(::std::move(_data))
{}

ls::std::io::SectionPairSectionIdUnmarshalValidator::~SectionPairSectionIdUnmarshalValidator() = default;

bool ls::std::io::SectionPairSectionIdUnmarshalValidator::isValid()
{
  ::std::string newLine = ls::std::io::NewLine::get();
  bool isValidSectionId = this->data.rfind(newLine, 0) == 0;
  isValidSectionId = isValidSectionId && this->data.rfind(newLine) == (this->data.size() - newLine.size());

  if (isValidSectionId)
  {
    isValidSectionId = ls::std::io::SectionPairSectionIdUnmarshalValidator::_isValidSection(ls::std::io::SectionPairSectionIdUnmarshalValidator::_trimStartAndEnd(this->data, newLine, newLine));
  }

  return isValidSectionId;
}

bool ls::std::io::SectionPairSectionIdUnmarshalValidator::_isValidSection(const ls::std::core::type::byte_field &_bracketsNotation)
{
  bool isValidBracketsNotation = _bracketsNotation.rfind('[', 0) == 0;
  isValidBracketsNotation = isValidBracketsNotation && _bracketsNotation.rfind(']') == (_bracketsNotation.size() - 1);

  if (isValidBracketsNotation)
  {
    ls::std::core::type::byte_field identifier = ls::std::io::SectionPairSectionIdUnmarshalValidator::_trimStartAndEnd(_bracketsNotation, "[", "]");
    isValidBracketsNotation = ls::std::io::SectionPairIdentifierValidator{identifier}.isValid();
  }

  return isValidBracketsNotation;
}

ls::std::core::type::byte_field ls::std::io::SectionPairSectionIdUnmarshalValidator::_trimStartAndEnd(const ls::std::core::type::byte_field &_trimmedWord, const ls::std::core::type::byte_field &_beginningTrimWord, const ls::std::core::type::byte_field &_endingTrimWord)
{
  ls::std::core::type::byte_field trimmedWord = _trimmedWord.substr(_beginningTrimWord.size());
  trimmedWord.erase(trimmedWord.end() - (uint32_t) _endingTrimWord.size(), trimmedWord.end());

  return trimmedWord;
}
