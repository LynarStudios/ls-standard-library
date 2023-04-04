/*
* Author:          Patrick-Christopher Mattulat
* Company:         Lynar Studios
* E-Mail:          webmaster@lynarstudios.com
* Created:         2023-02-08
* Changed:         2023-04-04
*
* */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <memory>
#include <string>

using ls::std::core::NullPointerEvaluator;
using ls::std::core::NullPointerException;
using std::shared_ptr;
using std::string;
using testing::Test;

namespace
{
  class NullPointerArgumentTest : public Test
  {
    public:

      NullPointerArgumentTest() = default;
      ~NullPointerArgumentTest() override = default;
  };

  TEST_F(NullPointerArgumentTest, evaluate_raw_pointer)
  {
    EXPECT_THROW(
        {
          try
          {
            NullPointerEvaluator{nullptr}.evaluate();
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - reference in use is null!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerArgumentTest, evaluate_raw_pointer_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            NullPointerEvaluator(nullptr, "this reference is not set and causes this exception!").evaluate();
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - this reference is not set and causes this exception!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerArgumentTest, evaluate)
  {
    shared_ptr<void> value{};

    EXPECT_THROW(
        {
          try
          {
            NullPointerEvaluator{value}.evaluate();
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - reference in use is null!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerArgumentTest, evaluate_dedicated_message)
  {
    shared_ptr<void> value{};

    EXPECT_THROW(
        {
          try
          {
            NullPointerEvaluator(value, "this reference is not set and causes this exception!").evaluate();
          }
          catch (const NullPointerException &_exception)
          {
            string actual = _exception.what();
            string expected = _exception.getName() + " thrown - this reference is not set and causes this exception!";

            ASSERT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        NullPointerException);
  }
}
