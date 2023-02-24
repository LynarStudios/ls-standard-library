/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairSectionArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairSection.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairSection.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::section_pair_row_list_element;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairSection;
using ls::std::io::SectionPairSectionArgumentEvaluator;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;

SerializableSectionPairSection::SerializableSectionPairSection(const SerializableSectionPairParameter &_parameter) : Class("SerializableSectionPairSection")
{
  string message = this->getClassName() + ": model reference is null!";
  NullPointerArgumentEvaluator(_parameter.getValue(), message).evaluate();
  this->parameter = _parameter;
}

SerializableSectionPairSection::~SerializableSectionPairSection() noexcept = default;

shared_ptr<Class> SerializableSectionPairSection::getValue()
{
  return this->parameter.getValue();
}

byte_field SerializableSectionPairSection::marshal()
{
  byte_field serializedSection{};

  serializedSection += this->_marshalSectionId();
  serializedSection += this->_marshalRows();

  return serializedSection;
}

void SerializableSectionPairSection::unmarshal(const byte_field &_data)
{
  SectionPairSectionArgumentEvaluator{_data}.evaluate();
  size_t sectionHeaderSize = this->_unmarshalSectionHeader(_data);
  this->_unmarshalRows(_data.substr(sectionHeaderSize));
}

byte_field SerializableSectionPairSection::_collectSectionRow(const byte_field &_currentRows, SectionPairRowEnumType &_type)
{
  string row{};
  string newLine = this->parameter.getNewLine();
  string firstRow = _currentRows.substr(0, _currentRows.find(newLine) + newLine.size());

  if (SerializableSectionPairSection::_isSingleValueRow(firstRow))
  {
    row = SerializableSectionPairSection::_collectSectionSingleValueRow(firstRow, _type);
  }

  if (SerializableSectionPairSection::_isListValueRow(firstRow))
  {
    row = this->_collectSectionListValueRow(_currentRows, _type);
  }

  return row;
}

byte_field SerializableSectionPairSection::_collectSectionListValueRow(const byte_field &_currentRows, SectionPairRowEnumType &_type)
{
  byte_field currentRows = _currentRows;
  byte_field currentRow{}, row{};
  string newLine = this->parameter.getNewLine();
  _type = SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE;
  size_t iterations{};
  bool isStillListRow{};

  do
  {
    if (currentRows.empty() && iterations > 1)
    {
      break;
    }

    ++iterations;
    currentRow = currentRows.substr(0, currentRows.find(newLine) + newLine.size());
    currentRows = currentRows.substr(currentRow.size());
    isStillListRow = !SerializableSectionPairSection::_isStartingValueRow(currentRow) || iterations == 1;

    if (isStillListRow)
    {
      row += currentRow;
    }
  } while (isStillListRow);

  return row;
}

byte_field SerializableSectionPairSection::_collectSectionSingleValueRow(const byte_field &_firstRow, SectionPairRowEnumType &_type)
{
  _type = SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE;
  return _firstRow;
}

size_t SerializableSectionPairSection::_getNthSubStringPosition(const byte_field &_text, const byte_field &_subText)
{
  size_t position = -1;
  size_t amount{};

  for (int index = 0; index < (_text.size() - _subText.size()); index++)
  {
    if (_text.substr(index, _subText.size()) == _subText)
    {
      ++amount;
    }

    if (amount == 2)
    {
      position = index;
      break;
    }
  }

  return position;
}

byte_field SerializableSectionPairSection::_getSectionHeader(const byte_field &_data)
{
  byte_field sectionHeader{};
  string newLine = this->parameter.getNewLine();
  size_t position = SerializableSectionPairSection::_getNthSubStringPosition(_data, newLine);

  if (position != -1)
  {
    sectionHeader = _data.substr(0, position + 2 * newLine.size());
  }

  return sectionHeader;
}

byte_field SerializableSectionPairSection::_getSectionId(const byte_field &_sectionHeader)
{
  byte_field sectionId = _sectionHeader.substr(_sectionHeader.find('[') + 1);
  return sectionId.substr(0, sectionId.find(']'));
}

bool SerializableSectionPairSection::_isListValueRow(const string &_currentRow)
{
  return _currentRow.find(':') != string::npos;
}

bool SerializableSectionPairSection::_isStartingValueRow(const string &_currentRow)
{
  bool isSingleValue = SerializableSectionPairSection::_isSingleValueRow(_currentRow);
  bool isListValue = SerializableSectionPairSection::_isListValueRow(_currentRow);

  return isSingleValue || isListValue;
}

bool SerializableSectionPairSection::_isSingleValueRow(const string &_currentRow)
{
  return _currentRow.find('=') != string::npos;
}

byte_field SerializableSectionPairSection::_marshalRows()
{
  byte_field serializedSectionRows{};

  for (const auto &_row : dynamic_pointer_cast<SectionPairSection>(this->parameter.getValue())->getList())
  {
    _row->reserveNewLine(this->parameter.getNewLine());
    serializedSectionRows += _row->marshal();
  }

  return serializedSectionRows;
}

byte_field SerializableSectionPairSection::_marshalSectionId()
{
  string newLine = this->parameter.getNewLine();
  return newLine + "[" + dynamic_pointer_cast<SectionPairSection>(this->parameter.getValue())->getSectionId() + "]" + newLine + newLine;
}

void SerializableSectionPairSection::_unmarshalRow(const string &_sectionRow, SectionPairRowEnumType _type)
{
  section_pair_row_list_element row = make_shared<SectionPairRow>("tmp-dir", _type);
  row->reserveNewLine(this->parameter.getNewLine());
  row->unmarshal(_sectionRow);
  dynamic_pointer_cast<SectionPairSection>(this->parameter.getValue())->add(row);
}

void SerializableSectionPairSection::_unmarshalRows(const byte_field &_serializedRows)
{
  string currentRows = _serializedRows;
  SectionPairRowEnumType type{};

  while (!currentRows.empty())
  {
    string sectionRow = this->_collectSectionRow(currentRows, type);
    this->_unmarshalRow(sectionRow, type);
    currentRows = currentRows.substr(sectionRow.size());
  }
}

size_t SerializableSectionPairSection::_unmarshalSectionHeader(const byte_field &_data)
{
  byte_field sectionHeader = this->_getSectionHeader(_data);
  dynamic_pointer_cast<SectionPairSection>(this->parameter.getValue())->setSectionId(SerializableSectionPairSection::_getSectionId(sectionHeader));

  return sectionHeader.size();
}
