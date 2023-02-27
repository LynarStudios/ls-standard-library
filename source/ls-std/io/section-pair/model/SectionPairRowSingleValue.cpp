/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-23
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.hpp>

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::NewLine;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairRowValue;
using ls::std::io::SectionPairValueArgumentEvaluator;
using ls::std::io::SerializableSectionPairRowSingleValue;
using std::make_shared;
using std::string;

SectionPairRowSingleValue::SectionPairRowSingleValue(const section_pair_row_value &_value) : Class("SectionPairRowSingleValue"), SectionPairRowValue(SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE)
{
  this->_set(_value);
}

SectionPairRowSingleValue::~SectionPairRowSingleValue() noexcept = default;

section_pair_row_value SectionPairRowSingleValue::get()
{
  return this->value;
}

SectionPairRowEnumType SectionPairRowSingleValue::getType()
{
  return this->type;
}

byte_field SectionPairRowSingleValue::marshal()
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void SectionPairRowSingleValue::set(const section_pair_row_value &_value)
{
  this->_set(_value);
}

void SectionPairRowSingleValue::unmarshal(const byte_field &_data)
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void SectionPairRowSingleValue::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = make_shared<SerializableSectionPairRowSingleValue>(parameter);
}

void SectionPairRowSingleValue::_set(const section_pair_row_value &_value)
{
  EmptyStringArgumentEvaluator{_value}.evaluate();
  SectionPairValueArgumentEvaluator(_value).evaluate();
  string newLine = this->reservedNewLine.empty() ? NewLine::get() : this->reservedNewLine;
  this->value = _value;

  if (this->value.find(newLine) != string::npos)
  {
    this->value.replace(this->value.find(newLine), newLine.size(), "");
  }
}
