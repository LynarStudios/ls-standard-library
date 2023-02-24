/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-23
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRow.hpp>

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::IllegalArgumentException;
using ls::std::core::type::byte_field;
using ls::std::io::section_pair_identifier;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairIdentifierArgumentEvaluator;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairRowValue;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRow;
using std::make_shared;
using std::shared_ptr;
using std::string;

SectionPairRow::SectionPairRow(const section_pair_identifier &_key, const SectionPairRowEnumType &_type) : Class("SectionPairRow")
{
  this->_setKey(_key);
  this->_initValue(_type);
}

SectionPairRow::~SectionPairRow() noexcept = default;

section_pair_row_value SectionPairRow::getKey()
{
  return this->key;
}

shared_ptr<SectionPairRowValue> SectionPairRow::getValue()
{
  return this->value;
}

bool SectionPairRow::isList()
{
  return this->value->getType() == SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE;
}

bool SectionPairRow::isSingleValue()
{
  return this->value->getType() == SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE;
}

byte_field SectionPairRow::marshal()
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void SectionPairRow::reserveNewLine(const string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void SectionPairRow::setKey(const section_pair_identifier &_key)
{
  this->_setKey(_key);
}

void SectionPairRow::unmarshal(const byte_field &_data)
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void SectionPairRow::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = make_shared<SerializableSectionPairRow>(parameter);
}

void SectionPairRow::_initValue(const SectionPairRowEnumType &_type)
{
  switch (_type)
  {
    case SECTION_PAIR_ROW_NOT_IMPLEMENTED:
    {
      throw IllegalArgumentException{this->getClassName() + ": default row enum type can not be set!"};
    }
    case SECTION_PAIR_ROW_LIST_VALUE:
    {
      this->value = make_shared<SectionPairRowListValue>();
    }
    break;
    case SECTION_PAIR_ROW_SINGLE_VALUE:
    {
      this->value = make_shared<SectionPairRowSingleValue>("empty");
    }
    break;
  }
}

void SectionPairRow::_setKey(const section_pair_identifier &_key)
{
  EmptyStringArgumentEvaluator{_key, this->getClassName() + ": passed key identifier is empty!"}.evaluate();
  SectionPairIdentifierArgumentEvaluator(_key).evaluate();
  this->key = _key;
}
