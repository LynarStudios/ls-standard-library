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
  class SectionPairRowArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      SectionPairRowArgumentEvaluatorTest() = default;
      ~SectionPairRowArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairRowArgumentEvaluatorTest_InvalidArgumentTest : public ::testing::TestWithParam<string>
  {
    protected:

      SectionPairRowArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairRowArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairRowArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairRowArgumentEvaluator> evaluator = make_shared<SectionPairRowArgumentEvaluator>("empty");
    ASSERT_STREQ("SectionPairRowArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairRowArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairRowArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string actual = _exception.what();
            ::std::string expected = "IllegalArgumentException thrown - \"" + GetParam() + "\" is not a valid section pair row!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairRowArgumentEvaluatorTest_InvalidArgumentTest, ::testing::Values("heroes:\n  phil", "shapes:\r\n  triangle\r\nsquare"));
}
