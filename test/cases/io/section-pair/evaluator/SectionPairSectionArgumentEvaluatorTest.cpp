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
using ls::std::io::SectionPairSectionArgumentEvaluator;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairSectionArgumentEvaluatorTest : public Test
  {
    public:

      SectionPairSectionArgumentEvaluatorTest() = default;
      ~SectionPairSectionArgumentEvaluatorTest() override = default;
  };

  class SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    public:

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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid section!";

            ASSERT_STREQ(SectionPairMessageFormatter::getFormattedMessage(expected).c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairSectionArgumentEvaluatorTest_InvalidArgumentTest, Values("\n[general]\n\n", "\n[section]\n\ncolors:"));
}
