/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-20
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowListValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowSingleValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRow.hpp>

ls::std::io::SerializableSectionPairRow::SerializableSectionPairRow(const SerializableSectionPairParameter &_parameter) : ls::std::core::Class("SerializableSectionPairRow")
{
  ::std::string message = this->getClassName() + ": model reference is null!";
  ls::std::core::NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

ls::std::io::SerializableSectionPairRow::~SerializableSectionPairRow() = default;

::std::shared_ptr<ls::std::core::Class> ls::std::io::SerializableSectionPairRow::getValue()
{
  return this->parameter.getValue();
}

ls::std::core::type::byte_field ls::std::io::SerializableSectionPairRow::marshal()
{
  ls::std::core::type::byte_field data = this->_marshalKey();
  ::std::shared_ptr<SectionPairRow> row = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRow>(this->parameter.getValue());
  row->getValue()->reserveNewLine(this->parameter.getNewLine());
  return data + row->getValue()->marshal();
}

void ls::std::io::SerializableSectionPairRow::unmarshal(const ls::std::core::type::byte_field &_data)
{
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRow>(this->parameter.getValue());
  row->getValue()->reserveNewLine(this->parameter.getNewLine());

  if (row->isSingleValue())
  {
    this->_unmarshalSingleValue(_data);
  }

  if (row->isList())
  {
    this->_unmarshalListValue(_data);
  }
}

::std::string ls::std::io::SerializableSectionPairRow::_marshalKey()
{
  ::std::string serializedKey{};
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRow>(this->parameter.getValue());

  if (row->isSingleValue())
  {
    serializedKey = row->getKey() + "=";
  }

  if (row->isList())
  {
    serializedKey = row->getKey() + ":" + this->parameter.getNewLine();
  }

  return serializedKey;
}

void ls::std::io::SerializableSectionPairRow::_unmarshalListValue(const ls::std::core::type::byte_field &_data)
{
  ls::std::io::SectionPairRowListValueArgumentEvaluator{_data}.evaluate();
  ::std::string::size_type separatorPosition = _data.find(':');
  ::std::string newLine = this->parameter.getNewLine();

  if (separatorPosition != ::std::string::npos)
  {
    ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRow>(this->parameter.getValue());
    row->setKey(_data.substr(0, separatorPosition));
    ::std::string::size_type newLinePosition = _data.find(newLine) + (newLine.size() - 1);
    ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(row->getValue())->unmarshal(_data.substr(newLinePosition + 1));
  }
}

void ls::std::io::SerializableSectionPairRow::_unmarshalSingleValue(const ls::std::core::type::byte_field &_data)
{
  ls::std::io::SectionPairRowSingleValueArgumentEvaluator{_data}.evaluate();
  ::std::string::size_type position = _data.find('=');

  if (position != ::std::string::npos)
  {
    ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRow>(this->parameter.getValue());
    row->setKey(_data.substr(0, position));
    ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(row->getValue())->unmarshal(_data.substr(position + 1));
  }
}
