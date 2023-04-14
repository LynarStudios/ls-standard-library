/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <ls-std/ls-std-io.hpp>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::io::SectionPairValueArgumentEvaluator;
using std::make_shared;
using std::shared_ptr;
using std::string;
using testing::Test;
using testing::TestWithParam;
using testing::Values;

namespace
{
  class SectionPairValueArgumentEvaluatorTest : public Test
  {
    public:

      SectionPairValueArgumentEvaluatorTest() = default;
      ~SectionPairValueArgumentEvaluatorTest() override = default;
  };

  class SectionPairValueArgumentEvaluatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    public:

      SectionPairValueArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairValueArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairValueArgumentEvaluator> evaluator = make_shared<SectionPairValueArgumentEvaluator>("=33");
    ASSERT_STREQ("SectionPairValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairValueArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairValueArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid value!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairValueArgumentEvaluatorTest_InvalidArgumentTest, Values("=33", "\\empty"));
}
