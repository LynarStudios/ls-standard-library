/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-22
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.hpp>

ls::std::io::SerializableSectionPairRowSingleValue::SerializableSectionPairRowSingleValue(const ls::std::io::SerializableSectionPairParameter &_parameter) : ls::std::core::Class("SerializableSectionPairRowSingleValue")
{
  ::std::string message = this->getClassName() + ": model reference is null!";
  ls::std::core::NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

ls::std::io::SerializableSectionPairRowSingleValue::~SerializableSectionPairRowSingleValue() noexcept = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairRowSingleValue::getValue()
{
  return this->parameter.getValue();
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRowSingleValue::marshal()
{
  return ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(this->parameter.getValue())->get() + this->parameter.getNewLine();
}

void ls::std::io::SerializableSectionPairRowSingleValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::EmptyStringArgumentEvaluator{_data}.evaluate();
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(this->parameter.getValue())->set(_data);
}
