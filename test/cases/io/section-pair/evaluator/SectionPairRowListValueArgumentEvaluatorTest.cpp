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
  class SectionPairRowListValueArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowListValueArgumentEvaluatorTest() = default;
      ~SectionPairRowListValueArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowListValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairRowListValueArgumentEvaluator> evaluator = make_shared<SectionPairRowListValueArgumentEvaluator>("color=blue");
    ASSERT_STREQ("SectionPairRowListValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowListValueArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid section pair list value row!";

            ASSERT_STREQ(SectionPairMessageFormatter::getFormattedMessage(expected).c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest, ::testing::Values("colors:", "colors:\n red", "colors:\r\n  red"));
}
