/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-10
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairRow.hpp>
#include <ls-std/io/section-pair/SectionPairRowValueArgumentEvaluator.hpp>

ls::std::io::SectionPairRow::SectionPairRow(const ls::std::io::section_pair_identifier &_key) : ls::std::core::Class("SectionPairRow")
{
  ls::std::core::EmptyStringArgumentEvaluator{_key, "passed key identifier for section pair row is empty!"}.evaluate();
  ls::std::io::SectionPairIdentifierArgumentEvaluator(_key, "section pair key identifier \"" + _key + "\" contains invalid characters!").evaluate();
  this->key = _key;
}

ls::std::io::SectionPairRow::~SectionPairRow() = default;

ls::std::io::section_pair_row_value ls::std::io::SectionPairRow::getKey()
{
  return this->key;
}

::std::string ls::std::io::SectionPairRow::getValue()
{
  return this->values.empty() ? "" : this->values.front();
}

bool ls::std::io::SectionPairRow::isKeyValue()
{
  return this->type == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_KEY_VALUE;
}

bool ls::std::io::SectionPairRow::isList()
{
  return this->type == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST;
}

void ls::std::io::SectionPairRow::setValue(const ls::std::io::section_pair_row_value &_value)
{
  ls::std::core::EmptyStringArgumentEvaluator{_value, "passed value for section pair row is empty!"}.evaluate();
  ls::std::io::SectionPairRowValueArgumentEvaluator{_value, "passed value for section pair row \"" + _value + "\" contains invalid characters!"}.evaluate();
  this->_setType(ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_KEY_VALUE);
  this->_setValue(_value);
}

void ls::std::io::SectionPairRow::_setType(const ls::std::io::SectionPairRowEnumType &_type)
{
  if (_type == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_NOT_IMPLEMENTED)
  {
    this->type = _type;
  }
}

void ls::std::io::SectionPairRow::_setValue(const ls::std::io::section_pair_row_value &_value)
{
  if (!this->values.empty())
  {
    this->values.pop_front();
  }

  this->values.push_back(_value);
}
