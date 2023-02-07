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
  class IllegalArithmeticOperationExceptionTest : public ::testing::Test
  {
    protected:

      IllegalArithmeticOperationExceptionTest() = default;
      ~IllegalArithmeticOperationExceptionTest() override = default;

      void SetUp() override
      {}

      void TearDown() override
      {}
  };

  TEST_F(IllegalArithmeticOperationExceptionTest, constructor)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArithmeticOperationException{};
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("IllegalArithmeticOperationException thrown - arithmetic operation is not allowed!", message.c_str());
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(IllegalArithmeticOperationExceptionTest, constructor_dedicated_message)
  {
    EXPECT_THROW(
        {
          try
          {
            throw IllegalArithmeticOperationException{"division by zero"};
          }
          catch (const IllegalArithmeticOperationException &_exception)
          {
            ::std::string message = _exception.what();
            EXPECT_STREQ("IllegalArithmeticOperationException thrown - division by zero", message.c_str());
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }
}
