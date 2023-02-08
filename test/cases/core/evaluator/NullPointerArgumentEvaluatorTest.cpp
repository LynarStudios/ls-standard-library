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
  class NullPointerArgumentEvaluatorTest : public ::testing::Test
  {
    protected:

      NullPointerArgumentEvaluatorTest() = default;
      ~NullPointerArgumentEvaluatorTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(NullPointerArgumentEvaluatorTest, evaluate)
  {
    EXPECT_THROW(
        {
          try
          {
            NullPointerArgumentEvaluator{nullptr}.evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - passed argument is null!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }

  TEST_F(NullPointerArgumentEvaluatorTest, evaluate_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            NullPointerArgumentEvaluator(nullptr, "this reference is null!").evaluate();
          }
          catch (const IllegalArgumentException &_exception)
          {
            string message = _exception.what();
            ASSERT_STREQ("IllegalArgumentException thrown - this reference is null!", message.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
