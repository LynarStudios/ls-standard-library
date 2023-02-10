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
    ASSERT_STREQ("SectionPairRow", SectionPairRow{"tmp-key"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowTest, constructor_empty_key)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRow row{""};
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
            SectionPairRow row{"-tmp-key"};
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

    SectionPairRow row{key};
    ASSERT_STREQ(key.c_str(), row.getKey().c_str());
  }

  TEST_F(SectionPairRowTest, isSingleValue)
  {
    ASSERT_FALSE(SectionPairRow{"tmp-key"}.isSingleValue());
  }

  TEST_F(SectionPairRowTest, isList)
  {
    ASSERT_FALSE(SectionPairRow{"tmp-key"}.isList());
  }
}