/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairMessageFormatter;
using ls::std::io::SectionPairRowSingleValueArgumentEvaluator;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairRowSingleValueArgumentEvaluatorTest : public Test
  {
    public:

      SectionPairRowSingleValueArgumentEvaluatorTest() = default;
      ~SectionPairRowSingleValueArgumentEvaluatorTest() override = default;
  };

  class SectionPairRowSingleValueArgumentEvaluatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    public:

      SectionPairRowSingleValueArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowSingleValueArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowSingleValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairRowSingleValueArgumentEvaluator> evaluator = make_shared<SectionPairRowSingleValueArgumentEvaluator>("color=blue");
    ASSERT_STREQ("SectionPairRowSingleValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairRowSingleValueArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValueArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid section pair single value row!";

            ASSERT_STREQ(SectionPairMessageFormatter::getFormattedMessage(expected).c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowSingleValueArgumentEvaluatorTest_InvalidArgumentTest, Values("favourite-color", "a value\n"));
}
