/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
* Changed:         2023-02-22
*
* */

#include <ls-std/io/section-pair/validator/SectionPairFileExtensionValidator.hpp>

ls::std::io::SectionPairFileExtensionValidator::SectionPairFileExtensionValidator(::std::string _fileName) : ls::std::core::Class("SectionPairFileExtensionValidator"), fileName(::std::move(_fileName))
{}

ls::std::io::SectionPairFileExtensionValidator::~SectionPairFileExtensionValidator() = default;

bool ls::std::io::SectionPairFileExtensionValidator::isValid()
{
  ::std::string textFileExtension = ".txt";
  ::std::string sectionPairFileExtension = ".sp";
  bool endsWithTextFileExtension = this->fileName.rfind(textFileExtension) == (this->fileName.size() - textFileExtension.size());
  bool endsWithSectionPairFileExtension = this->fileName.rfind(sectionPairFileExtension) == (this->fileName.size() - sectionPairFileExtension.size());

  return endsWithTextFileExtension || endsWithSectionPairFileExtension;
}
