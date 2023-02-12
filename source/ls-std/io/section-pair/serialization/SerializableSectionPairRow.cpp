/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-12
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/NewLine.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRow.hpp>

ls::std::io::SerializableSectionPairRow::SerializableSectionPairRow(const ::std::shared_ptr<ls::std::io::SectionPairRow> &_value)
{
  this->_setValue(_value);
}

ls::std::io::SerializableSectionPairRow::~SerializableSectionPairRow() = default;

::std::shared_ptr<ls::std::io::SectionPairRow> ls::std::io::SerializableSectionPairRow::getValue()
{
  return this->value;
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRow::marshal()
{
  ls::std::core::type::byte_field data = this->_marshalKey();
  return data + this->value->getValue()->marshal();
}

void ls::std::io::SerializableSectionPairRow::unmarshal(const ls::std::core::type::byte_field &_data)
{
  if (this->value->isSingleValue())
  {
    this->_unmarshalSingleValue(_data);
  }

  if (this->value->isList())
  {
    this->_unmarshalListValue(_data);
  }
}

::std::string ls::std::io::SerializableSectionPairRow::_marshalKey()
{
  ::std::string serializedKey{};

  if (this->value->isSingleValue())
  {
    serializedKey = this->value->getKey() + "=";
  }

  if (this->value->isList())
  {
    serializedKey = this->value->getKey() + ":" + ls::std::io::NewLine::get();
  }

  return serializedKey;
}

void ls::std::io::SerializableSectionPairRow::_setValue(const ::std::shared_ptr<ls::std::io::SectionPairRow> &_value)
{
  ls::std::core::NullPointerArgumentEvaluator{_value}.evaluate();
  this->value = _value;
}

void ls::std::io::SerializableSectionPairRow::_unmarshalListValue(const ls::std::core::type::byte_field &_data)
{
  ::std::string::size_type separatorPosition = _data.find(':');
  ls::std::io::section_pair_identifier identifier{};

  if (separatorPosition != ::std::string::npos)
  {
    this->value->setKey(_data.substr(0, separatorPosition));
    ::std::string::size_type newLinePosition = _data.find(NewLine::get()) + (NewLine::get().size() - 1);
    ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(this->value->getValue())->unmarshal(_data.substr(newLinePosition + 1));
  }
}

void ls::std::io::SerializableSectionPairRow::_unmarshalSingleValue(const ls::std::core::type::byte_field &_data)
{
  ::std::string::size_type position = _data.find('=');
  ls::std::io::section_pair_identifier identifier{};

  if (position != ::std::string::npos)
  {
    this->value->setKey(_data.substr(0, position));
    ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(this->value->getValue())->unmarshal(_data.substr(position + 1));
  }
}
