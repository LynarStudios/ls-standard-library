/*
 * Author:          Patrick-Christopher Mattulat
 * Company:         Lynar Studios
 * E-Mail:          webmaster@lynarstudios.com
 * Created:         2021-05-01
 * Changed:         2023-02-22
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
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - arithmetic operation is not allowed!";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
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
            ::std::string actual = _exception.what();
            ::std::string expected = _exception.getName() + " thrown - division by zero";

            EXPECT_STREQ(expected.c_str(), actual.c_str());
            throw;
          }
        },
        IllegalArithmeticOperationException);
  }

  TEST_F(IllegalArithmeticOperationExceptionTest, getName)
  {
    ASSERT_STREQ("IllegalArithmeticOperationException", IllegalArithmeticOperationException{}.getName().c_str());
  }
}
