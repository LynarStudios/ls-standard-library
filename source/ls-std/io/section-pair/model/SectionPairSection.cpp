/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-19
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairSection.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairSection.hpp>

ls::std::io::SectionPairSection::SectionPairSection(const ls::std::io::section_pair_identifier &_sectionId) : ls::std::core::Class("SectionPairSection")
{
  this->_setSectionId(_sectionId);
}

ls::std::io::SectionPairSection::~SectionPairSection() = default;

void ls::std::io::SectionPairSection::add(const section_pair_row_list_element &_row)
{
  ls::std::core::NullPointerArgumentEvaluator{::std::reinterpret_pointer_cast<void>(_row)}.evaluate();
  this->_rowExistenceCheck(_row->getKey());
  this->rows.push_back(_row);
}

void ls::std::io::SectionPairSection::clear()
{
  this->rows.clear();
}

ls::std::io::section_pair_row_list_element ls::std::io::SectionPairSection::get(size_t _index)
{
  ls::std::core::IndexOutOfBoundsEvaluator{_index, this->rows.size()}.evaluate();
  ls::std::io::section_pair_row_list_element element{};
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

ls::std::io::section_pair_row_list ls::std::io::SectionPairSection::getList()
{
  return this->rows;
}

size_t ls::std::io::SectionPairSection::getRowAmount()
{
  return this->rows.size();
}

ls::std::io::section_pair_identifier ls::std::io::SectionPairSection::getSectionId()
{
  return this->sectionId;
}

ls::std::core::type::byte_field ls::std::io::SectionPairSection::marshal()
{
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void ls::std::io::SectionPairSection::reserveNewLine(const ::std::string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void ls::std::io::SectionPairSection::setSectionId(const ls::std::io::section_pair_identifier &_sectionId)
{
  this->_setSectionId(_sectionId);
}

void ls::std::io::SectionPairSection::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void ls::std::io::SectionPairSection::_createSerializable()
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = ::std::make_shared<ls::std::io::SerializableSectionPairSection>(parameter);
}

bool ls::std::io::SectionPairSection::_hasRow(const ls::std::io::section_pair_identifier &_key)
{
  bool rowExists{};

  for (const auto &_row : this->rows)
  {
    if (_row->getKey() == _key)
    {
      rowExists = true;
      break;
    }
  }

  return rowExists;
}

void ls::std::io::SectionPairSection::_rowExistenceCheck(const ls::std::io::section_pair_identifier &_key)
{
  if (this->_hasRow(_key))
  {
    ::std::string message = this->getClassName() + ": row key \"" + _key + "\" already exists in section \"" + this->sectionId + "\"!";
    throw ls::std::core::IllegalArgumentException{message};
  }
}
void ls::std::io::SectionPairSection::_setSectionId(const ls::std::io::section_pair_identifier &_sectionId)
{
  ls::std::core::EmptyStringArgumentEvaluator{_sectionId}.evaluate();
  ls::std::io::SectionPairIdentifierArgumentEvaluator(_sectionId).evaluate();
  this->sectionId = _sectionId;
}
