/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-10
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
  class SectionPairRowTest : public ::testing::Test
  {
    protected:

      SectionPairRowTest() = default;
      ~SectionPairRowTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRow", SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_LIST_VALUE).getClassName().c_str());
  }

  TEST_F(SectionPairRowTest, constructor_empty_key)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRow row("", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, constructor_invalid_key)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRow row("-tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowTest, getKey)
  {
    ls::std::io::section_pair_identifier key = "tmp-key";

    SectionPairRow row(key, SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE);
    ASSERT_STREQ(key.c_str(), row.getKey().c_str());
  }

  TEST_F(SectionPairRowTest, isSingleValue)
  {
    ASSERT_TRUE(SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE).isSingleValue());
  }

  TEST_F(SectionPairRowTest, isList)
  {
    ASSERT_FALSE(SectionPairRow("tmp-key", SectionPairRowEnumType::SECTION_PAIR_ROW_SINGLE_VALUE).isList());
  }
}