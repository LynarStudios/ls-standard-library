/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-23
*
* */

#include "SerializableSectionPairRowProvider.hpp"

using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SerializableSectionPairParameter;
using ls::std::io::SerializableSectionPairRow;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::SerializableSectionPairRowProvider;

SerializableSectionPairRowProvider::SerializableSectionPairRowProvider() = default;

SerializableSectionPairRowProvider::~SerializableSectionPairRowProvider() = default;

shared_ptr<SerializableSectionPairRow> SerializableSectionPairRowProvider::createListValueForMarshal(const string &_newLine)
{
  SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-colors", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  parameter.setValue(row);
  shared_ptr<SectionPairRowListValue> listValue = dynamic_pointer_cast<SectionPairRowListValue>(row->getValue());
  listValue->add("blue");
  listValue->add("red");
  listValue->add("purple");

  return make_shared<SerializableSectionPairRow>(parameter);
}

shared_ptr<SerializableSectionPairRow> SerializableSectionPairRowProvider::createListValueForUnmarshal(const string &_newLine)
{
  SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  parameter.setValue(row);

  return make_shared<SerializableSectionPairRow>(parameter);
}

shared_ptr<SerializableSectionPairRow> SerializableSectionPairRowProvider::createSingleValueForMarshal(const string &_newLine)
{
  SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("favourite-color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  parameter.setValue(row);
  shared_ptr<SectionPairRowSingleValue> singleValue = dynamic_pointer_cast<SectionPairRowSingleValue>(row->getValue());
  singleValue->set("blue");

  return make_shared<SerializableSectionPairRow>(parameter);
}

shared_ptr<SerializableSectionPairRow> SerializableSectionPairRowProvider::createSingleValueForUnmarshal(const string &_newLine)
{
  SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  shared_ptr<SectionPairRow> row = make_shared<SectionPairRow>("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  parameter.setValue(row);

  return make_shared<SerializableSectionPairRow>(parameter);
}
