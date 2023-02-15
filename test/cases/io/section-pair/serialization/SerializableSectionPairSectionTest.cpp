/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-14
* Changed:         2023-02-15
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <memory>

using namespace ls::std::core;
using namespace ls::std::core::type;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SerializableSectionPairSectionTest : public ::testing::Test
  {
    protected:

      SerializableSectionPairSectionTest() = default;
      ~SerializableSectionPairSectionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}

      static shared_ptr<SectionPairSection> createSection()
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

      static byte_field createSerializedSection()
      {
        byte_field serializedSection = NewLine::get() + "[general]" + NewLine::get();
        byte_field serializedNameRow = "name=Tom" + NewLine::get();
        byte_field serializedJobsRow = "jobs:" + NewLine::get() + "  Farmer" + NewLine::get() + "  Bounty Hunter" + NewLine::get();
        byte_field serializedAgeRow = "age=33" + NewLine::get();

        return serializedSection + serializedNameRow + serializedJobsRow + serializedAgeRow;
      }
  };

  TEST_F(SerializableSectionPairSectionTest, constructor_no_reference)
  {
    EXPECT_THROW(
        {
          try
          {
            SerializableSectionPairSection serializable(nullptr);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SerializableSectionPairSectionTest, getValue)
  {
    SerializableSectionPairSection serializable{make_shared<SectionPairSection>("general")};
    ASSERT_TRUE(serializable.getValue() != nullptr);
  }

  TEST_F(SerializableSectionPairSectionTest, marshal)
  {
    shared_ptr<SectionPairSection> section = SerializableSectionPairSectionTest::createSection();
    SerializableSectionPairSection serializable{section};
    byte_field expected = SerializableSectionPairSectionTest::createSerializedSection();
    byte_field actual = serializable.marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SerializableSectionPairSectionTest, unmarshal)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    SerializableSectionPairSection serializable{section};
    serializable.unmarshal(SerializableSectionPairSectionTest::createSerializedSection());

    ASSERT_STREQ("general", section->getSectionId().c_str());
    ASSERT_EQ(3, section->getRowAmount());
    ASSERT_STREQ("name", section->get(0)->getKey().c_str());
    ASSERT_STREQ("Tom", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(0)->getValue())->get().c_str());
    ASSERT_STREQ("jobs", section->get(1)->getKey().c_str());
    shared_ptr<SectionPairRowListValue> listRow = dynamic_pointer_cast<SectionPairRowListValue>(section->get(1)->getValue());
    ASSERT_EQ(2, listRow->getSize());
    ASSERT_STREQ("Farmer", listRow->get(0).c_str());
    ASSERT_STREQ("Bounty Hunter", listRow->get(1).c_str());
    ASSERT_STREQ("age", section->get(2)->getKey().c_str());
    ASSERT_STREQ("33", dynamic_pointer_cast<SectionPairRowSingleValue>(section->get(2)->getValue())->get().c_str());
  }
}
