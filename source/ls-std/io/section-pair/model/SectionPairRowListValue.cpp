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
#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowListValue.hpp>

using ls::std::core::Class;
using ls::std::core::ConditionalFunctionExecutor;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::IndexOutOfBoundsEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::section_pair_row_value;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowValue;
using ls::std::io::SectionPairValueArgumentEvaluator;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRowListValue;
using std::list;
using std::make_shared;

SectionPairRowListValue::SectionPairRowListValue() : Class("SectionPairRowListValue"), SectionPairRowValue(SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE)
{}

SectionPairRowListValue::~SectionPairRowListValue() noexcept = default;

void SectionPairRowListValue::add(const section_pair_row_value &_value)
{
  EmptyStringArgumentEvaluator{_value}.evaluate();
  SectionPairValueArgumentEvaluator{_value}.evaluate();
  this->values.push_back(_value);
}

void SectionPairRowListValue::clear()
{
  this->values.clear();
}

section_pair_row_value SectionPairRowListValue::get(size_t _index)
{
  IndexOutOfBoundsEvaluator(_index, this->values.size()).evaluate();
  section_pair_row_value value{};
  size_t index{};

  for (const auto &_value : this->values)
  {
    if (index == _index)
    {
      value = _value;
      break;
    }

    ++index;
  }

  return value;
}

list<section_pair_row_value> SectionPairRowListValue::getList()
{
  return this->values;
}

size_t SectionPairRowListValue::getSize()
{
  return this->values.size();
}

SectionPairRowEnumType SectionPairRowListValue::getType()
{
  return this->type;
}

byte_field SectionPairRowListValue::marshal()
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void SectionPairRowListValue::unmarshal(const byte_field &_data)
{
  ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void SectionPairRowListValue::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = make_shared<SerializableSectionPairRowListValue>(parameter);
}
