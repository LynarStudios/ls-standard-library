/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#include <ls-std/io/section-pair/SectionPairRow.hpp>

ls::std::io::SectionPairRow::SectionPairRow(const ::std::string &_key) : ls::std::core::Class("SectionPairRow")
{
  //ls::std::io::SectionPairRowKeyArgumentEvaluator{_key}.evaluate();
  this->key = _key;
}

ls::std::io::SectionPairRow::~SectionPairRow() = default;

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

void ls::std::io::SectionPairRow::setValue(const ::std::string &_value)
{
  //ls::std::core::EmptyStringArgumentEvaluator{_value}.evaluate();
  if (!this->values.empty())
  {
    this->values.pop_front();
  }

  this->values.push_back(_value);
}
