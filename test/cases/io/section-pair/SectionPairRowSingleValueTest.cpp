/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
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
  class SectionPairRowSingleValueTest : public ::testing::Test
  {
    protected:

      SectionPairRowSingleValueTest() = default;
      ~SectionPairRowSingleValueTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowSingleValueTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowSingleValue", SectionPairRowSingleValue{"blue"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowSingleValueTest, constructor_empty_value)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValue value{""};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, constructor_invalid_value)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValue value{"=33"};
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, get)
  {
    SectionPairRowSingleValue value{"blue"};
    ASSERT_STREQ("blue", value.get().c_str());
  }

  TEST_F(SectionPairRowSingleValueTest, getType)
  {
    SectionPairRowSingleValue value{"blue"};
    ASSERT_EQ(ls::std::io::SECTION_PAIR_ROW_SINGLE_VALUE, value.getType());
  }

  TEST_F(SectionPairRowSingleValueTest, set_empty_value)
  {
    SectionPairRowSingleValue value{"empty"};

    EXPECT_THROW(
        {
          try
          {
            value.set("");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(SectionPairRowSingleValueTest, set_invalid_value)
  {
    SectionPairRowSingleValue value{"empty"};

    EXPECT_THROW(
        {
          try
          {
            value.set("=33");
          }
          catch (const IllegalArgumentException &_exception)
          {
            throw;
          }
        },
        IllegalArgumentException);
  }
}
