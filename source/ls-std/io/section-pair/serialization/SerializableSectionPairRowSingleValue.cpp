/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-15
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.hpp>

ls::std::io::SerializableSectionPairRowSingleValue::SerializableSectionPairRowSingleValue(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairRowSingleValue::~SerializableSectionPairRowSingleValue() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairRowSingleValue::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRowSingleValue::marshal()
{
  return ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(this->value)->get() + ls::std::io::NewLine::get();
}

void ls::std::io::SerializableSectionPairRowSingleValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::EmptyStringArgumentEvaluator{_data}.evaluate();
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(this->value)->set(_data);
}

void ls::std::io::SerializableSectionPairRowSingleValue::_setValue(const ::std::shared_ptr<ls::std::core::Class> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value, "model reference for SerializableSectionPairRowSingleValue is null!"}.evaluate();
  this->value = _value;
}
