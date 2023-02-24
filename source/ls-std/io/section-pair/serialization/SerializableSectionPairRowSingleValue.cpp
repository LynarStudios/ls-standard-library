/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRowSingleValue.hpp>

using ls::std::core::Class;
using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRowSingleValue;
using std::dynamic_pointer_cast;
using std::shared_ptr;
using std::string;

SerializableSectionPairRowSingleValue::SerializableSectionPairRowSingleValue(const SerializableSectionPairParameter &_parameter) : Class("SerializableSectionPairRowSingleValue")
{
  string message = this->getClassName() + ": model reference is null!";
  NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

SerializableSectionPairRowSingleValue::~SerializableSectionPairRowSingleValue() noexcept = default;

shared_ptr<Class> SerializableSectionPairRowSingleValue::getValue()
{
  return this->parameter.getValue();
}

byte_field SerializableSectionPairRowSingleValue::marshal()
{
  return dynamic_pointer_cast<SectionPairRowSingleValue>(this->parameter.getValue())->get() + this->parameter.getNewLine();
}

void SerializableSectionPairRowSingleValue::unmarshal(const byte_field &_data)
{
  EmptyStringArgumentEvaluator{_data}.evaluate();
  dynamic_pointer_cast<SectionPairRowSingleValue>(this->parameter.getValue())->set(_data);
}
