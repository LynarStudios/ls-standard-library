/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace ::testing;

namespace
{
  class SectionPairRowSingleValueValidatorTest : public Test
  {
    protected:

      SectionPairRowSingleValueValidatorTest() = default;
      ~SectionPairRowSingleValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowSingleValueValidatorTest_ValidArgumentTest : public TestWithParam<string>
  {
    protected:

      SectionPairRowSingleValueValidatorTest_ValidArgumentTest() = default;
      ~SectionPairRowSingleValueValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairRowSingleValueValidatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    protected:

      SectionPairRowSingleValueValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowSingleValueValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowSingleValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowSingleValueValidator", SectionPairRowSingleValueValidator{"empty"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowSingleValueValidatorTest, getValidationRegex)
  {
    string expected = R"(([a-z]([a-z0-9-]){1,31})={1}([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}){1}($|\n{1}|\r{1}\n{1}))";
    ASSERT_STREQ(expected.c_str(), SectionPairRowSingleValueValidator::getValidationRegex().c_str());
  }

  TEST_P(SectionPairRowSingleValueValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowSingleValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairRowSingleValueValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowSingleValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairRowSingleValueValidatorTest_ValidArgumentTest, Values("favourite-color=blue" + NewLine::getUnixNewLine(), "hair-color=red" + NewLine::getWindowsNewLine(), "height=167"));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowSingleValueValidatorTest_InvalidArgumentTest, Values("color blue", "a value\n"));
}
