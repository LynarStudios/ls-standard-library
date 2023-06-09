/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using ls::std::core::IllegalArgumentException;
using ls::std::core::IndexOutOfBoundsException;
using ls::std::core::type::byte_field;
using ls::std::io::NewLine;
using ls::std::io::section_pair_row_list_element;
using ls::std::io::SectionPairRow;
using ls::std::io::SectionPairRowEnumType;
using ls::std::io::SectionPairRowListValue;
using ls::std::io::SectionPairRowSingleValue;
using ls::std::io::SectionPairSection;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::shared_ptr;
using test::io::SectionPairSectionProvider;
using testing::Test;

namespace
{
  class SectionPairSectionTest : public Test
  {
    public:

      SectionPairSectionTest() = default;
      ~SectionPairSectionTest() override = default;
  };

  TEST_F(SectionPairSectionTest, constructor_empty_id)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairSection section{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairSectionTest, constructor_invalid_id)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairSection section = SectionPairSection{"SERVER"};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairSectionTest, add)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_EQ(1, section->getRowAmount());
  }

  TEST_F(SectionPairSectionTest, add_row_already_exists)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    EXPECT_THROW(
        {
          try
          {
            section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairSectionTest, clear)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_EQ(1, section->getRowAmount());
    section->clear();
    ASSERT_TRUE(section->getList().empty());
  }

  TEST_F(SectionPairSectionTest, get_by_index)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_TRUE(section->get(0) != nullptr);
  }

  TEST_F(SectionPairSectionTest, get_by_index_out_of_bounds)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");

    EXPECT_THROW(
        {
          try
          {
            section_pair_row_list_element element = section->get(1);
          }
          catch (const IndexOutOfBoundsException &_exception)
          {
            throw;
          }
        },
        IndexOutOfBoundsException);
  }

  TEST_F(SectionPairSectionTest, get_by_key)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_TRUE(section->get("color") != nullptr);
  }

  TEST_F(SectionPairSectionTest, get_by_key_not_found)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_TRUE(section->get("hobbies") == nullptr);
  }

  TEST_F(SectionPairSectionTest, getAmount)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    ASSERT_EQ(0, section->getRowAmount());
  }

  TEST_F(SectionPairSectionTest, getClassName)
  {
    ASSERT_STREQ("SectionPairSection", SectionPairSection{"general"}.getClassName().c_str());
  }

  TEST_F(SectionPairSectionTest, getList)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    ASSERT_TRUE(section->getList().empty());
  }

  TEST_F(SectionPairSectionTest, getSectionId)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    ASSERT_STREQ("general", section->getSectionId().c_str());
  }

  TEST_F(SectionPairSectionTest, hasRow)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_TRUE(section->hasRow("color"));
  }

  TEST_F(SectionPairSectionTest, hasRow_not_found)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_FALSE(section->hasRow("hobbies"));
  }

  TEST_F(SectionPairSectionTest, marshal)
  {
    shared_ptr<SectionPairSection> section = SectionPairSectionProvider::createSectionWithTomExample();
    byte_field expected = SectionPairSectionProvider::createSerializedSectionWithTomExample(NewLine::get());
    byte_field actual = section->marshal();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_F(SectionPairSectionTest, setSectionId)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");

    section->setSectionId("personal");
    ASSERT_STREQ("personal", section->getSectionId().c_str());
  }

  TEST_F(SectionPairSectionTest, setSectionId_empty_id)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");

    EXPECT_THROW(
        {
          try
          {
            section->setSectionId("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairSectionTest, setSectionId_invalid_id)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");

    EXPECT_THROW(
        {
          try
          {
            section->setSectionId("PERSONAL");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairSectionTest, unmarshal)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("tmp-id");
    section->unmarshal(SectionPairSectionProvider::createSerializedSectionWithTomExample(NewLine::get()));

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
