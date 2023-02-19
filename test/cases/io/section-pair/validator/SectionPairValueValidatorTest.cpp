/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
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
  class SectionPairValueValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairValueValidatorTest() = default;
      ~SectionPairValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairValueValidatorValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairValueValidatorValidTest() = default;
      ~SectionPairValueValidatorValidTest() override = default;
  };

  class SectionPairValueValidatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairValueValidatorNotValidTest() = default;
      ~SectionPairValueValidatorNotValidTest() override = default;
  };

  TEST_F(SectionPairValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairValueValidator", SectionPairValueValidator{"any value"}.getClassName().c_str());
  }

  TEST_F(SectionPairValueValidatorTest, getValidationRegex)
  {
    string expected = R"(([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32})|([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\n{1})|([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\r{1}\n{1}))";
    string actual = SectionPairValueValidator::getValidationRegex();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SectionPairValueValidatorValidTest, isValid)
  {
    ASSERT_TRUE(SectionPairValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairValueValidatorNotValidTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairValueValidatorTest, SectionPairValueValidatorValidTest, ::testing::Values("blue is my favourite color!", "Age", "Tom", "\"Tom\"", "Hello!" + NewLine::getUnixNewLine(), "Hello!" + NewLine::getWindowsNewLine()));
  INSTANTIATE_TEST_SUITE_P(SectionPairValueValidatorTest, SectionPairValueValidatorNotValidTest, ::testing::Values("1+2=3", "\\escape"));
}