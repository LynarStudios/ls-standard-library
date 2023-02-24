/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-23
*
* */

#include "SectionPairSectionProvider.hpp"

using ls::std::core::type::byte_field;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using std::string;
using test::io::SectionPairSectionProvider;

SectionPairSectionProvider::SectionPairSectionProvider() = default;

SectionPairSectionProvider::~SectionPairSectionProvider() = default;

shared_ptr<SectionPairSection> SectionPairSectionProvider::createSectionWithSandraExample()
{
  shared_ptr<SectionPairSection> generalSection = make_shared<SectionPairSection>("general");

  shared_ptr<SectionPairRow> name = make_shared<SectionPairRow>("name", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(name->getValue())->set("Sandra");
  generalSection->add(name);

  shared_ptr<SectionPairRow> age = make_shared<SectionPairRow>("age", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(age->getValue())->set("24");
  generalSection->add(age);

  shared_ptr<SectionPairRow> hobbies = make_shared<SectionPairRow>("hobbies", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  dynamic_pointer_cast<SectionPairRowListValue>(hobbies->getValue())->add("swimming");
  dynamic_pointer_cast<SectionPairRowListValue>(hobbies->getValue())->add("cycling");
  dynamic_pointer_cast<SectionPairRowListValue>(hobbies->getValue())->add("singing");
  generalSection->add(hobbies);

  return generalSection;
}

shared_ptr<SectionPairSection> SectionPairSectionProvider::createSectionWithTomExample()
{
  shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");

  shared_ptr<SectionPairRow> name = make_shared<SectionPairRow>("name", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(name->getValue())->set("Tom");
  section->add(name);

  shared_ptr<SectionPairRow> jobs = make_shared<SectionPairRow>("jobs", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  shared_ptr<SectionPairRowListValue> jobList = dynamic_pointer_cast<SectionPairRowListValue>(jobs->getValue());
  jobList->add("Farmer");
  jobList->add("Bounty Hunter");
  section->add(jobs);

  shared_ptr<SectionPairRow> age = make_shared<SectionPairRow>("age", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  dynamic_pointer_cast<SectionPairRowSingleValue>(age->getValue())->set("33");
  section->add(age);

  return section;
}

byte_field SectionPairSectionProvider::createSerializedSectionWithSandraExample(const string &_newLine)
{
  byte_field serializedDocument{};

  serializedDocument += _newLine + "[general]" + _newLine + _newLine;
  serializedDocument += "name=Sandra" + _newLine;
  serializedDocument += "age=24" + _newLine;
  serializedDocument += "hobbies:" + _newLine;
  serializedDocument += "  swimming" + _newLine;
  serializedDocument += "  cycling" + _newLine;
  serializedDocument += "  singing" + _newLine;

  return serializedDocument;
}

byte_field SectionPairSectionProvider::createSerializedSectionWithTomExample(const string &_newLine)
{
  byte_field serializedSection = _newLine + "[general]" + _newLine + _newLine;
  byte_field serializedNameRow = "name=Tom" + _newLine;
  byte_field serializedJobsRow = "jobs:" + _newLine + "  Farmer" + _newLine + "  Bounty Hunter" + _newLine;
  byte_field serializedAgeRow = "age=33" + _newLine;

  return serializedSection + serializedNameRow + serializedJobsRow + serializedAgeRow;
}
