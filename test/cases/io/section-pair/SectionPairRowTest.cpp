/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
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
    ASSERT_STREQ("SectionPairRow", SectionPairRow{"TMP_KEY"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowTest, getValue)
  {
    SectionPairRow row{"TMP_KEY"};
    ASSERT_TRUE(row.getValue().empty());
  }

  TEST_F(SectionPairRowTest, isKeyValue)
  {
    ASSERT_FALSE(SectionPairRow{"TMP_KEY"}.isKeyValue());
  }

  TEST_F(SectionPairRowTest, isList)
  {
    ASSERT_FALSE(SectionPairRow{"TMP_KEY"}.isList());
  }

  TEST_F(SectionPairRowTest, setValue_key_value)
  {
    SectionPairRow row{"color"};
    row.setValue("blue");

    ASSERT_STREQ("blue", row.getValue().c_str());
  }
}