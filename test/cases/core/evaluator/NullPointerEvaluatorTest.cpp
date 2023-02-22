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

using namespace ls::std::core;
using namespace ::std;
using namespace ::testing;

namespace
{
  class NullPointerArgumentTest : public Test
  {
    protected:

      NullPointerArgumentTest() = default;
      ~NullPointerArgumentTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(NullPointerArgumentTest, evaluate)
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

  TEST_F(NullPointerArgumentTest, evaluate_dedicated_message)
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
}
