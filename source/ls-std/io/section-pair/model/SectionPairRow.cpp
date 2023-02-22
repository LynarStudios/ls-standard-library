/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
*
* */

#include <ls-std/core/ConditionalFunctionExecutor.hpp>
#include <ls-std/core/evaluator/EmptyStringArgumentEvaluator.hpp>
#include <ls-std/core/exception/IllegalArgumentException.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairIdentifierArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRow.hpp>

ls::std::io::SectionPairRow::SectionPairRow(const ls::std::io::section_pair_identifier &_key, const ls::std::io::SectionPairRowEnumType &_type) : ls::std::core::Class("SectionPairRow")
{
  this->_setKey(_key);
  this->_initValue(_type);
}

ls::std::io::SectionPairRow::~SectionPairRow() noexcept = default;

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
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  return this->serializable->marshal();
}

void ls::std::io::SectionPairRow::reserveNewLine(const ::std::string &_reservedNewLine)
{
  this->reservedNewLine = _reservedNewLine;
}

void ls::std::io::SectionPairRow::setKey(const ls::std::io::section_pair_identifier &_key)
{
  this->_setKey(_key);
}

void ls::std::io::SectionPairRow::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ls::std::core::ConditionalFunctionExecutor{this->serializable == nullptr}.execute([this] { _createSerializable(); });
  this->serializable->unmarshal(_data);
}

void ls::std::io::SectionPairRow::_createSerializable()
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setValue(shared_from_this());

  if (!this->reservedNewLine.empty())
  {
    parameter.setNewLine(this->reservedNewLine);
  }

  this->serializable = ::std::make_shared<ls::std::io::SerializableSectionPairRow>(parameter);
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
  ls::std::io::SectionPairIdentifierArgumentEvaluator(_key).evaluate();
  this->key = _key;
}
