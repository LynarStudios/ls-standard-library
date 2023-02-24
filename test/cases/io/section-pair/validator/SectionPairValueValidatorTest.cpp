/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
* Changed:         2023-02-23
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::io::NewLine;
using ls::std::io::SectionPairValueValidator;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairValueValidatorTest : public Test
  {
    protected:

      SectionPairValueValidatorTest() = default;
      ~SectionPairValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairValueValidatorTest_ValidArgumentTest : public TestWithParam<string>
  {
    protected:

      SectionPairValueValidatorTest_ValidArgumentTest() = default;
      ~SectionPairValueValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairValueValidatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    protected:

      SectionPairValueValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairValueValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairValueValidator", SectionPairValueValidator{"empty"}.getClassName().c_str());
  }

  TEST_F(SectionPairValueValidatorTest, getValidationRegex)
  {
    string expected = R"([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32})";
    string actual = SectionPairValueValidator::getValidationRegex();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SectionPairValueValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairValueValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairValueValidatorTest_ValidArgumentTest, Values("blue is my favourite color!", "Age", "Tom", "\"Tom\"", "Hello!" + NewLine::getUnixNewLine(), "Hello!" + NewLine::getWindowsNewLine()));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairValueValidatorTest_InvalidArgumentTest, Values("1+2=3", "\\escape"));
}
