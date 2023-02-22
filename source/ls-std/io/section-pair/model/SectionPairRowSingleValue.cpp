/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-19
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.hpp>

ls::std::io::SectionPairRowSingleValue::SectionPairRowSingleValue(const ls::std::io::section_pair_row_value &_value) : ls::std::core::Class("SectionPairRowSingleValue"), ls::std::io::SectionPairRowValue(ls::std::io::SECTION_PAIR_ROW_SINGLE_VALUE)
{
  this->_set(_value);
}

ls::std::io::SectionPairRowSingleValue::~SectionPairRowSingleValue() = default;

ls::std::io::section_pair_row_value ls::std::io::SectionPairRowSingleValue::get()
{
  return this->value;
}

ls::std::io::SectionPairRowEnumType ls::std::io::SectionPairRowSingleValue::getType()
{
  return this->type;
}

ls::std::core::type::byte_field ls::std::io::SectionPairRowSingleValue::marshal()
{
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void ls::std::io::SectionPairRowSingleValue::set(const ls::std::io::section_pair_row_value &_value)
{
  this->_set(_value);
}

void ls::std::io::SectionPairRowSingleValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void ls::std::io::SectionPairRowSingleValue::_createSerializable()
{
  SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = ::std::make_shared<ls::std::io::SerializableSectionPairRowSingleValue>(parameter);
}

void ls::std::io::SectionPairRowSingleValue::_set(const ls::std::io::section_pair_row_value &_value)
{
  ls::std::core::EmptyStringArgumentEvaluator{_value}.evaluate();
  ls::std::io::SectionPairValueArgumentEvaluator(_value).evaluate();
  ::std::string newLine = this->reservedNewLine.empty() ? NewLine::get() : this->reservedNewLine;
  this->value = _value;

  if (this->value.find(newLine) != ::std::string::npos)
  {
    this->value.replace(this->value.find(newLine), newLine.size(), "");
  }
}
