/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
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
  class SectionPairRowListValueValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowListValueValidatorTest() = default;
      ~SectionPairRowListValueValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowListValueValidatorTest_ValidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowListValueValidatorTest_ValidArgumentTest() = default;
      ~SectionPairRowListValueValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairRowListValueValidatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowListValueValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowListValueValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowListValueValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairRowListValueValidator", SectionPairRowListValueValidator{"tmp-key"}.getClassName().c_str());
  }

  TEST_F(SectionPairRowListValueValidatorTest, getValidationRegex)
  {
    string expected = R"(((((([a-z]([a-z0-9-]){1,15}):{1})\r{1}\n{1})( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\r{1}\n{1})){1}(( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\r{1}\n{1})*))|((((([a-z]([a-z0-9-]){1,15}):{1})\n{1})( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\n{1})){1}(( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}\n{1})*)))";
    string actual = SectionPairRowListValueValidator::getValidationRegex();

    ASSERT_STREQ(expected.c_str(), actual.c_str());
  }

  TEST_P(SectionPairRowListValueValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairRowListValueValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairRowListValueValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairRowListValueValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairRowListValueValidatorTest_ValidArgumentTest, ::testing::Values("colors:\n  blue\n  red\n", "colors:\r\n  blue\r\n  green\r\n  yellow\r\n"));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowListValueValidatorTest_InvalidArgumentTest, ::testing::Values("colors:\nblue", "colors:\r\n hello!"));
}
