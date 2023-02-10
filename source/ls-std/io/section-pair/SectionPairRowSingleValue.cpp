/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-10
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/SectionPairRowValueArgumentEvaluator.hpp>

ls::std::io::SectionPairRowSingleValue::SectionPairRowSingleValue(const ls::std::io::section_pair_row_value &_value) : ls::std::core::Class("SectionPairRowSingleValue"), ls::std::io::SectionPairRowValue(ls::std::io::SECTION_PAIR_ROW_SINGLE_VALUE)
{
  ls::std::core::EmptyStringArgumentEvaluator{_value}.evaluate();
  ls::std::io::SectionPairRowValueArgumentEvaluator(_value, "section pair single value \"" + _value + "\" contains invalid characters!").evaluate();
  this->value = _value;
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
