/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-21
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
  class SectionPairDocumentValidatorTest : public ::testing::Test
  {
    protected:

      SectionPairDocumentValidatorTest() = default;
      ~SectionPairDocumentValidatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairDocumentValidatorTest_LineBreakTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairDocumentValidatorTest_LineBreakTest() = default;
      ~SectionPairDocumentValidatorTest_LineBreakTest() override = default;
  };

  class SectionPairDocumentValidatorTest_ValidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairDocumentValidatorTest_ValidArgumentTest() = default;
      ~SectionPairDocumentValidatorTest_ValidArgumentTest() override = default;
  };

  class SectionPairDocumentValidatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairDocumentValidatorTest_InvalidArgumentTest() = default;
      ~SectionPairDocumentValidatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairDocumentValidatorTest, getClassName)
  {
    ASSERT_STREQ("SectionPairDocumentValidator", SectionPairDocumentValidator{"tmp-key"}.getClassName().c_str());
  }

  TEST_P(SectionPairDocumentValidatorTest_LineBreakTest, isValid)
  {
    ASSERT_TRUE(SectionPairDocumentValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairDocumentValidatorTest_ValidArgumentTest, isValid)
  {
    ASSERT_TRUE(SectionPairDocumentValidator{GetParam()}.isValid());
  }

  TEST_P(SectionPairDocumentValidatorTest_InvalidArgumentTest, isValid_not_valid)
  {
    ASSERT_FALSE(SectionPairDocumentValidator{GetParam()}.isValid());
  }

  INSTANTIATE_TEST_SUITE_P(LineBreakTest, SectionPairDocumentValidatorTest_LineBreakTest, ::testing::Values(SectionPairDocumentProvider::createSerializedDocument(NewLine::getWindowsNewLine()), SectionPairDocumentProvider::createSerializedDocument(NewLine::getUnixNewLine())));
  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairDocumentValidatorTest_InvalidArgumentTest, ::testing::Values("\n[general]\n\ncolors:\nblue\n"));
  INSTANTIATE_TEST_SUITE_P(ValidArgumentTest, SectionPairDocumentValidatorTest_ValidArgumentTest, ::testing::Values(SectionPairDocumentProvider::createSerializedDocumentComputerExample(NewLine::get())));
}
