/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-13
* Changed:         2023-02-14
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SectionPairSectionTest : public ::testing::Test
  {
    protected:

      SectionPairSectionTest() = default;
      ~SectionPairSectionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
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

  TEST_F(SectionPairSectionTest, getClassName)
  {
    ASSERT_STREQ("SectionPairSection", SectionPairSection{"general"}.getClassName().c_str());
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

  TEST_F(SectionPairSectionTest, get)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    section->add(make_shared<SectionPairRow>("color", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE));

    ASSERT_TRUE(section->get(0) != nullptr);
  }

  TEST_F(SectionPairSectionTest, get_out_of_bounds)
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

  TEST_F(SectionPairSectionTest, getAmount)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    ASSERT_EQ(0, section->getRowAmount());
  }

  TEST_F(SectionPairSectionTest, getSectionId)
  {
    shared_ptr<SectionPairSection> section = make_shared<SectionPairSection>("general");
    ASSERT_STREQ("general", section->getSectionId().c_str());
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
}
