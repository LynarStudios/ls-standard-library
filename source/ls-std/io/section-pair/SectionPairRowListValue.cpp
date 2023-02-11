/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-11
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/IndexOutOfBoundsEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/SectionPairRowValueArgumentEvaluator.hpp>

ls::std::io::SectionPairRowListValue::SectionPairRowListValue() : ls::std::core::Class("SectionPairRowListValue"), ls::std::io::SectionPairRowValue(ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE)
{}

ls::std::io::SectionPairRowListValue::~SectionPairRowListValue() = default;

void ls::std::io::SectionPairRowListValue::add(const ls::std::io::section_pair_row_value &_value)
{
  ls::std::core::EmptyStringArgumentEvaluator{_value}.evaluate();
  ls::std::io::SectionPairRowValueArgumentEvaluator{_value, "section pair row list value \"" + _value + "\" contains invalid characters!"}.evaluate();
  this->values.push_back(_value);
}

ls::std::io::section_pair_row_value ls::std::io::SectionPairRowListValue::get(size_t _index)
{
  ls::std::core::IndexOutOfBoundsEvaluator(_index, this->values.size()).evaluate();
  ls::std::io::section_pair_row_value value{};
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

::std::list<ls::std::io::section_pair_row_value> ls::std::io::SectionPairRowListValue::getList()
{
  return this->values;
}

size_t ls::std::io::SectionPairRowListValue::getSize()
{
  return this->values.size();
}

ls::std::io::SectionPairRowEnumType ls::std::io::SectionPairRowListValue::getType()
{
  return this->type;
}
