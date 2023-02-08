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
  class NullPointerArgumentTest : public ::testing::Test
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
            string message = _exception.what();
            ASSERT_STREQ("NullPointerException thrown - reference in use is null!", message.c_str());
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
            string message = _exception.what();
            ASSERT_STREQ("NullPointerException thrown - this reference is not set and causes this exception!", message.c_str());
            throw;
          }
        },
        NullPointerException);
  }
}
