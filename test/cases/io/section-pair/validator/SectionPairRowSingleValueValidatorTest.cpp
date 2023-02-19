/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-19
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;

namespace
{
  class SectionPairRowSingleValueValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowSingleValueValidatorTest() = default;
      ~SectionPairRowSingleValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowSingleValueValidatorIsValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowSingleValueValidatorIsValidTest() = default;
      ~SectionPairRowSingleValueValidatorIsValidTest() override = default;
  };

  class SectionPairRowSingleValueValidatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowSingleValueValidatorNotValidTest() = default;
      ~SectionPairRowSingleValueValidatorNotValidTest() override = default;
  };

  TEST_F(SectionPairRowSingleValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowSingleValueValidator", SectionPairRowSingleValueValidator{"tmp-key"}.getClassName().c_str());
  }

  TEST_P(SectionPairRowSingleValueValidatorIsValidTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowSingleValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairRowSingleValueValidatorNotValidTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowSingleValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairRowSingleValueValidatorTest, SectionPairRowSingleValueValidatorIsValidTest, ::testing::Values("favourite-color=blue" + NewLine::getUnixNewLine(), "hair-color=red" + NewLine::getWindowsNewLine(), "height=167"));
  INSTANTIATE_TEST_SUITE_P(SectionPairRowSingleValueValidatorTest, SectionPairRowSingleValueValidatorNotValidTest, ::testing::Values("color blue", "a value\n"));
}
