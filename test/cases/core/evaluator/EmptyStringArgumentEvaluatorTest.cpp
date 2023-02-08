/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-08
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;
using namespace ::std;

namespace
{
  class EmptyStringArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      EmptyStringArgumentEvaluatorTest() = default;
      ~EmptyStringArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(EmptyStringArgumentEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            EmptyStringArgumentEvaluator{""}.evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - passed argument is empty!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(EmptyStringArgumentEvaluatorTest, evaluate_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            EmptyStringArgumentEvaluator("", "this id is empty!").evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - this id is empty!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
