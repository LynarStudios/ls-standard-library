/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-17
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairDocument.hpp>

ls::std::io::SerializableSectionPairDocument::SerializableSectionPairDocument(const ::std::shared_ptr<ls::std::core::Class> &_value) : ls::std::core::Class("SerializableSectionPairDocument")
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairDocument::~SerializableSectionPairDocument() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairDocument::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairDocument::marshal()
{
  ::std::shared_ptr<ls::std::io::SectionPairDocument> document = ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->value);
  ::std::string newLine = ls::std::io::NewLine::get();
  ls::std::core::type::byte_field serializedDocument = document->getHeader() + newLine + newLine;

  for (const auto &_section : document->getSectionList())
  {
    serializedDocument += _section->marshal();
  }

  return serializedDocument;
}

void ls::std::io::SerializableSectionPairDocument::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::type::byte_field serializedDocument = _data;
  size_t headerSize = ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->value)->getHeader().size() + 2 * ls::std::io::NewLine::get().size();
  serializedDocument = serializedDocument.substr(headerSize);
  ls::std::core::type::byte_field serializedSection{};

  do
  {
    serializedSection = ls::std::io::SerializableSectionPairDocument::_getNextSerializedSection(serializedDocument);
    this->_addSection(serializedSection);
    serializedDocument = serializedDocument.substr(serializedSection.size());
  } while (!serializedDocument.empty());
}

void ls::std::io::SerializableSectionPairDocument::_addSection(const ls::std::core::type::byte_field &_serializedSection)
{
  ::std::shared_ptr<ls::std::io::SectionPairSection> section = ::std::make_shared<ls::std::io::SectionPairSection>("tmp-id");
  section->unmarshal(_serializedSection);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairDocument>(this->value)->add(section);
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairDocument::_getCurrentRow(size_t _iterations, const ls::std::core::type::byte_field &_serializedDocument)
{
  ::std::string newLine = ls::std::io::NewLine::get();
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
  ::std::string newLine = ls::std::io::NewLine::get();

  do
  {
    ++iterations;
    currentRow = ls::std::io::SerializableSectionPairDocument::_getCurrentRow(iterations, serializedDocument);
    isNotNewSection = ls::std::io::SerializableSectionPairDocument::_isNotNewSection(currentRow) && !serializedDocument.empty() || iterations == 1;
    serializedDocument = serializedDocument.substr(currentRow.size());
    serializedSection += currentRow;
  } while (isNotNewSection);

  return serializedDocument.empty() ? serializedSection : serializedSection.substr(0, serializedSection.size() - newLine.size());
}

bool ls::std::io::SerializableSectionPairDocument::_isNotNewSection(const ls::std::core::type::byte_field &_currentRow)
{
  ::std::string newLine = ls::std::io::NewLine::get();
  return _currentRow.find(newLine + newLine) == ::std::string::npos;
}

void ls::std::io::SerializableSectionPairDocument::_setValue(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value}.evaluate();
  this->value = _value;
}
