/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-16
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairDocument.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairDocument.hpp>
#include <string>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::SectionPairDocument;
using ls::std::io::SectionPairSection;
using ls::std::io::SerializableSectionPairDocument;
using ls::std::io::SerializableSectionPairParameter;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;

SerializableSectionPairDocument::SerializableSectionPairDocument(const SerializableSectionPairParameter &_parameter) : Class("SerializableSectionPairDocument")
{
  string message = this->getClassName() + ": model reference is null!";
  NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

SerializableSectionPairDocument::~SerializableSectionPairDocument() noexcept = default;

shared_ptr<Class> SerializableSectionPairDocument::getValue()
{
  return this->parameter.getValue();
}

byte_field SerializableSectionPairDocument::marshal()
{
  shared_ptr<SectionPairDocument> document = dynamic_pointer_cast<SectionPairDocument>(this->parameter.getValue());
  string newLine = this->parameter.getNewLine();
  byte_field serializedDocument = document->getHeader() + newLine;

  for (const auto &_section : document->getSectionList())
  {
    _section->reserveNewLine(this->parameter.getNewLine());
    serializedDocument += _section->marshal();
  }

  return serializedDocument;
}

void SerializableSectionPairDocument::unmarshal(const byte_field &_data)
{
  byte_field serializedDocument = _data;
  size_t headerSize = dynamic_pointer_cast<SectionPairDocument>(this->parameter.getValue())->getHeader().size() + this->parameter.getNewLine().size();
  serializedDocument = serializedDocument.substr(headerSize);
  byte_field serializedSection{};

  do
  {
    serializedSection = this->_getNextSerializedSection(serializedDocument);
    this->_addSection(serializedSection);
    serializedDocument = serializedDocument.substr(serializedSection.size());
  } while (!serializedDocument.empty());
}

void SerializableSectionPairDocument::_addSection(const byte_field &_serializedSection)
{
  shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
  section->reserveNewLine(this->parameter.getNewLine());
  section->unmarshal(_serializedSection);
  dynamic_pointer_cast<SectionPairDocument>(this->parameter.getValue())->add(section);
}

byte_field SerializableSectionPairDocument::_getCurrentRow(size_t _iterations, const byte_field &_serializedDocument)
{
  string newLine = this->parameter.getNewLine();
  string currentRow{};

  if (_iterations == 1 || _serializedDocument.find('[') != string::npos)
  {
    currentRow = _serializedDocument.substr(0, _serializedDocument.find(newLine + newLine) + 2 * newLine.size());
  }
  else
  {
    currentRow = _serializedDocument.substr(0, _serializedDocument.find(newLine) + newLine.size());
  }

  return currentRow;
}

byte_field SerializableSectionPairDocument::_getNextSerializedSection(const byte_field &_serializedDocument)
{
  byte_field serializedSection{}, currentRow{};
  size_t iterations{};
  byte_field serializedDocument = _serializedDocument;
  bool isNotNewSection{};
  string newLine = this->parameter.getNewLine();

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

bool SerializableSectionPairDocument::_isNotNewSection(const byte_field &_currentRow)
{
  string newLine = this->parameter.getNewLine();
  return _currentRow.find(newLine + newLine) == string::npos;
}
