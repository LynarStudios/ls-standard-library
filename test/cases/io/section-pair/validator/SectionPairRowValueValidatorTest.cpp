/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-18
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

  class SectionPairRowValueValidatorValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowValueValidatorValidTest() = default;
      ~SectionPairRowValueValidatorValidTest() override = default;
  };

  class SectionPairRowValueValidatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowValueValidatorNotValidTest() = default;
      ~SectionPairRowValueValidatorNotValidTest() override = default;
  };

  TEST_F(SectionPairRowValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowValueValidator", SectionPairRowValueValidator{"any value"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowValueValidatorTest, getValidationRegex)
  {
    string expected = R"(([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32})|([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\n{1})|([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\r{1}\n{1}))";
    string actual = SectionPairRowValueValidator::getValidationRegex();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SectionPairRowValueValidatorValidTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairRowValueValidatorNotValidTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairRowValueValidatorTest, SectionPairRowValueValidatorValidTest, ::testing::Values("blue is my favourite color!", "Age", "Tom", "\"Tom\"", "Hello!" + NewLine::getUnixNewLine(), "Hello!" + NewLine::getWindowsNewLine()));
  INSTANTIATE_TEST_SUITE_P(SectionPairRowValueValidatorTest, SectionPairRowValueValidatorNotValidTest, ::testing::Values("1+2=3", "\\escape"));
}