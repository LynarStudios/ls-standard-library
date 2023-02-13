/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-13
*
* */

#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/core/evaluator/NullPointerEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>

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

::std::shared_ptr<ls::std::io::SectionPairRowValue> ls::std::io::SectionPairRow::getValue()
{
  return this->value;
}

bool ls::std::io::SectionPairRow::isList()
{
  return this->value->getType() == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE;
}

bool ls::std::io::SectionPairRow::isSingleValue()
{
  return this->value->getType() == ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE;
}

ls::std::core::type::byte_field ls::std::io::SectionPairRow::marshal()
{
  ::std::string message = "member \"serializable\" for marshal attempt is null!";
  ls::std::core::NullPointerEvaluator{::std::reinterpret_pointer_cast<void>(this->serializable), message}.evaluate();
  return this->serializable->marshal();
}

void ls::std::io::SectionPairRow::setKey(const ls::std::io::section_pair_identifier &_key)
{
  this->_setKey(_key);
}

void ls::std::io::SectionPairRow::setSerializable(const ::std::shared_ptr<ls::std::core::interface_type::ISerializable> &_serializable)
{
  ::std::string message = this->getClassName() + ": argument \"_serializable\" is null!";
  ls::std::core::NullPointerArgumentEvaluator{::std::reinterpret_pointer_cast<void>(_serializable), message}.evaluate();
  this->serializable = _serializable;
}

void ls::std::io::SectionPairRow::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ::std::string message = this->getClassName() + ": member \"serializable\" for unmarshal attempt is null!";
  ls::std::core::NullPointerEvaluator{::std::reinterpret_pointer_cast<void>(this->serializable), message}.evaluate();
  this->serializable->unmarshal(_data);
}

void ls::std::io::SectionPairRow::_initValue(const ls::std::io::SectionPairRowEnumType &_type)
{
  switch (_type)
  {
    case SECTION_PAIR_ROW_NOT_IMPLEMENTED:
    {
      throw ls::std::core::IllegalArgumentException{this->getClassName() + ": default row enum type can not be set!"};
    }
    case SECTION_PAIR_ROW_LIST_VALUE:
    {
      this->value = ::std::make_shared<ls::std::io::SectionPairRowListValue>();
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
  ls::std::core::EmptyStringArgumentEvaluator{_key, this->getClassName() + ": passed key identifier is empty!"}.evaluate();
  ls::std::io::SectionPairIdentifierArgumentEvaluator(_key, this->getClassName() + ": section pair key identifier \"" + _key + "\" contains invalid characters!").evaluate();
  this->key = _key;
}
