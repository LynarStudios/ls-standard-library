/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairRowListValueArgumentEvaluator;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairRowListValueArgumentEvaluatorTest : public Test
  {
    public:

      SectionPairRowListValueArgumentEvaluatorTest() = default;
      ~SectionPairRowListValueArgumentEvaluatorTest() override = default;
  };

  class SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    public:

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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid section pair list value row!";

            ASSERT_STREQ(SectionPairMessageFormatter::getFormattedMessage(expected).c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowListValueArgumentEvaluatorTest_InvalidArgumentTest, Values("colors:", "colors:\n red", "colors:\r\n  red"));
}
