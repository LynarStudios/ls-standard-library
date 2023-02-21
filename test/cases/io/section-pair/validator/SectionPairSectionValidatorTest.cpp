/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-02-21
*
* */

#include <gtest/gtest.h>
#include <ls-std-io-test.hpp>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using namespace ls::std::core;
using namespace ls::std::io;
using namespace ::std;
using namespace test::io;

namespace
{
  class SectionPairSectionValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairSectionValidatorTest() = default;
      ~SectionPairSectionValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairSectionValidatorTest_ValidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairSectionValidatorTest_ValidArgumentTest() = default;
      ~SectionPairSectionValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairSectionValidatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairSectionValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairSectionValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairSectionValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairSectionValidator", SectionPairSectionValidator{"empty"}.getClassName().c_str());
  }

  TEST_F(SectionPairSectionValidatorTest, getValidationRegex)
  {
    string expected =
        R"(((\n)|(\r\n))\[{1}([a-z]([a-z0-9-]){1,31})\]{1}(((\n)|(\r\n)){2})(((([a-z]([a-z0-9-]){1,31})={1}([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}){1}($|\n{1}|\r{1}\n{1}))|(((((([a-z]([a-z0-9-]){1,31}):{1})((\n{1})|(\r{1}\n{1})))( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))){1}(( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))*)))){1})(((([a-z]([a-z0-9-]){1,31})={1}([a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}){1}($|\n{1}|\r{1}\n{1}))|(((((([a-z]([a-z0-9-]){1,31}):{1})((\n{1})|(\r{1}\n{1})))( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))){1}(( {2}[a-zA-Z0-9\-_#!?\[\]\{\}\(\)\$€§<>+:;., \*\/"]{1,32}((\n{1})|(\r{1}\n{1})))*))))*))";
    ASSERT_STREQ(expected.c_str(), SectionPairSectionValidator::getValidationRegex().c_str());
  }

  TEST_P(SectionPairSectionValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairSectionValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairSectionValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairSectionValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairSectionValidatorTest_ValidArgumentTest, ::testing::Values(SectionPairSectionProvider::createSerializedSectionWithTomExample(NewLine::getUnixNewLine()), SectionPairSectionProvider::createSerializedSectionWithTomExample(NewLine::getWindowsNewLine())));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairSectionValidatorTest_InvalidArgumentTest, ::testing::Values("[general]\nage=22"));
}
