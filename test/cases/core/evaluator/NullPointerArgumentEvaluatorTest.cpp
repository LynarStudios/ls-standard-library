/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-02-22
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::core::NullPointerArgumentEvaluator;
using std::string;
using testing::Test;

namespace
{
  class NullPointerArgumentEvaluatorTest : public Test
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - passed argument is null!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - this reference is null!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
