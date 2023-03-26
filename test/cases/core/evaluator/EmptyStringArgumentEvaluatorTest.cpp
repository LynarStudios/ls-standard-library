/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-03-25
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using ls::std::core::EmptyStringArgumentEvaluator;
using ls::std::core::IllegalArgumentException;
using std::string;
using testing::Test;

namespace
{
  class EmptyStringArgumentEvaluatorTest : public Test
  {
    public:

      EmptyStringArgumentEvaluatorTest() = default;
      ~EmptyStringArgumentEvaluatorTest() override = default;
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - passed argument is empty!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
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
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - this id is empty!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArgumentException);
  }
}
