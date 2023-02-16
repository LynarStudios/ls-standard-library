/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-16
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
  class SectionPairRowValueValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowValueValidatorTest() = default;
      ~SectionPairRowValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(SectionPairRowValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowValueValidator", SectionPairRowValueValidator{"any value"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowValueValidatorTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowValueValidator{"blue is my favourite color!"}.isValid());
    ASSERT_TRUE(SectionPairRowValueValidator{"Age"}.isValid());
    ASSERT_TRUE(SectionPairRowValueValidator{"Tom"}.isValid());
    ASSERT_TRUE(SectionPairRowValueValidator{"\"Tom\""}.isValid());
    ASSERT_TRUE(SectionPairRowValueValidator{"Hello!" + NewLine::get()}.isValid());
  }

  TEST_F(SectionPairRowValueValidatorTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowValueValidator{"1+2=3"}.isValid());
    ASSERT_FALSE(SectionPairRowValueValidator{"\\escape"}.isValid());
  }
}