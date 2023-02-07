/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-07
 *
 * */

#include <gtest/gtest.h>
#include <ls-std/ls-std-core.hpp>
#include <string>

using namespace ls::std::core;

namespace
{
  class NullPointerExceptionTest : public ::testing::Test
  {
    protected:

      NullPointerExceptionTest() = default;
      ~NullPointerExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(NullPointerExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw NullPointerException{};
          }
          catch (const NullPointerException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("NullPointerException thrown - reference is null!", message.c_str());
            throw;
          }
        },
        NullPointerException);
  }

  TEST_F(NullPointerExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw NullPointerException{"_value is null"};
          }
          catch (const NullPointerException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("NullPointerException thrown - _value is null", message.c_str());
            throw;
          }
        },
        NullPointerException);
  }
}
