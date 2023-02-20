/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-20
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

  class SectionPairRowListValueArgumentEvaluatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowListValueArgumentEvaluatorNotValidTest() = default;
      ~SectionPairRowListValueArgumentEvaluatorNotValidTest() override = default;
  };

  TEST_F(SectionPairRowListValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairRowListValueArgumentEvaluator> evaluator = make_shared<SectionPairRowListValueArgumentEvaluator>("color=blue");
    ASSERT_STREQ("SectionPairRowListValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairRowListValueArgumentEvaluatorNotValidTest, evaluate)
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
            ::std::string expected = "IllegalArgumentException thrown - \"" + GetParam() + "\" is not a valid section pair list value row!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairRowListValueArgumentEvaluatorTest, SectionPairRowListValueArgumentEvaluatorNotValidTest, ::testing::Values("colors:", "colors:\n red", "colors:\r\n  red"));
}
