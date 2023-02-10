/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-10
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/SectionPairRow.hpp>
#include <ls-std/io/section-pair/SectionPairRowSingleValue.hpp>

ls::std::io::SectionPairRow::SectionPairRow(const ls::std::io::section_pair_identifier &_key, const ls::std::io::SectionPairRowEnumType &_type) : ls::std::core::Class("SectionPairRow")
{
  this->_setKey(_key);
  this->_initValue(_type);
}

ls::std::io::SectionPairRow::~SectionPairRow() = default;

ls::std::io::section_pair_row_value ls::std::io::SectionPairRow::getKey()
{
  return this->key;
}

bool ls::std::io::SectionPairRow::isList()
{
  return this->value->getType() == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST;
}

bool ls::std::io::SectionPairRow::isSingleValue()
{
  return this->value->getType() == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE;
}

void ls::std::io::SectionPairRow::_initValue(const ls::std::io::SectionPairRowEnumType &_type)
{
  switch (_type)
  {
    case SECTION_PAIR_ROW_NOT_IMPLEMENTED:
    {
      throw ls::std::core::IllegalArgumentException{"default row enum type can not be set!"};
    }
    case SECTION_PAIR_ROW_LIST:
    {
    }
    break;
    case SECTION_PAIR_ROW_SINGLE_VALUE:
    {
      this->value = ::std::make_shared<ls::std::io::SectionPairRowSingleValue>("empty");
    }
    break;
  }
}

void ls::std::io::SectionPairRow::_setKey(const ls::std::io::section_pair_identifier &_key)
{
  ls::std::core::EmptyStringArgumentEvaluator{_key, "passed key identifier for section pair row is empty!"}.evaluate();
  ls::std::io::SectionPairIdentifierArgumentEvaluator(_key, "section pair key identifier \"" + _key + "\" contains invalid characters!").evaluate();
  this->key = _key;
}
