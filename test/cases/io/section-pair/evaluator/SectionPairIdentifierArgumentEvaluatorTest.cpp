/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-09
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
using namespace ::testing;

namespace
{
  class SectionPairIdentifierArgumentEvaluatorTest : public Test
  {
    protected:

      SectionPairIdentifierArgumentEvaluatorTest() = default;
      ~SectionPairIdentifierArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  class SectionPairIdentifierArgumentEvaluatorTest_InvalidArgumentTest : public TestWithParam<string>
  {
    protected:

      SectionPairIdentifierArgumentEvaluatorTest_InvalidArgumentTest() = default;
      ~SectionPairIdentifierArgumentEvaluatorTest_InvalidArgumentTest() override = default;
  };

  TEST_F(SectionPairIdentifierArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairIdentifierArgumentEvaluator> evaluator = make_shared<SectionPairIdentifierArgumentEvaluator>("_id");
    ASSERT_STREQ("SectionPairIdentifierArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_P(SectionPairIdentifierArgumentEvaluatorTest_InvalidArgumentTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairIdentifierArgumentEvaluator(GetParam()).evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - \"" + GetParam() + "\" is not a valid identifier!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  INSTANTIATE_TEST_SUITE_P(InvalidArgumentTest, SectionPairIdentifierArgumentEvaluatorTest_InvalidArgumentTest, Values("_color", "Color", "another_color"));
}
