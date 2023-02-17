/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-18
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairDocument.hpp>
#include <string>

ls::std::io::SerializableSectionPairDocument::SerializableSectionPairDocument(const ls::std::io::SerializableSectionPairParameter &_parameter) : ls::std::core::Class("SerializableSectionPairDocument")
{
  ::std::string message = this->getClassName() + ": model reference is null!";
  ls::std::core::NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

ls::std::io::SerializableSectionPairDocument::~SerializableSectionPairDocument() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairDocument::getValue()
{
  return this->parameter.getValue();
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairDocument::marshal()
{
  ::std::shared_ptr<ls::std::io::SectionPairDocument> document = ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->parameter.getValue());
  ::std::string newLine = this->parameter.getNewLine();
  ls::std::core::type::byte_field serializedDocument = document->getHeader() + newLine + newLine;

  for (const auto &_section : document->getSectionList())
  {
    _section->reserveNewLine(this->parameter.getNewLine());
    serializedDocument += _section->marshal();
  }

  return serializedDocument;
}

void ls::std::io::SerializableSectionPairDocument::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::type::byte_field serializedDocument = _data;
  size_t headerSize = ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->parameter.getValue())->getHeader().size() + 2 * this->parameter.getNewLine().size();
  serializedDocument = serializedDocument.substr(headerSize);
  ls::std::core::type::byte_field serializedSection{};

  do
  {
    serializedSection = this->_getNextSerializedSection(serializedDocument);
    this->_addSection(serializedSection);
    serializedDocument = serializedDocument.substr(serializedSection.size());
  } while (!serializedDocument.empty());
}

void ls::std::io::SerializableSectionPairDocument::_addSection(const ls::std::core::type::byte_field &_serializedSection)
{
  ::std::shared_ptr<ls::std::io::SectionPairSection> section = ::std::make_shared<ls::std::io::SectionPairSection>("tmp-id");
  section->reserveNewLine(this->parameter.getNewLine());
  section->unmarshal(_serializedSection);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->parameter.getValue())->add(section);
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairDocument::_getCurrentRow(size_t _iterations, const ls::std::core::type::byte_field &_serializedDocument)
{
  ::std::string newLine = this->parameter.getNewLine();
  ::std::string currentRow{};

  if (_iterations == 1 || _serializedDocument.find('[') != ::std::string::npos)
  {
    currentRow = _serializedDocument.substr(0, _serializedDocument.find(newLine + newLine) + 2 * newLine.size());
  }
  else
  {
    currentRow = _serializedDocument.substr(0, _serializedDocument.find(newLine) + newLine.size());
  }

  return currentRow;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairDocument::_getNextSerializedSection(const ls::std::core::type::byte_field &_serializedDocument)
{
  ls::std::core::type::byte_field serializedSection{}, currentRow{};
  size_t iterations{};
  ls::std::core::type::byte_field serializedDocument = _serializedDocument;
  bool isNotNewSection{};
  ::std::string newLine = this->parameter.getNewLine();

  do
  {
    ++iterations;
    currentRow = this->_getCurrentRow(iterations, serializedDocument);
    isNotNewSection = this->_isNotNewSection(currentRow) && !serializedDocument.empty() || iterations == 1;
    serializedDocument = serializedDocument.substr(currentRow.size());
    serializedSection += currentRow;
  } while (isNotNewSection);

  return serializedDocument.empty() ? serializedSection : serializedSection.substr(0, serializedSection.size() - newLine.size());
}

bool ls::std::io::SerializableSectionPairDocument::_isNotNewSection(const ls::std::core::type::byte_field &_currentRow)
{
  ::std::string newLine = this->parameter.getNewLine();
  return _currentRow.find(newLine + newLine) == ::std::string::npos;
}
