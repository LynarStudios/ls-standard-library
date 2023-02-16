/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-16
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairSection.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairSection.hpp>
#include <ls-std/io/section-pair/validator/SectionPairSectionIdUnmarshalValidator.hpp>

ls::std::io::SerializableSectionPairSection::SerializableSectionPairSection(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairSection::~SerializableSectionPairSection() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairSection::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::marshal()
{
  ls::std::core::type::byte_field serializedSection{};

  serializedSection += this->_marshalSectionId();
  serializedSection += this->_marshalRows();

  return serializedSection;
}

void ls::std::io::SerializableSectionPairSection::unmarshal(const ls::std::core::type::byte_field &_data)
{
  size_t sectionHeaderSize = this->_unmarshalSectionHeader(_data);
  this->_unmarshalRows(_data.substr(sectionHeaderSize));
}

void ls::std::io::SerializableSectionPairSection::_checkSectionHeader(const ls::std::core::type::byte_field &_sectionHeader)
{
  if (!ls::std::io::SectionPairSectionIdUnmarshalValidator{_sectionHeader}.isValid())
  {
    throw ls::std::core::IllegalArgumentException{"serialized section header is not valid!"};
  }
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_collectSectionRow(const ls::std::core::type::byte_field &_currentRows, ls::std::io::SectionPairRowEnumType &_type)
{
  ::std::string row{};
  ::std::string newLine = ls::std::io::NewLine::get();
  ::std::string firstRow = _currentRows.substr(0, _currentRows.find(newLine) + newLine.size());

  if (ls::std::io::SerializableSectionPairSection::_isSingleValueRow(firstRow))
  {
    row = ls::std::io::SerializableSectionPairSection::_collectSectionSingleValueRow(firstRow, _type);
  }

  if (ls::std::io::SerializableSectionPairSection::_isListValueRow(firstRow))
  {
    row = ls::std::io::SerializableSectionPairSection::_collectSectionListValueRow(_currentRows, _type);
  }

  return row;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_collectSectionListValueRow(const ls::std::core::type::byte_field &_currentRows, ls::std::io::SectionPairRowEnumType &_type)
{
  ls::std::core::type::byte_field currentRows = _currentRows;
  ls::std::core::type::byte_field currentRow{}, row{};
  ::std::string newLine = ls::std::io::NewLine::get();
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
    isStillListRow = !ls::std::io::SerializableSectionPairSection::_isStartingValueRow(currentRow) || iterations == 1;

    if (isStillListRow)
    {
      row += currentRow;
    }
  } while (isStillListRow);

  return row;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_collectSectionSingleValueRow(const ls::std::core::type::byte_field &_firstRow, ls::std::io::SectionPairRowEnumType &_type)
{
  _type = SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE;
  return _firstRow;
}

size_t ls::std::io::SerializableSectionPairSection::_getNthSubStringPosition(const ls::std::core::type::byte_field &_text, const ls::std::core::type::byte_field &_subText)
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

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_getSectionHeader(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::type::byte_field sectionHeader{};
  ::std::string newLine = ls::std::io::NewLine::get();
  size_t position = ls::std::io::SerializableSectionPairSection::_getNthSubStringPosition(_data, newLine);

  if (position != -1)
  {
    sectionHeader = _data.substr(0, position + 2 * newLine.size());
  }

  return sectionHeader;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_getSectionId(const ls::std::core::type::byte_field &_sectionHeader)
{
  ls::std::core::type::byte_field sectionId = _sectionHeader.substr(_sectionHeader.find('[') + 1);
  return sectionId.substr(0, sectionId.find(']'));
}

bool ls::std::io::SerializableSectionPairSection::_isListValueRow(const ::std::string &_currentRow)
{
  return _currentRow.find(':') != ::std::string::npos;
}

bool ls::std::io::SerializableSectionPairSection::_isStartingValueRow(const ::std::string &_currentRow)
{
  bool isSingleValue = ls::std::io::SerializableSectionPairSection::_isSingleValueRow(_currentRow);
  bool isListValue = ls::std::io::SerializableSectionPairSection::_isListValueRow(_currentRow);

  return isSingleValue || isListValue;
}

bool ls::std::io::SerializableSectionPairSection::_isSingleValueRow(const ::std::string &_currentRow)
{
  return _currentRow.find('=') != ::std::string::npos;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_marshalRows()
{
  ls::std::core::type::byte_field serializedSectionRows{};

  for (const auto &_row : ::std::dynamic_pointer_cast<ls::std::io::SectionPairSection>(this->value)->getList())
  {
    serializedSectionRows += _row->marshal();
  }

  return serializedSectionRows;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairSection::_marshalSectionId()
{
  return ls::std::io::NewLine::get() + "[" + ::std::dynamic_pointer_cast<ls::std::io::SectionPairSection>(this->value)->getSectionId() + "]" + ls::std::io::NewLine::get() + ls::std::io::NewLine::get();
}

void ls::std::io::SerializableSectionPairSection::_setValue(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value, "model reference for SerializableSectionPairSection is null!"}.evaluate();
  this->value = _value;
}

void ls::std::io::SerializableSectionPairSection::_unmarshalRow(const ::std::string &_sectionRow, ls::std::io::SectionPairRowEnumType _type)
{
  ls::std::io::section_pair_row_list_element row = ::std::make_shared<ls::std::io::SectionPairRow>("tmp-dir", _type);
  row->unmarshal(_sectionRow);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairSection>(this->value)->add(row);
}

void ls::std::io::SerializableSectionPairSection::_unmarshalRows(const ls::std::core::type::byte_field &_serializedRows)
{
  ::std::string newLine = ls::std::io::NewLine::get();
  ::std::string currentRows = _serializedRows;
  ls::std::io::SectionPairRowEnumType type{};

  while (!currentRows.empty())
  {
    ::std::string sectionRow = ls::std::io::SerializableSectionPairSection::_collectSectionRow(currentRows, type);
    this->_unmarshalRow(sectionRow, type);
    currentRows = currentRows.substr(sectionRow.size());
  }
}

size_t ls::std::io::SerializableSectionPairSection::_unmarshalSectionHeader(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::type::byte_field sectionHeader = ls::std::io::SerializableSectionPairSection::_getSectionHeader(_data);
  ls::std::io::SerializableSectionPairSection::_checkSectionHeader(sectionHeader);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairSection>(this->value)->setSectionId(ls::std::io::SerializableSectionPairSection::_getSectionId(sectionHeader));

  return sectionHeader.size();
}
