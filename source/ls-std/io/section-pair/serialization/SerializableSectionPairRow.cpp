/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-11
* Changed:         2023-02-23
*
* */

#include <ls-std/core/evaluator/NullPointerArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowListValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/evaluator/SectionPairRowSingleValueArgumentEvaluator.hpp>
#include <ls-std/io/section-pair/model/SectionPairRow.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowListValue.hpp>
#include <ls-std/io/section-pair/model/SectionPairRowSingleValue.hpp>
#include <ls-std/io/section-pair/serialization/SerializableSectionPairRow.hpp>

using ls::std::core::Class;
using ls::std::core::NullPointerArgumentEvaluator;
using ls::std::core::type::byte_field;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowListValueArgumentEvaluator;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairRowSingleValueArgumentEvaluator;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRow;
using std::dynamic_pointer_cast;
using std::shared_ptr;
using std::string;

SerializableSectionPairRow::SerializableSectionPairRow(const SerializableSectionPairParameter &_parameter) : Class("SerializableSectionPairRow")
{
  string message = this->getClassName() + ": model reference is null!";
  NullPointerArgumentEvaluator{_parameter.getValue(), message}.evaluate();
  this->parameter = _parameter;
}

SerializableSectionPairRow::~SerializableSectionPairRow() noexcept = default;

shared_ptr<Class> SerializableSectionPairRow::getValue()
{
  return this->parameter.getValue();
}

byte_field SerializableSectionPairRow::marshal()
{
  byte_field data = this->_marshalKey();
  shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(this->parameter.getValue());
  row->getValue()->reserveNewLine(this->parameter.getNewLine());
  return data + row->getValue()->marshal();
}

void SerializableSectionPairRow::unmarshal(const byte_field &_data)
{
  shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(this->parameter.getValue());
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

string SerializableSectionPairRow::_marshalKey()
{
  string serializedKey{};
  shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(this->parameter.getValue());

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

void SerializableSectionPairRow::_unmarshalListValue(const byte_field &_data)
{
  SectionPairRowListValueArgumentEvaluator{_data}.evaluate();
  string::size_type separatorPosition = _data.find(':');
  string newLine = this->parameter.getNewLine();

  if (separatorPosition != string::npos)
  {
    shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(this->parameter.getValue());
    row->setKey(_data.substr(0, separatorPosition));
    string::size_type newLinePosition = _data.find(newLine) + (newLine.size() - 1);
    dynamic_pointer_cast<SectionPairRowListValue>(row->getValue())->unmarshal(_data.substr(newLinePosition + 1));
  }
}

void SerializableSectionPairRow::_unmarshalSingleValue(const byte_field &_data)
{
  SectionPairRowSingleValueArgumentEvaluator{_data}.evaluate();
  string::size_type position = _data.find('=');

  if (position != string::npos)
  {
    shared_ptr<SectionPairRow> row = dynamic_pointer_cast<SectionPairRow>(this->parameter.getValue());
    row->setKey(_data.substr(0, position));
    dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue())->unmarshal(_data.substr(position + 1));
  }
}
