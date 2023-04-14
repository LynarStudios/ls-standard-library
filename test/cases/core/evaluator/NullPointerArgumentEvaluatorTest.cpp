/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-04-07
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <memory>
#include <string>

using ls::std::core::IllegalArgumentException;
using ls::std::core::NullPointerArgumentEvaluator;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class NullPointerArgumentEvaluatorTest : public Test
  {
    public:

      NullPointerArgumentEvaluatorTest() = default;
      ~NullPointerArgumentEvaluatorTest() override = default;
  };

  TEST_F(NullPointerArgumentEvaluatorTest, evaluate_raw_pointer)
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

  TEST_F(NullPointerArgumentEvaluatorTest, evaluate_raw_pointer_with_dedicated_message)
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

  TEST_F(NullPointerArgumentEvaluatorTest, evaluate)
  {
    shared_ptr<void> value{};

    EXPECT_THROW(
        {
          try
          {
            NullPointerArgumentEvaluator{value}.evaluate();
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
    shared_ptr<void> value{};

    EXPECT_THROW(
        {
          try
          {
            NullPointerArgumentEvaluator(value, "this reference is null!").evaluate();
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
