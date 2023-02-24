/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-24
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairMessageFormatter.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairSection.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairSection.hpp>

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::IllegalArgumentException;
using ls::std::core::IndexOutOfBoundsEvaluator;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::section_pair_identifier;
using ls::std::io::section_pair_row_list;
using ls::std::io::section_pair_row_list_element;
using ls::std::io::SectionPairIdentifierArgumentEvaluator;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairSection;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairSection;
using std::any_of;
using std::find_if;
using std::make_shared;
using std::reinterpret_pointer_cast;
using std::shared_ptr;
using std::string;

SectionPairSection::SectionPairSection(const section_pair_identifier &_sectionId) : Class("SectionPairSection")
{
  this->_setSectionId(_sectionId);
}

SectionPairSection::~SectionPairSection() noexcept = default;

void SectionPairSection::add(const section_pair_row_list_element &_row)
{
  NullPointerArgumentEvaluator{reinterpret_pointer_cast<void>(_row)}.evaluate();
  this->_rowExistenceCheck(_row->getKey());
  this->rows.push_back(_row);
}

void SectionPairSection::clear()
{
  this->rows.clear();
}

section_pair_row_list_element SectionPairSection::get(size_t _index)
{
  IndexOutOfBoundsEvaluator{_index, this->rows.size()}.evaluate();
  section_pair_row_list_element element{};
  size_t index{};

  for (const auto &_element : this->rows)
  {
    if (index == _index)
    {
      element = _element;
      break;
    }

    ++index;
  }

  return element;
}

section_pair_row_list_element SectionPairSection::get(const section_pair_identifier &_key)
{
  return this->_get(_key);
}

section_pair_row_list SectionPairSection::getList()
{
  return this->rows;
}

size_t SectionPairSection::getRowAmount()
{
  return this->rows.size();
}

section_pair_identifier SectionPairSection::getSectionId()
{
  return this->sectionId;
}

bool SectionPairSection::hasRow(const section_pair_identifier &_key)
{
  return this->_hasRow(_key);
}

byte_field SectionPairSection::marshal()
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void SectionPairSection::reserveNewLine(const string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void SectionPairSection::setSectionId(const section_pair_identifier &_sectionId)
{
  this->_setSectionId(_sectionId);
}

void SectionPairSection::unmarshal(const byte_field &_data)
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void SectionPairSection::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = make_shared<SerializableSectionPairSection>(parameter);
}

section_pair_row_list_element SectionPairSection::_get(const section_pair_identifier &_key)
{
  const auto &iterator = find_if(this->rows.begin(), this->rows.end(), [_key](const shared_ptr<SectionPairRow> &_row) { return _row->getKey() == _key; });
  return iterator != this->rows.end() ? *iterator : nullptr;
}

bool SectionPairSection::_hasRow(const section_pair_identifier &_key)
{
  return any_of(this->rows.begin(), this->rows.end(), [_key](const shared_ptr<SectionPairRow> &_row) { return _row->getKey() == _key; });
}

void SectionPairSection::_rowExistenceCheck(const section_pair_identifier &_key)
{
  if (this->_hasRow(_key))
  {
    string message = this->getClassName() + ": row key \"" + _key + "\" already exists in section \"" + this->sectionId + "\"!";
    throw IllegalArgumentException{SectionPairMessageFormatter::getFormattedMessage(message)};
  }
}
void SectionPairSection::_setSectionId(const section_pair_identifier &_sectionId)
{
  EmptyStringArgumentEvaluator{_sectionId}.evaluate();
  SectionPairIdentifierArgumentEvaluator(_sectionId).evaluate();
  this->sectionId = _sectionId;
}
