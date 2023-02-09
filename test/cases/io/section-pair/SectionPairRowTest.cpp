/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-09
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
    ::std::string key = "tmp-key";

    SectionPairRow row{key};
    ASSERT_STREQ(key.c_str(), row.getKey().c_str());
  }

  TEST_F(SectionPairRowTest, getValue)
  {
    SectionPairRow row{"tmp-key"};
    ASSERT_TRUE(row.getValue().empty());
  }

  TEST_F(SectionPairRowTest, isKeyValue)
  {
    ASSERT_FALSE(SectionPairRow{"tmp-key"}.isKeyValue());
  }

  TEST_F(SectionPairRowTest, isList)
  {
    ASSERT_FALSE(SectionPairRow{"tmp-key"}.isList());
  }

  TEST_F(SectionPairRowTest, setValue_key_value)
  {
    SectionPairRow row{"color"};
    row.setValue("blue");

    ASSERT_STREQ("blue", row.getValue().c_str());
  }

  TEST_F(SectionPairRowTest, setValue_key_value_empty_value)
  {
    SectionPairRow row{"color"};

    EXPECT_THROW(
        {
          try
          {
            row.setValue("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}