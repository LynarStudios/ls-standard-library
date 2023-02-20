/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-20
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
  class SectionPairRowValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowValidatorTest() = default;
      ~SectionPairRowValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowValidatorTest_ValidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowValidatorTest_ValidArgumentTest() = default;
      ~SectionPairRowValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairRowValidatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowValidator", SectionPairRowValidator{"empty"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowValidatorTest, getValidationRegex)
  {
    ::std::string expected = R"((([a-z]([a-z0-9-]){1,15})={1}([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}){1}($|\n{1}|\r{1}\n{1}))|(((((([a-z]([a-z0-9-]){1,15}):{1})((\n{1})|(\r{1}\n{1})))( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))){1}(( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))*))))";
    ASSERT_STREQ(expected.c_str(), SectionPairRowValidator::getValidationRegex().c_str());
  }

  TEST_P(SectionPairRowValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairRowValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairRowValidatorTest_ValidArgumentTest, ::testing::Values("favourite-color=blue\n", "color=red\r\n", "colors:\n  red\n  blue\n", "colors:\r\n  red\r\n  yellow\r\n", "graphics-card=GTX 720\n"));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowValidatorTest_InvalidArgumentTest, ::testing::Values("color blue", "a row\nand so on"));
}
