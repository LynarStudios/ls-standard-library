/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-10
* Changed:         2023-02-19
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
  class SectionPairValueArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairValueArgumentEvaluatorTest() = default;
      ~SectionPairValueArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairValueArgumentEvaluatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairValueArgumentEvaluatorNotValidTest() = default;
      ~SectionPairValueArgumentEvaluatorNotValidTest() override = default;
  };

  TEST_F(SectionPairValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairValueArgumentEvaluator> evaluator = make_shared<SectionPairValueArgumentEvaluator>("=33");
    ASSERT_STREQ("SectionPairValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairValueArgumentEvaluatorNotValidTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairValueArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = "IllegalArgumentException thrown - \"" + GetParam() + "\" is not a valid value!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairValueArgumentEvaluatorTest, SectionPairValueArgumentEvaluatorNotValidTest, ::testing::Values("=33", "\\empty"));
}
