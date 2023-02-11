/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-11
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>

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
  ::std::string message = "member \"serializable\" for marshal attempt is null!";
  ls::std::core::NullPointerEvaluator{::std::reinterpret_pointer_cast<void>(this->serializable), message}.evaluate();
  return this->serializable->marshal();
}

void ls::std::io::SectionPairRowSingleValue::set(const ls::std::io::section_pair_row_value &_value)
{
  this->_set(_value);
}

void ls::std::io::SectionPairRowSingleValue::setSerializable(const ::std::shared_ptr<ls::std::core::interface_type::ISerializable> &_serializable)
{
  ls::std::core::NullPointerArgumentEvaluator{_serializable}.evaluate();
  this->serializable = _serializable;
}

void ls::std::io::SectionPairRowSingleValue::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ::std::string message = "member \"serializable\" for unmarshal attempt is null!";
  ls::std::core::NullPointerEvaluator{::std::reinterpret_pointer_cast<void>(this->serializable), message}.evaluate();
  this->serializable->unmarshal(_data);
}

void ls::std::io::SectionPairRowSingleValue::_set(const ls::std::io::section_pair_row_value &_value)
{
  ls::std::core::EmptyStringArgumentEvaluator{_value}.evaluate();
  ls::std::io::SectionPairRowValueArgumentEvaluator(_value, "section pair single value \"" + _value + "\" contains invalid characters!").evaluate();
  this->value = _value;
}
