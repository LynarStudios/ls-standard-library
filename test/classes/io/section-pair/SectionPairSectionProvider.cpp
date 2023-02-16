/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-15
* Changed:         2023-02-16
*
* */

#include "SectionPairSectionProvider.hpp"

test::io::SectionPairSectionProvider::SectionPairSectionProvider() = default;

test::io::SectionPairSectionProvider::~SectionPairSectionProvider() = default;

::std::shared_ptr<ls::std::io::SectionPairSection> test::io::SectionPairSectionProvider::createSectionWithSandraExample()
{
  ::std::shared_ptr<ls::std::io::SectionPairSection> generalSection = ::std::make_shared<ls::std::io::SectionPairSection>("general");

  ::std::shared_ptr<ls::std::io::SectionPairRow> name = ::std::make_shared<ls::std::io::SectionPairRow>("name", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(name->getValue())->set("Sandra");
  generalSection->add(name);

  ::std::shared_ptr<ls::std::io::SectionPairRow> age = ::std::make_shared<ls::std::io::SectionPairRow>("age", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(age->getValue())->set("24");
  generalSection->add(age);

  ::std::shared_ptr<ls::std::io::SectionPairRow> hobbies = ::std::make_shared<ls::std::io::SectionPairRow>("hobbies", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(hobbies->getValue())->add("swimming");
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(hobbies->getValue())->add("cycling");
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(hobbies->getValue())->add("singing");
  generalSection->add(hobbies);

  return generalSection;
}

::std::shared_ptr<ls::std::io::SectionPairSection> test::io::SectionPairSectionProvider::createSectionWithTomExample()
{
  ::std::shared_ptr<ls::std::io::SectionPairSection> section = ::std::make_shared<ls::std::io::SectionPairSection>("general");

  ::std::shared_ptr<ls::std::io::SectionPairRow> name = ::std::make_shared<ls::std::io::SectionPairRow>("name", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(name->getValue())->set("Tom");
  section->add(name);

  ::std::shared_ptr<ls::std::io::SectionPairRow> jobs = ::std::make_shared<ls::std::io::SectionPairRow>("jobs", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE);
  ::std::shared_ptr<ls::std::io::SectionPairRowListValue> jobList = ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowListValue>(jobs->getValue());
  jobList->add("Farmer");
  jobList->add("Bounty Hunter");
  section->add(jobs);

  ::std::shared_ptr<ls::std::io::SectionPairRow> age = ::std::make_shared<ls::std::io::SectionPairRow>("age", ls::std::io::SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
  ::std::dynamic_pointer_cast<ls::std::io::SectionPairRowSingleValue>(age->getValue())->set("33");
  section->add(age);

  return section;
}

ls::std::core::type::byte_field test::io::SectionPairSectionProvider::createSerializedSectionWithSandraExample()
{
  ls::std::core::type::byte_field serializedDocument{};
  ::std::string newLine = ls::std::io::NewLine::get();

  serializedDocument += newLine + "[general]" + newLine + newLine;
  serializedDocument += "name=Sandra" + newLine;
  serializedDocument += "age=24" + newLine;
  serializedDocument += "hobbies:" + newLine;
  serializedDocument += "  swimming" + newLine;
  serializedDocument += "  cycling" + newLine;
  serializedDocument += "  singing" + newLine;

  return serializedDocument;
}

ls::std::core::type::byte_field test::io::SectionPairSectionProvider::createSerializedSectionWithTomExample()
{
  ::std::string newLine = ls::std::io::NewLine::get();

  ls::std::core::type::byte_field serializedSection = newLine + "[general]" + newLine + newLine;
  ls::std::core::type::byte_field serializedNameRow = "name=Tom" + newLine;
  ls::std::core::type::byte_field serializedJobsRow = "jobs:" + newLine + "  Farmer" + newLine + "  Bounty Hunter" + newLine;
  ls::std::core::type::byte_field serializedAgeRow = "age=33" + newLine;

  return serializedSection + serializedNameRow + serializedJobsRow + serializedAgeRow;
}
