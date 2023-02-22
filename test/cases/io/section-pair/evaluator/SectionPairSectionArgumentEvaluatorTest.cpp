/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
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

namespace
{
  class SectionPairSectionArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairSectionArgumentEvaluatorTest() = default;
      ~SectionPairSectionArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairSectionArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairSectionArgumentEvaluator> evaluator = make_shared<SectionPairSectionArgumentEvaluator>("=33");
    ASSERT_STREQ("SectionPairSectionArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairSectionArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid section!";

            ASSERT_STREQ(SectionPairMessageFormatter::getFormattedMessage(expected).c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest, ::testing::Values("\n[general]\n\n", "\n[section]\n\ncolors:"));
}
