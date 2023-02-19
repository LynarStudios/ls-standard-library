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

  TEST_F(SectionPairValueArgumentEvaluatorTest, getClassName)
  {
    shared_ptr<SectionPairValueArgumentEvaluator> evaluator = make_shared<SectionPairValueArgumentEvaluator>("=33", "section pair value contains invalid characters!");
    ASSERT_STREQ("SectionPairValueArgumentEvaluator", evaluator->getClassName().c_str());
  }

  TEST_F(SectionPairValueArgumentEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            SectionPairValueArgumentEvaluator("=33", "section pair value contains invalid characters!").evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            ::std::string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - section pair value contains invalid characters!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
