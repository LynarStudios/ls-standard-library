/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-11
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SerializableSectionPairRowSingleValue.hpp>

ls::std::io::SerializableSectionPairRowSingleValue::SerializableSectionPairRowSingleValue(const ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> &_value)
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairRowSingleValue::~SerializableSectionPairRowSingleValue() = default;

::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> ls::std::io::SerializableSectionPairRowSingleValue::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRowSingleValue::marshal()
{
  return this->value->get();
}

void ls::std::io::SerializableSectionPairRowSingleValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::EmptyStringArgumentEvaluator{_data}.evaluate();
  this->value->set(_data);
}

void ls::std::io::SerializableSectionPairRowSingleValue::_setValue(const ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value, "model reference for SerializableSectionPairRowSingleValue is null!"}.evaluate();
  this->value = _value;
}
