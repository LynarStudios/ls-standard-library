/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-23
*
* */

#include <ls-std/io/section-pair/validator/SectionPairFileExtensionValidator.hpp>

using ls::std::core::Class;
using ls::std::io::SectionPairFileExtensionValidator;
using std::move;
using std::string;

SectionPairFileExtensionValidator::SectionPairFileExtensionValidator(string _fileName) : Class("SectionPairFileExtensionValidator"), fileName(::move(_fileName))
{}

SectionPairFileExtensionValidator::~SectionPairFileExtensionValidator() noexcept = default;

bool SectionPairFileExtensionValidator::isValid()
{
  string textFileExtension = ".txt";
  string sectionPairFileExtension = ".sp";
  bool endsWithTextFileExtension = this->fileName.rfind(textFileExtension) == (this->fileName.size() - textFileExtension.size());
  bool endsWithSectionPairFileExtension = this->fileName.rfind(sectionPairFileExtension) == (this->fileName.size() - sectionPairFileExtension.size());

  return endsWithTextFileExtension || endsWithSectionPairFileExtension;
}
