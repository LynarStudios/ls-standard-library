/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-17
* Changed:         2023-02-17
*
* */

#include "SerializableSectionPairRowProvider.hpp"

test::io::SerializableSectionPairRowProvider::SerializableSectionPairRowProvider() = default;

test::io::SerializableSectionPairRowProvider::~SerializableSectionPairRowProvider() = default;

::std::shared_ptr<ls::std::io::SerializableSectionPairRow> test::io::SerializableSectionPairRowProvider::createListValueForMarshal(const ::std::string &_newLine)
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::make_shared<ls::std::io::SectionPairRow>("favourite-colors", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  parameter.setValue(row);
  ::std::shared_ptr<ls::std::io::SectionPairRowListValue> listValue = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(row->getValue());
  listValue->add("blue");
  listValue->add("red");
  listValue->add("purple");

  return ::std::make_shared<ls::std::io::SerializableSectionPairRow>(parameter);
}

::std::shared_ptr<ls::std::io::SerializableSectionPairRow> test::io::SerializableSectionPairRowProvider::createListValueForUnmarshal(const ::std::string &_newLine)
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::make_shared<ls::std::io::SectionPairRow>("tmp-key", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  parameter.setValue(row);

  return ::std::make_shared<ls::std::io::SerializableSectionPairRow>(parameter);
}

::std::shared_ptr<ls::std::io::SerializableSectionPairRow> test::io::SerializableSectionPairRowProvider::createSingleValueForMarshal(const ::std::string &_newLine)
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::make_shared<ls::std::io::SectionPairRow>("favourite-color", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  parameter.setValue(row);
  ::std::shared_ptr<ls::std::io::SectionPairRowSingleValue> singleValue = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(row->getValue());
  singleValue->set("blue");

  return ::std::make_shared<ls::std::io::SerializableSectionPairRow>(parameter);
}

::std::shared_ptr<ls::std::io::SerializableSectionPairRow> test::io::SerializableSectionPairRowProvider::createSingleValueForUnmarshal(const ::std::string &_newLine)
{
  ls::std::io::SerializableSectionPairParameter parameter{};
  parameter.setNewLine(_newLine);
  ::std::shared_ptr<ls::std::io::SectionPairRow> row = ::std::make_shared<ls::std::io::SectionPairRow>("tmp-key", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  parameter.setValue(row);

  return ::std::make_shared<ls::std::io::SerializableSectionPairRow>(parameter);
}
