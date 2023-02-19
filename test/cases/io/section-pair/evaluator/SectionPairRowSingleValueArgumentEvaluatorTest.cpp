/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-19
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
  class SectionPairRowSingleValueArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowSingleValueArgumentEvaluatorTest() = default;
      ~SectionPairRowSingleValueArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowSingleValueArgumentEvaluatorNotValidTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowSingleValueArgumentEvaluatorNotValidTest() = default;
      ~SectionPairRowSingleValueArgumentEvaluatorNotValidTest() override = default;
  };

  TEST_F(SectionPairRowSingleValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairRowSingleValueArgumentEvaluator> evaluator = make_shared<SectionPairRowSingleValueArgumentEvaluator>("color=blue");
    ASSERT_STREQ("SectionPairRowSingleValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairRowSingleValueArgumentEvaluatorNotValidTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowSingleValueArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = "IllegalArgumentException thrown - \"" + GetParam() + "\" is not a valid section pair single value row!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(SectionPairRowSingleValueArgumentEvaluatorTest, SectionPairRowSingleValueArgumentEvaluatorNotValidTest, ::testing::Values("favourite-color", "a value\n"));
}
